#include "graph_lib/src/graph.h"

int main(void)
{
    graph g = {NULL};
    int edges;
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&g, u, v);
    }
    print_graph(&g);
}