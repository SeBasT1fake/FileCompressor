#include "huffman.h"

// Constructor del nodo
MinHeapNode::MinHeapNode(unsigned char data, int freq) {
    left = right = nullptr;
    this->data = data;
    this->freq = freq;
}

// Implementación del comparador
bool CompareNode::operator()(MinHeapNode* l, MinHeapNode* r) {
    return (l->freq > r->freq);
}

// Constructor de HuffmanCompression
HuffmanCompression::HuffmanCompression() {}

// Destructor
HuffmanCompression::~HuffmanCompression() {
    if (!minHeap.empty()) {
        cleanupTree(minHeap.top());
    }
}

// Limpieza del árbol
void HuffmanCompression::cleanupTree(MinHeapNode* root) {
    if (root) {
        cleanupTree(root->left);
        cleanupTree(root->right);
        delete root;
    }
}

// Generación de códigos Huffman
void HuffmanCompression::generateCodes(MinHeapNode* root, string str) {
    if (!root) return;
    if (!root->left && !root->right)
        codes[root->data] = str;
    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

// Construcción del árbol de Huffman
MinHeapNode* HuffmanCompression::buildHuffmanTree() {
    while (!minHeap.empty()) minHeap.pop();  // Limpiar el heap
    for (auto& pair : freq) {
        minHeap.push(new MinHeapNode(pair.first, pair.second));
    }
    while (minHeap.size() > 1) {
        MinHeapNode *left = minHeap.top(); minHeap.pop();
        MinHeapNode *right = minHeap.top(); minHeap.pop();
        MinHeapNode *top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    return minHeap.top();
}

// Escribir árbol en el archivo
void HuffmanCompression::writeTreeToFile(MinHeapNode* root, ofstream& outFile) {
    if (!root) {
        outFile.put(0);
        return;
    }
    outFile.put(1);
    if (!root->left && !root->right) {
        outFile.put(1);
        outFile.put(root->data);
    } else {
        outFile.put(0);
        writeTreeToFile(root->left, outFile);
        writeTreeToFile(root->right, outFile);
    }
}

// Leer árbol del archivo
MinHeapNode* HuffmanCompression::readTreeFromFile(ifstream& inFile) {
    char bit;
    if (!inFile.get(bit) || bit == 0) return nullptr;
    if (!inFile.get(bit)) throw runtime_error("Error al leer el árbol");
    if (bit == 1) {
        char data;
        if (!inFile.get(data)) throw runtime_error("Error al leer el árbol");
        return new MinHeapNode(data, 0);
    }
    MinHeapNode* node = new MinHeapNode('$', 0);
    node->left = readTreeFromFile(inFile);
    node->right = readTreeFromFile(inFile);
    return node;
}

// Comprimir archivo
void HuffmanCompression::compress(const char* inputPath, const char* outputPath) {
    ifstream inFile(inputPath, ios::binary);
    if (!inFile) throw runtime_error("No se pudo abrir el archivo de entrada");

    unsigned char byte;
    while (inFile.get(reinterpret_cast<char&>(byte))) {
        freq[byte]++;
    }
    inFile.clear();
    inFile.seekg(0);

    MinHeapNode* root = buildHuffmanTree();
    generateCodes(root, "");

    ofstream outFile(outputPath, ios::binary);
    if (!outFile) throw runtime_error("No se pudo crear el archivo de salida");

    writeTreeToFile(root, outFile);

    string buffer;
    while (inFile.get(reinterpret_cast<char&>(byte))) {
        buffer += codes[byte];
        while (buffer.length() >= 8) {
            unsigned char c = 0;
            for (int i = 0; i < 8; i++)
                c = (c << 1) | (buffer[i] - '0');
            outFile.put(c);
            buffer = buffer.substr(8);
        }
    }

    if (!buffer.empty()) {
        unsigned char c = 0;
        int remainingBits = buffer.length();
        for (int i = 0; i < remainingBits; i++)
            c = (c << 1) | (buffer[i] - '0');
        c <<= (8 - remainingBits);
        outFile.put(c);
        outFile.put(remainingBits);
    } else {
        outFile.put(0);
    }

    inFile.close();
    outFile.close();
}

void HuffmanCompression::decompress(const char* inputPath, const char* outputPath) {
    ifstream inFile(inputPath, ios::binary);
    if (!inFile) {
        throw runtime_error("No se pudo abrir el archivo comprimido");
    }

    ofstream outFile(outputPath, ios::binary);
    if (!outFile) {
        throw runtime_error("No se pudo crear el archivo de salida");
    }

    // Lee el árbol de Huffman
    MinHeapNode* root = readTreeFromFile(inFile);
    MinHeapNode* current = root;

    unsigned char byte;
    int remainingBits = 8;

    // Leer el archivo comprimido
    while (inFile.get(reinterpret_cast<char&>(byte))) {
        if (inFile.peek() == EOF) {
            inFile.get(reinterpret_cast<char&>(remainingBits));
            if (remainingBits == 0) break;
        }

        for (int i = 7; i >= 8 - remainingBits; i--) {
            bool bit = (byte >> i) & 1;
            current = bit ? current->right : current->left;

            if (!current->left && !current->right) {
                outFile.put(current->data);
                current = root;
            }
        }
    }

    inFile.close();
    outFile.close();
}
