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
    g->adj_list[g->num_vertices] = NULL;
    g->num_vertices++;
}

void add_vertices(graph *g, int n)
{
    if (!g)
        return;

    g->adj_list = realloc(g->adj_list, sizeof(node *) * (g->num_vertices + n));
    if (!g->adj_list)
        return;
    for (int i = g->num_vertices; i < g->num_vertices + n; i++)
        g->adj_list[i] = NULL;
    g->num_vertices += n;
}

void print_graph(graph *g)
{
    if (!g)
        return;

    for (int i = 0; i < g->num_vertices; i++)
    {
        printf("%d  ->  ", i);
        node *current_v = g->adj_list[i];
        while (current_v != NULL)
        {
            printf("%d  ->  ", current_v->vertex);
            current_v = current_v->next;
        }
        printf("\n");
    }
}

void add_arc(graph *g, int src_vertex, int dest_vertex)
{
    if (!g || src_vertex > g->num_vertices || dest_vertex > g->num_vertices)
        return;

    node *new_v = malloc(sizeof(node));
    if (!new_v)
        return;

    new_v->vertex = dest_vertex;
    new_v->next = NULL;
    node *aux = g->adj_list[src_vertex];
    if (!aux)
    {
        g->adj_list[src_vertex] = new_v;
        return;
    }

    while (aux->next)
        aux = aux->next;

    aux->next = new_v;
}

void add_edge(graph *g, int vertex_a, int vertex_b)
{
    add_arc(g, vertex_a, vertex_b);
    add_arc(g, vertex_b, vertex_a);
}

void remove_arc(graph *g, int src_vertex, int dest_vertex)
{
    if (!g || src_vertex > g->num_vertices || dest_vertex > g->num_vertices)
        return;

    node *current_v = g->adj_list[src_vertex];
    if (!current_v)
        return;

    if (current_v->vertex == dest_vertex)
    {
        g->adj_list[src_vertex] = current_v->next;
        return;
    }

    node *temp = current_v->next;
    while (current_v->next)
    {
        if (current_v->next->vertex == dest_vertex)
        {
            current_v->next = temp->next;
            free(temp);
        }
    }
}

void remove_edge(graph *g, int vertex_a, int vertex_b)
{
    remove_arc(g, vertex_a, vertex_b);
    remove_arc(g, vertex_b, vertex_a);
}

int get_num_edges(graph *g)
{
    int degree_counter = 0;
    for (int i = 0; i < g->num_vertices; i++)
    {
        node *current_v = g->adj_list[i];
        while (current_v)
        {
            degree_counter++;
            current_v = current_v->next;
        }
    }
    return degree_counter / 2;
}

int get_neighbours(graph *g, int vertex)
{
    int neighbour_counter = 0;
    node *current_v = g->adj_list[vertex];

    while (current_v)
    {
        neighbour_counter++;
        current_v = current_v->next;
    }

    return neighbour_counter;
}

void remove_vertex(graph *g, int vertex)
{
    if (!g || vertex > g->num_vertices)
        return;

    // Removes all arcs that point to the vertex and corrects vertex labels that are greater than the removed
    // vertex's label.
    for (int i = 0; i < g->num_vertices; i++)
    {
        node *current_v = g->adj_list[i];
        while (current_v)
        {
            if (current_v->vertex == vertex)
            {
                remove_arc(g, i, vertex);
                break;
            }
            if (current_v->vertex > vertex)
                current_v->vertex--;
            current_v = current_v->next;
        }
    }

    // Deallocates the vertex's adjacency list.
    node *temp = g->adj_list[vertex];
    while (temp)
    {
        node *temp2 = temp;
        temp = temp->next;
        free(temp2);
    }

    // Shifts the adjacency list to the left for all vertices that are greater than the removed vertex
    // for subsequent reallocation.
    for (int i = vertex; i < g->num_vertices; i++)
    {
        g->adj_list[i] = g->adj_list[i + 1];
    }

    // Reallocates the adjacency list for the new number of vertices.
    g->adj_list = realloc(g->adj_list, sizeof(node *) * (g->num_vertices - 1));
    g->num_vertices--;
}