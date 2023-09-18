#include "graph.h"

Graph *create_trivial_graph()
{
    Graph *g = malloc(sizeof(Graph));
    if (!g)
        return NULL;

    g->num_vertices = 1;
    g->adj_list = malloc(sizeof(Node *));
    g->adj_list[0] = NULL;
    return g;
}

Graph *create_graph(int n)
{
    Graph *g = malloc(sizeof(Graph));
    if (!g)
        return NULL;

    g->num_vertices = n;
    g->adj_list = malloc(sizeof(Node *) * n);
    if (!g->adj_list)
        return;

    for (int i = 0; i < n; i++)
    {
        g->adj_list[i] = NULL;
    }

    return g;
}

void destroy_graph(Graph *g)
{
    if (!g)
        return;

    for (int i = 0; i < g->num_vertices; i++)
    {
        Node *current_v = g->adj_list[i];
        while (current_v)
        {
            Node *temp_v = current_v;
            current_v = current_v->next;
            free(temp_v);
        }
    }
    free(g->adj_list);
    free(g);
}

void add_vertex(Graph *g)
{
    if (!g)
        return;

    g->adj_list = realloc(g->adj_list, sizeof(Node *) * (g->num_vertices + 1));
    if (!g->adj_list)
        return;
    g->adj_list[g->num_vertices] = NULL;
    g->num_vertices++;
}

void add_vertices(Graph *g, int n)
{
    if (!g)
        return;

    g->adj_list = realloc(g->adj_list, sizeof(Node *) * (g->num_vertices + n));
    if (!g->adj_list)
        return;
    for (int i = g->num_vertices; i < g->num_vertices + n; i++)
        g->adj_list[i] = NULL;
    g->num_vertices += n;
}

void add_arc(Graph *g, int src_vertex, int dest_vertex)
{
    if (!g || src_vertex >= g->num_vertices || dest_vertex >= g->num_vertices)
        return;

    Node *new_v = malloc(sizeof(Node));
    if (!new_v)
        return;

    new_v->vertex = dest_vertex;
    new_v->next = NULL;
    Node *aux = g->adj_list[src_vertex];
    if (!aux)
    {
        g->adj_list[src_vertex] = new_v;
        return;
    }

    while (aux->next)
        aux = aux->next;

    aux->next = new_v;
}

void add_edge(Graph *g, int vertex_a, int vertex_b)
{
    add_arc(g, vertex_a, vertex_b);
    add_arc(g, vertex_b, vertex_a);
}

void remove_arc(Graph *g, int src_vertex, int dest_vertex)
{
    if (!g || src_vertex >= g->num_vertices || dest_vertex >= g->num_vertices)
        return;

    Node *current_v = g->adj_list[src_vertex];
    if (!current_v)
        return;

    if (current_v->vertex == dest_vertex)
    {
        g->adj_list[src_vertex] = current_v->next;
        return;
    }

    Node *temp = current_v->next;
    while (current_v->next)
    {
        if (current_v->next->vertex == dest_vertex)
        {
            current_v->next = temp->next;
            free(temp);
        }
    }
}

void remove_edge(Graph *g, int vertex_a, int vertex_b)
{
    remove_arc(g, vertex_a, vertex_b);
    remove_arc(g, vertex_b, vertex_a);
}

void remove_vertex(Graph *g, int vertex)
{
    if (!g || vertex > g->num_vertices)
        return;

    // Removes all arcs that point to the vertex and corrects vertex labels that are greater than the removed
    // vertex's label.
    for (int i = 0; i < g->num_vertices; i++)
    {
        Node *current_v = g->adj_list[i];
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
    Node *temp = g->adj_list[vertex];
    while (temp)
    {
        Node *temp2 = temp;
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
    g->adj_list = realloc(g->adj_list, sizeof(Node *) * (g->num_vertices - 1));
    g->num_vertices--;
}

void print_graph(const Graph *g)
{
    if (!g)
        return;

    for (int i = 0; i < g->num_vertices; i++)
    {
        printf("%d  ->  ", i);
        Node *current_v = g->adj_list[i];
        while (current_v != NULL)
        {
            printf("%d  ->  ", current_v->vertex);
            current_v = current_v->next;
        }
        printf("\n");
    }
}

int graph_has_arc(const Graph *g, int src_vertex, int dest_vertex)
{
    if (g == NULL || src_vertex >= g->num_vertices || dest_vertex >= g->num_vertices)
        return 0;

    Node *current_v = g->adj_list[src_vertex];
    while (current_v != NULL)
    {
        if (current_v->vertex == dest_vertex)
            return 1;
        current_v = current_v->next;
    }
    return 0;
}

int get_num_edges(const Graph *g)
{
    int degree_counter = 0;
    for (int i = 0; i < g->num_vertices; i++)
    {
        Node *current_v = g->adj_list[i];
        while (current_v)
        {
            degree_counter++;
            current_v = current_v->next;
        }
    }
    return degree_counter / 2;
}

int get_neighbours(const Graph *g, int vertex)
{
    int neighbour_counter = 0;
    Node *current_v = g->adj_list[vertex];

    while (current_v)
    {
        neighbour_counter++;
        current_v = current_v->next;
    }

    return neighbour_counter;
}
