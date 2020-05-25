//
// Created by Ritik Anand Agrawal on 25-05-2020.
//

#ifndef GRAPHS_STACK_H
#define GRAPHS_STACK_H

#include "linkedlist.h"

typedef struct stack_type{
    int size;
    node *top;
}stack;

void initStack(stack *a);
void pushStack(stack *a, int data);
int popStack(stack *a);

#endif //GRAPHS_STACK_H
