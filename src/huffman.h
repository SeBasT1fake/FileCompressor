#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// Nodo del árbol de Huffman
struct MinHeapNode {
    unsigned char data;
    int freq;
    MinHeapNode *left, *right;
    MinHeapNode(unsigned char data, int freq);
};

// Comparador para la cola de prioridad
struct CompareNode {
    bool operator()(MinHeapNode* l, MinHeapNode* r);
};

// Clase principal para compresión Huffman
class HuffmanCompression {
private:
    map<unsigned char, int> freq;
    map<unsigned char, string> codes;
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, CompareNode> minHeap;

    void generateCodes(MinHeapNode* root, string str);
    MinHeapNode* buildHuffmanTree();
    void writeTreeToFile(MinHeapNode* root, ofstream& outFile);
    MinHeapNode* readTreeFromFile(ifstream& inFile);
    void cleanupTree(MinHeapNode* root);

public:
    HuffmanCompression();
    ~HuffmanCompression();
    void compress(const char* inputPath, const char* outputPath);
    void decompress(const char* inputPath, const char* outputPath);
};

#endif
