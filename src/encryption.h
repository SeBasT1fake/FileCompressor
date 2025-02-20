#ifndef ENCRYPTION_H
#define ENCRYPTION_H

class Encryption {
private:
    static const int KEY_SIZE = 8;
    const unsigned char encryptionKey[KEY_SIZE];

public:
    Encryption();
    void encrypt(const char* inputPath, const char* outputPath);
    void decrypt(const char* inputPath, const char* outputPath);
};

#endif