// Recursive DFS implementation
// Input: The number of vertices in the graph, n
//        The number of edges in the graph, m
//        m lines with two integers u and v, representing an edge uv in E(G)
// Output: The order in which vertices were discovered by the search (preorder)
//
// Written by: Victor A. Miranda - GitHub: @VicAlexandre
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void dfs_rec(graph *g, int i, int *visited, int *cnt);

int main()
{
    int n, m, cnt = 0; // n = number of vertices, m = number of edges
    graph *g = create_graph();

    scanf("%d %d", &n, &m);

    add_vertices(g, n - 1);

    for (int i = 0; i < m; i++)
    {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= n || w >= n)
        {
            printf("The specified vertex does not exist in the graph\n");
            return 1;
        }
        add_edge(g, u, w);
    }

    int visited[g->num_vertices];
    for (int i = 0; i < g->num_vertices; i++)
        visited[i] = -1;

    for (int i = 0; i < g->num_vertices; i++)
    {
        if (visited[i] == -1)
        {
            dfs_rec(g, i, visited, &cnt);
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", visited[i]);
    printf("\n");
    destroy_graph(g);
    return 0;
}

/// @brief Recursive implementation of DFS
/// @param g The graph G(V,E)
/// @param i The current vertex being visited
/// @param visited Array of visited vertices
/// @param cnt Counter of visited vertices
void dfs_rec(graph *g, int i, int *visited, int *cnt)
{
    visited[i] = (*cnt)++;
    node *v = g->adj_list[i];
    while (v != NULL)
    {
        if (visited[v->vertex] == -1)
        {
            dfs_rec(g, v->vertex, visited, cnt);
        }
        v = v->next;
    }

    return;
}