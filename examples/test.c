// Simple test program for the graph library
// Input: None
// Output: The graph G with 4 vertices and 4 edges before and after removing vertex 1
//
// Written by: Victor A. Miranda - GitHub: @VicAlexandre
#include "graph.h"
#include <stdio.h>

int main(void)
{
    graph *g = create_graph(4);

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