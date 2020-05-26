//
// Created by ritik on 25/05/20.
//

#include "graph.h"
#define INF 0x7fffffff

void init_graph(graph *a) {
    a->size=0;
    for (int i = 0; i < MAXSIZE; ++i) {
        a->vertices[i].edgeList =NULL;
        a->vertices[i].name[0] = '\0';
    }
}

void addVertex(graph *a, char *name) {
    int index = a->size;
    strcpy(a->vertices[index].name , name);
    a->size = a->size + 1;

}

void addEdge(graph *a, char *V1name, char *V2name, int is_directed, int cost) {
    int V1 = getVertexId(a, V1name);
    int V2 = getVertexId(a, V2name);
    if(findInEdge(a->vertices[V1].edgeList, V2) == NULL){
        a->vertices[V1].edgeList = insertEdge(a->vertices[V1].edgeList, V2,cost);
    }
    if(is_directed  == 0){
        if(findInEdge(a->vertices[V2].edgeList, V1) == NULL){
            a->vertices[V2].edgeList = insertEdge(a->vertices[V2].edgeList, V1,cost);
        }
    }
}

void depthFirstTraversal(graph *a) {
    bool *isVisited= calloc(a->size, sizeof(bool));
    dfs(a,0 ,isVisited);
    for (int i = 0; i < a->size; ++i) {
        if(isVisited[i] == FALSE){
            dfs(a, i, isVisited);
        }
    }
    printf("\n");
    free(isVisited);
}

void dfs(graph *a, int vertex, bool isVisited[]) {
    printf("%s ", a->vertices[vertex].name);
    isVisited[vertex] = TRUE;
    edge *alist = a->vertices[vertex].edgeList;
    while (alist !=NULL){
        if(isVisited[alist->vertex] == FALSE){
            dfs(a, alist->vertex, isVisited);
        }
        alist = alist->next;
    }
}

void breadthFirstTraversal(graph *a) {
    Que q;
    bool *isVisited = calloc(a->size, sizeof(bool));
    initQue(&q);
    for (int i = 0; i < a->size; ++i) {
        if(isVisited[i] == FALSE){
            pushQue(&q, i);
            isVisited[i] = TRUE;
            bfs(a, &q, isVisited);
        }
    }
    printf("\n");
    free(isVisited);
}

void bfs(graph *a, Que *q, bool *isVisited) {
    while (q->size > 0){
        int vertexId = popQue(q);
        printf("%s ",a->vertices[vertexId].name);
        edge *list = a->vertices[vertexId].edgeList;
        while (list !=NULL){
            if(isVisited[list->vertex] == FALSE){
                pushQue(q, list->vertex);
                isVisited[list->vertex] = TRUE;
            }
            list = list->next;
        }
    }

}

void topologicalSort(graph *a) {
    stack m; initStack(&m);
    bool *isVisited = calloc(a->size, sizeof(bool));
    for (int i = 0; i < a->size; ++i) {
        if(isVisited[i] == FALSE){
            topoSort(a, i, &m, isVisited);
        }

    }
    while (m.size > 0){
        int id = popStack(&m);
        printf("%s ", a->vertices[id].name);
    }
    free(isVisited);
}

void topoSort(graph *a, int vertexId, stack *m, bool *isVisited) {
    isVisited[vertexId] = TRUE;
    edge *adj = a->vertices[vertexId].edgeList;
    while (adj != NULL){
        int vid = adj->vertex;
        if(isVisited[vid] == FALSE){
            topoSort(a,vid, m,isVisited);
        }
        adj = adj->next;
    }
    pushStack(m, vertexId);
}

bool isGraphConnected(graph *a) {
    bool ret = FALSE;
    bool *isVisited = calloc(a->size, sizeof(bool));
    int visited = 0;
    Que openSet;
    initQue(&openSet);
    pushQue(&openSet, 0);
    isVisited[0] = TRUE;
    while (openSet.size > 0){
        int vId = openSet.top->data;
        edge *adList = a->vertices[vId].edgeList;
        while (adList != NULL){
            if(isVisited[adList->vertex] == FALSE){
                isVisited[adList->vertex] = TRUE;
                pushQue(&openSet, adList->vertex);
            }
            adList = adList->next;
        }
        popQue(&openSet);
        visited++;
    }
    if (visited == a->size){
        ret = TRUE;
    }
    return ret;

}

int getVertexId(graph *a, char *name) {
    int ret = -1;
    for (int i = 0; i < a->size && ret == -1; ++i) {
        if(strcmp(a->vertices[i].name, name) == 0){
            ret = i;
        }
    }
    return ret;
}

int minIndex(int *array, int size, bool *closeSet) {
    int min = INF;
    int i=-1;
    for (int j = 0; j < size; ++j) {
        if(array[j]<min && closeSet[j] == FALSE){
            min = array[j];
            i = j;
        }
    }
    return i;
}

int *dijkstra(graph *a, char *originName, int **costTable) {
    int origin = getVertexId(a, originName);

    int *costT = calloc(a->size, sizeof(int));
    // init distance Table;
    for (int i = 0; i < a->size; ++i) {
        costT[i] = INF;
        if(i == origin){
            costT[i] = 0;
        }
    }
    bool *closeSet = calloc(a->size, sizeof(bool));
    int counter  = 0;
    int *path = malloc(a->size * sizeof(int));
    for (int j = 0; j < a->size; ++j) {
        path[j] = -1;
    }
    while (counter < a->size){
        int v = minIndex(costT, a->size, closeSet);
        closeSet[v] = TRUE;
        counter++;
        edge *adj = a->vertices[v].edgeList;
        while (adj !=NULL){
            int vertex = adj->vertex;
            if(closeSet[vertex] == FALSE){
                if(costT[vertex] == INF){
                    costT[vertex] = costT[v] + adj->cost;
                    path[vertex] = v;
                } else{
                    if(costT[v] + adj->cost < costT[vertex]){
                        costT[vertex] = costT[v] + adj->cost;
                        path[vertex] = v;
                    }
                }
            }

            adj = adj->next;
        }
    }
    *costTable = costT;
    return path;
}








