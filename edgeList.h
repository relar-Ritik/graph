//
// Created by Ritik Anand Agrawal on 25-05-2020.
//

#ifndef GRAPHS_EDGELIST_H
#define GRAPHS_EDGELIST_H
#include "linkedlist.h"
typedef struct ed_tag{
    int vertex;
    int cost;
    struct ed_tag *next;
}edge;

edge *createEdge(int vertex, int cost);
edge *insertEdge(edge *head,int vertex, int cost);
edge *deleteEdge(edge *head, int vertex);
edge *findInEdge(edge *head, int vertex);



#endif //GRAPHS_EDGELIST_H
