#include "graph.h"

graph *create_graph()
{
    graph *g = malloc(sizeof(graph));
    if (!g)
        return NULL;

    g->num_vertices = 1;
    g->adj_list = malloc(sizeof(node *));
    g->adj_list[0] = NULL;
    return g;
}

void destroy_graph(graph *g)
{
    if (!g)
        return;

    for (int i = 0; i < g->num_vertices; i++)
    {
        node *current_v = g->adj_list[i];
        while (current_v)
        {
            node *temp_v = current_v;
            current_v = current_v->next;
            free(temp_v);
        }
    }
    free(g->adj_list);
    free(g);
}

void add_vertex(graph *g)
{
    if (!g)
        return;

    g->adj_list = realloc(g->adj_list, sizeof(node *) * (g->num_vertices + 1));
    if (!g->adj_list)
        return;
    g->adj_list[g->num_vertices++] = NULL;
}

void print_graph(graph *g)
{
    if (!g)
        return;

    for (int i = 0; i < g->num_vertices; i++)
    {
        printf("%d  ->  ", i + 1);
        node *current_v = g->adj_list[i];
        while (current_v != NULL)
        {
            printf("%d  ->  ", current_v->vertex);
            current_v = current_v->next;
        }
        printf("\n");
    }
}

void add_arc(graph *g, int src_vertex, int destination_vertex)
{
    if (!g || src_vertex > g->num_vertices || destination_vertex > g->num_vertices)
        return;

    node *new_v = malloc(sizeof(node));
    if (!new_v)
        return;

    new_v->vertex = destination_vertex;
    new_v->next = g->adj_list[src_vertex - 1];
    g->adj_list[src_vertex - 1] = new_v;
}

void add_edge(graph *g, int vertex_a, int vertex_b)
{
    add_arc(g, vertex_a, vertex_b);
    add_arc(g, vertex_b, vertex_a);
}
