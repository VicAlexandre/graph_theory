#include <stdio.h>
#include <stdlib.h>
#define VERTICES_AMOUNT 10

typedef struct
{
  int vertex;
  struct node *next;
} node;

typedef struct
{
  node *adj_list[VERTICES_AMOUNT];
} graph;

extern void print_graph(graph *g);

extern void create_edge(graph *g, int vertex_a, int vertex_b);

extern void add_edge(graph *g, int vertex_a, int vertex_b);
