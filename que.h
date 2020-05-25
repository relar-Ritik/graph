//
// Created by ritik on 25/05/20.
//

#ifndef GRAPHS_QUE_H
#define GRAPHS_QUE_H
#include "linkedlist.h"

typedef struct q_type{
    node *top;
    node *tail;
    int size;
}Que;

void initQue(Que *A);
void pushQue(Que *A, int data);
int popQue(Que *A);



#endif //GRAPHS_QUE_H
