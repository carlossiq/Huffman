// Classes:
// 1-Node (nó) : representa um nó da árvore
//     atributos: char data; int frequency; node* left; node* right;
//     métodos: construtor; Comparador para ordenar nós com base na frequência (necessário para a fila de prioridade).

// 2-Huffman Tree (árvore) : constrói a árvore
//     atributos: node *root; (raiz da arvore)
//     métodos: buildTree (constroi a arvore a partir de um mapa de frequencias); generateCodes (gera as codificações de cada caractere);
//     metodos auxiliares para percorrer a arvore e gerar os códigos


// 3- Huffman Coding (codificação) : codifica e decodifica textos
//     atributos: std::unordered_map<char, std::string> codes - mapa de caracteres para códigos binários.
//                HuffmanTree tree - instância da árvore de Huffman
//     métodos: encode - codifica um texto usando os códigos gerados.
//              decode - decodifica um texto codificado usando a árvore de Huffman
//     Métodos auxiliares para calcular as frequências dos caracteres e inicializar o processo de construção da árvore.

struct Node;
class HuffmanTree;
class HuffmanCoding;
//comen
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

struct Node;
class HuffmanTree;
class HuffmanCoding;
