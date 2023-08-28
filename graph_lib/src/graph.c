#include "graph.h"

void print_graph(graph *g)
{
    for (int i = 0; i < VERTICES_AMOUNT; i++)
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

void create_edge(graph *g, int vertex_a, int vertex_b)
{
    node *new_v = malloc(sizeof(node));
    new_v->vertex = vertex_b;
    new_v->next = NULL;
    node *current_v = g->adj_list[vertex_a - 1];

    if (current_v == NULL)
    {
        g->adj_list[vertex_a - 1] = new_v;
    }
    else
    {
        while (current_v->next != NULL)
        {
            current_v = current_v->next;
        }
        current_v->next = new_v;
    }
}

void add_edge(graph *g, int vertex_a, int vertex_b)
{
    create_edge(g, vertex_a, vertex_b);
    create_edge(g, vertex_b, vertex_a);
}
