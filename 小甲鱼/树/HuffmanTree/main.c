//
// Created by gitzzg on 2017/2/13.
//
#include "huffman.h"

int main()
{
    htTree *codeTree = buildTree("I love FishC.com.");

    hlTable *codeTable = buildTable(codeTree);

    encode(codeTable, "I love FishC.com.");

    decode(codeTree, "0100111001101011");

    return 0;
}
