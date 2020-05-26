#include <stdio.h>
#include "graph.h"
#include "stack.h"
int main(){

    graph A;
    init_graph(&A);

    addVertex(&A,"0");
    addVertex(&A,"1");
    addVertex(&A,"2");
    addVertex(&A,"3");
    addVertex(&A,"4");
    addVertex(&A,"5");
    addVertex(&A,"6");
    addVertex(&A,"7");
    addVertex(&A, "8");


    addEdge(&A, "0", "1", 0,4);
    addEdge(&A, "0", "7", 0,8);
    addEdge(&A, "1", "2", 0,8);
    addEdge(&A, "1", "7", 0,11);
    addEdge(&A, "2", "3", 0,7);
    addEdge(&A, "2", "5", 0,4);
    addEdge(&A, "2", "8", 0,2);
    addEdge(&A, "3", "4", 0,9);
    addEdge(&A, "3", "5", 0,14);
    addEdge(&A, "7", "6", 0,1);
    addEdge(&A, "7", "8", 0,7);
    addEdge(&A, "6", "5", 0,2);
    addEdge(&A, "6", "8", 0,6);
    addEdge(&A, "5", "4", 0,10);
    dijkstra(&A, "0");
    depthFirstTraversal(&A);
    breadthFirstTraversal(&A);
    topologicalSort(&A);
    int n = isGraphConnected(&A);
    printf("\n%d\n", n);
    return 0;
}
