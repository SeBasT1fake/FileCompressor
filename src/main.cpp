#include "huffman.h"
#include "encryption.h"
#include <iostream>
#include <stdexcept>

#define VERSION "1.0.0"

void mostrarAyuda() {
    std::cout << "Uso: ./programa [opción] <archivo_entrada> <archivo_salida>\n\n"
              << "Opciones:\n"
              << "  -h, --help\t\t\tMuestra este mensaje de ayuda\n"
              << "  -v, --version\t\t\tMuestra la versión del programa\n"
              << "  -c, --compress\t\t\tComprime el archivo especificado\n"
              << "  -x, --decompress\t\tDescomprime el archivo especificado\n"
              << "  -e, --encrypt\t\t\tEncripta el archivo especificado\n"
              << "  -d, --decrypt\t\t\tDesencripta el archivo especificado\n\n"
              << "Ejemplos:\n"
              << "  ./programa -c archivo.txt archivo.compressed\n"
              << "  ./programa -x archivo.compressed archivo_recuperado.txt\n"
              << "  ./programa -e documento.txt documento.encrypted\n"
              << "  ./programa -d documento.encrypted documento_recuperado.txt\n";
}

void mostrarVersion() {
    std::cout << "Compresor y Encriptador de Archivos v" << VERSION << "\n"
              << "Desarrollado como proyecto académico\n"
              << "Implementa compresión Huffman y encriptación XOR básica\n";
}

int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            mostrarAyuda();
            return 1;
        }

        std::string opcion = argv[1];

        if (opcion == "-h" || opcion == "--help") {
            mostrarAyuda();
            return 0;
        }

        if (opcion == "-v" || opcion == "--version") {
            mostrarVersion();
            return 0;
        }

        if (argc != 4) {
            std::cerr << "Error: Número incorrecto de argumentos\n";
            mostrarAyuda();
            return 1;
        }

        const char* archivoEntrada = argv[2];
        const char* archivoSalida = argv[3];

        HuffmanCompression huffman;
        Encryption encryption;

        if (opcion == "-c" || opcion == "--compress") {
            std::cout << "Comprimiendo archivo...\n";
            huffman.compress(archivoEntrada, archivoSalida);
            std::cout << "Compresión completada\n";
        }
        else if (opcion == "-x" || opcion == "--decompress") {
            std::cout << "Descomprimiendo archivo...\n";
            huffman.decompress(archivoEntrada, archivoSalida);
            std::cout << "Descompresión completada\n";
        }
        else if (opcion == "-e" || opcion == "--encrypt") {
            std::cout << "Encriptando archivo...\n";
            encryption.encrypt(archivoEntrada, archivoSalida);
            std::cout << "Encriptación completada\n";
        }
        else if (opcion == "-d" || opcion == "--decrypt") {
            std::cout << "Desencriptando archivo...\n";
            encryption.decrypt(archivoEntrada, archivoSalida);
            std::cout << "Desencriptación completada\n";
        }
        else {
            std::cerr << "Error: Opción no válida\n";
            mostrarAyuda();
            return 1;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}