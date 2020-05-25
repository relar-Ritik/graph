#include <stdio.h>
#include "graph.h"
#include "stack.h"
int main() {

    graph A;
    init_graph(&A);
    for (int i = 0; i < 5; ++i) {
        addVertex(&A, i);
    }
    addEdge(&A,0,1,1);
    addEdge(&A, 0,2,1);
    addEdge(&A, 1,3,1);
    addEdge(&A, 3,4,1);
    addEdge(&A, 2,4,1);
    addEdge(&A, 2,3,1);
    depthFirstTraversal(&A, 0);
    breadthFirstTraversal(&A);
    topologicalSort(&A);
    return 0;
}
