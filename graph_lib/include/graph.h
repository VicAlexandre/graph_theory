#ifndef GRAPH_H
#define GRAPH_H

/*
 * Includes
 */
#include <stdlib.h>

/*
 * Structs
 */

/// @brief A node of the adjacency list.
typedef struct
{
  int vertex;
  struct node *next;
} node;

/// @brief The graph, represented as an adjacency list.
typedef struct
{
  int num_vertices;
  node **adj_list;
} graph;

/*
 * Functions
 */

/// @brief Creates a graph with one vertex.
/// @return A pointer to the graph.
extern graph *create_graph();

/// @brief Deallocates the graph and it's nodes.
/// @param g The graph.
extern void destroy_graph(graph *g);

/// @brief Receives a graph G and adds a new vertex to it.
/// @param g The graph.
extern void add_vertex(graph *g);

/// @brief Receives a graph G and prints the adjacency list of each vertex.
/// @param g The graph.
extern void print_graph(graph *g);

/// @brief Receives a graph G, two vertices and adds an arc between them.
/// Should be used in directed graphs.
/// @param g The graph.
/// @param source_vertex The starting vertex of the directed edge.
/// @param destination_vertex The ending vertex of the directed edge.
extern void add_arc(graph *g, int src_vertex, int destination_vertex);

/// @brief Receives a graph G, two vertices and adds an edge between them.
/// Should be used in undirected graphs.
/// @param g The graph.
/// @param vertex_a The first vertex.
/// @param vertex_b The second vertex.
extern void add_edge(graph *g, int vertex_a, int vertex_b);

#endif