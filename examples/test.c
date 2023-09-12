#include "graph.h"
#include <stdio.h>

/// @brief Simple driver program to test the graph library
int main(void)
{
    graph *g = create_graph();

    add_vertex(g);
    add_vertex(g);
    add_vertex(g);

    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 3, 2);
    add_edge(g, 1, 3);

    print_graph(g);
    remove_vertex(g, 1);
    printf("====================================\n");
    print_graph(g);

    destroy_graph(g);
    return 0;
}