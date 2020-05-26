#include <stdio.h>
#include "graph.h"
#include "stack.h"
int main(){

    graph A;
    init_graph(&A);

    addVertex(&A,"A");
    addVertex(&A,"B");
    addVertex(&A,"C");
    addVertex(&A,"D");
    addVertex(&A,"E");


    addEdge(&A, "A", "B", 1,10);
    addEdge(&A, "A", "C", 1,5);
    addEdge(&A, "C", "D", 1,15);
    addEdge(&A, "B", "E", 1,10);
    addEdge(&A, "E", "D", 1,1);



    depthFirstTraversal(&A);
    breadthFirstTraversal(&A);
    topologicalSort(&A);
    int n = isGraphConnected(&A);
    printf("\n%d\n", n);
    return 0;
}
