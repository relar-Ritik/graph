//
// Created by ritik on 25/05/20.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H
#define MAXSIZE 200
#include "linkedlist.h"
#include "que.h"
#include "stack.h"
#include "edgeList.h"
#include <string.h>



typedef struct v_tag{
    char name[3];
    edge *edgeList;
}vertex;

typedef struct graph_type{
    int size;
    vertex vertices[MAXSIZE];
}graph;

void init_graph(graph *a);
void addVertex(graph *a, char *name);
int getVertexId(graph *a, char *name);
void addEdge(graph *a, char *V1name, char *V2name, int is_directed, int cost);
void depthFirstTraversal(graph *a);
void dfs(graph *a, int vertex,bool isVisited[]);
void breadthFirstTraversal(graph *a);
void bfs(graph *a, Que *q, bool *isVisited);
void topologicalSort(graph *a);
void topoSort(graph *a, int vertexId ,stack *m, bool isVisited[MAXSIZE]);
bool isGraphConnected(graph *a);
int minIndex(int *array, int size, bool *closeSet);
int* dijkstra(graph *a, char *originName);

#endif //GRAPHS_GRAPH_H
