#include "graph.h"
#include <stdio.h>

/// @brief Simple driver program to test the graph library
int main(void)
{
    graph *g = create_graph();

    add_vertex(g);
    add_vertex(g);
    add_vertex(g);
    add_vertex(g);

    add_edge(g, 1, 2);
    add_edge(g, 2, 3);
    add_edge(g, 1, 3);
    add_edge(g, 5, 2);
    add_edge(g, 4, 2);

    print_graph(g);

    destroy_graph(g);
    return 0;
}