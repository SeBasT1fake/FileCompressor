#include "encryption.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>

#define BUFFER_SIZE 4096

Encryption::Encryption() : encryptionKey{0x4B, 0x75, 0x63, 0x68, 0x69, 0x7A, 0x75, 0x6B} {}

void Encryption::encrypt(const char* inputPath, const char* outputPath) {
    int inFile = open(inputPath, O_RDONLY);
    if (inFile < 0) {
        throw std::runtime_error("No se pudo abrir el archivo de entrada");
    }

    int outFile = open(outputPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outFile < 0) {
        close(inFile);
        throw std::runtime_error("No se pudo crear el archivo de salida");
    }

    unsigned char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    int keyIndex = 0;

    while ((bytesRead = read(inFile, buffer, BUFFER_SIZE)) > 0) {
        for (ssize_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= encryptionKey[keyIndex];
            keyIndex = (keyIndex + 1) % KEY_SIZE;
        }
        write(outFile, buffer, bytesRead);
    }

    close(inFile);
    close(outFile);
}

void Encryption::decrypt(const char* inputPath, const char* outputPath) {
    encrypt(inputPath, outputPath);
}