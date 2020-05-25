//
// Created by ritik on 25/05/20.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H
#define MAXSIZE 200
#include "linkedlist.h"
#include "que.h"


typedef struct v_tag{
    int active;
    node *edgeList;
}vertex;

typedef struct graph_type{
    int size;
    vertex vertices[MAXSIZE];
}graph;

void init_graph(graph *a);
void addVertex(graph *a, int V);
void addEdge(graph *a, int V1, int V2, int is_directed);
void depthFirstTraversal(graph *a, int origin);
void dfs(graph *a, int vertex,bool isVisited[MAXSIZE]);

#endif //GRAPHS_GRAPH_H
