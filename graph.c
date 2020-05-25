//
// Created by ritik on 25/05/20.
//

#include "graph.h"

void init_graph(graph *a) {
    a->size=0;
    for (int i = 0; i < MAXSIZE; ++i) {
        a->vertices[i].active= 0;
        a->vertices[i].edgeList =NULL;
    }
}

void addVertex(graph *a, int V) {
    a->size += 1;
    a->vertices[V].active = 1;
}

void addEdge(graph *a, int V1, int V2, int is_directed) {
    if(findInList(a->vertices[V1].edgeList, V2) == NULL){
        a->vertices[V1].edgeList = insertNode(a->vertices[V1].edgeList, V2);
    }
    if(is_directed  == 0){
        if(findInList(a->vertices[V2].edgeList, V1) == NULL){
            a->vertices[V2].edgeList = insertNode(a->vertices[V2].edgeList, V1);
        }
    }
}

void depthFirstTraversal(graph *a, int origin) {
    bool isVisited[MAXSIZE]={0};
    dfs(a,origin ,isVisited);
}

void dfs(graph *a, int vertex, bool isVisited[MAXSIZE]) {
    printf("%d ", vertex);
    isVisited[vertex] = TRUE;
    node *alist = a->vertices[vertex].edgeList;
    while (alist !=NULL){
        if(isVisited[alist->data] == FALSE){
            dfs(a, alist->data, isVisited);
        }
        alist = alist->next;
    }
}


