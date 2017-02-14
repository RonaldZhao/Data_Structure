//
// Created by gitzzg on 2017/2/13.
//

#ifndef DS_TEST_HUFFMAN_H
#define DS_TEST_HUFFMAN_H

typedef struct _htNode
{
    char symbol;
    struct _htNode *left, *right;
}htNode;

typedef struct _htTree
{
    htNode *root;
}htTree;

typedef struct _hlNode
{
    char symbol;
    char *code;
    struct _hlNode *next;
}hlNode;

typedef struct _hlTable
{
    hlNode *first;
    hlNode *last;
}hlTable;

htTree *buildTree(char *inputString);
void encode(hlTable *table, char *stringToEncode);
void decode(htTree *tree, char *stringToDecode);
void traverseTree(htNode *treeNode, hlTable **table, int k, char code[256]);
hlTable *buildTable(htTree *huffmanTree);

#endif //DS_TEST_HUFFMAN_H
