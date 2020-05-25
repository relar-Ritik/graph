#include <stdio.h>
#include "graph.h"
int main() {

    graph A;
    init_graph(&A);
    for (int i = 0; i < 5; ++i) {
        addVertex(&A, i+1);
    }
    addEdge(&A,1,2,0);
    addEdge(&A, 1,3,0);
    addEdge(&A, 3,5,1);
    addEdge(&A, 2, 4,0);
    addEdge(&A, 2,3,0);
    int ad = 4;
    depthFirstTraversal(&A, 1);
    return 0;
}
