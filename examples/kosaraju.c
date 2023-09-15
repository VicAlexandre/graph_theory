// Kosaraju's algorithm implementation for finding the number of strongly connected components in a digraph
// Input: The number of vertices in the digraph, n
//        The number of arcs in the digraph, m
//        m lines with two integers u and v, representing an arc from u to v
// Output: The number of strongly connected components in the digraph
//
// Written by: Victor A. Miranda - GitHub: @VicAlexandre
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

/// @brief Recursive implementation of DFS (postorder) for finding induced strongly connected components
/// @param g The graph G(V,E)
/// @param i The current vertex being visited
/// @param visited Array of visited vertices
void dfs_rec_strong_comps(graph *g, int i, int *visited)
{
    visited[i] = 1;
    node *adj = g->adj_list[i];
    while (adj != NULL)
    {
        if (visited[adj->vertex] == -1)
        {
            dfs_rec_strong_comps(g, adj->vertex, visited);
        }
        adj = adj->next;
    }
}

/// @brief Recursive implementation of DFS (postorder)
/// @param g The graph G(V,E)
/// @param i The current vertex being visited
/// @param visited Array of visited vertices
/// @param cnt Counter of visited vertices
void dfs_rec(graph *g, int i, int *visited, int *post, int *cnt)
{
    visited[i] = 1;
    node *adj = g->adj_list[i];
    while (adj != NULL)
    {
        if (visited[adj->vertex] == -1)
        {
            dfs_rec(g, adj->vertex, visited, post, cnt);
        }
        adj = adj->next;
    }
    post[i] = (*cnt)++;
}

/// @brief Receives a digraph and reverses the direction of all arcs
/// @param g The digraph G(V,A) to be reversed
graph *reverse_digraph(graph *g)
{
    graph *digraph_r = create_graph(g->num_vertices);
    add_vertices(digraph_r, g->num_vertices - 1);

    for (int i = 0; i < g->num_vertices; i++)
    {
        node *adj = g->adj_list[i];
        while (adj != NULL)
        {
            add_arc(digraph_r, adj->vertex, i);
            adj = adj->next;
        }
    }
    return digraph_r;
}

/// @brief Receives a digraph and prints the number of strongly connected components
/// @param digraph The digraph G(V,A)
void kosajaru(graph *digraph)
{
    // First DFS on the reversed digraph G^R(V,A^R)
    // this step is necessary to find a postorder permutation of the vertices
    // v0, v1, v2, ..., vn-1

    int cnt = 0;
    graph *digraph_r = reverse_digraph(digraph);
    int visited[digraph->num_vertices], post[digraph->num_vertices];

    for (int i = 0; i < digraph->num_vertices; i++)
    {
        visited[i] = -1;
        post[i] = -1;
    }

    for (int i = 0; i < digraph->num_vertices; i++)
    {
        if (visited[i] == -1)
        {
            dfs_rec(digraph_r, i, visited, post, &cnt);
        }
    }

    // Second DFS on the digraph G(V,A) using the postorder permutation,
    // this step is necessary to find the strongly connected components
    // and will produce a forest of DFS trees, each tree representing a SCC.
    // Ultimately, since the objective is to find the number of SCCs, the program
    // will only count the number of DFS trees in the forest.

    int num_scc = 0;

    for (int i = 0; i < digraph->num_vertices; i++)
    {
        visited[i] = -1;
    }

    for (int i = digraph->num_vertices - 1; i >= 0; i--)
    {
        if (visited[post[i]] == -1)
        {
            num_scc++;
            dfs_rec_strong_comps(digraph, post[i], visited);
        }
    }

    printf("%d\n", num_scc);
}

int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    if (n == 0 || m == 0)
        return 1;

    graph *digraph = create_graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= n || w >= n)
        {
            printf("The specified vertex does not exist in the graph\n");
            return 1;
        }
        add_arc(digraph, u, w);
    }

    kosajaru(digraph);

    return 0;
}