//
// Created by gitzzg on 2017/2/13.
//

#ifndef DS_TEST_QUEUE_H
#define DS_TEST_QUEUE_H

#include "huffman.h"

#define TYPE htNode *

#define MAX_SZ 256

typedef struct _pQueueNode
{
    TYPE val;
    unsigned int priority;
    struct _pQueueNode *next;
}pQueueNode;

typedef struct _pQueue
{
    unsigned int size;
    pQueueNode *first;
}pQueue;

void initPQueue(pQueue **queue);
void addPQueue(pQueue **queue, TYPE val, unsigned int priority);
TYPE getPQueue(pQueue **queue);

#endif //DS_TEST_QUEUE_H
