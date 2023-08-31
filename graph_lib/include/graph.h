#ifndef GRAPH_H
#define GRAPH_H

/*
 * Includes
 */
#include <stdlib.h>

typedef struct node node;

typedef struct graph graph;
/*
 * Structs
 */

/// @brief A node of the adjacency list.
struct node
{
  int vertex;
  struct node *next;
};

/// @brief The graph, represented as an adjacency list.
struct graph
{
  int num_vertices;
  node **adj_list;
};

/*
 * Prototypes
 */

/// @brief Creates a graph with one vertex (Trivial graph).
/// @return A pointer to the graph.
extern graph *create_graph();

/// @brief Deallocates the graph and it's nodes.
/// @param g The graph G(V,E).
extern void destroy_graph(graph *g);

/// @brief Receives a graph G and adds a new vertex to it.
/// @param g The graph G(V,E).
extern void add_vertex(graph *g);

/// @brief Receives a graph G and prints the adjacency list of each vertex.
/// @param g The graph G(V,E).
extern void print_graph(graph *g);

/// @brief Receives a graph G, two vertices and adds an arc between them.
/// Should be used in directed graphs.
/// @param g The graph G(V,E).
/// @param source_vertex The starting vertex of the directed edge.
/// @param destination_vertex The ending vertex of the directed edge.
extern void add_arc(graph *g, int src_vertex, int destination_vertex);

/// @brief Receives a graph G, two vertices and adds an edge between them.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @param vertex_a The first vertex.
/// @param vertex_b The second vertex.
extern void add_edge(graph *g, int vertex_a, int vertex_b);

/// @brief Receives a graph G, two vertices and removes an arc between them.
/// Should be used in directed graphs.
/// @param g The graph G(V,E).
/// @param source_vertex The starting vertex of the directed edge.
/// @param destination_vertex The ending vertex of the directed edge.
extern void remove_arc(graph *g, int src_vertex, int dest_vertex);

/// @brief Receives a graph G, two vertices and adds an edge between them.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @param vertex_a The first vertex.
/// @param vertex_b The second vertex.
extern void remove_edge(graph *g, int vertex_a, int vertex_b);

/// @brief Receives a graph G and returns the number of edges.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @return The number of edges.
extern int get_num_edges(graph *g);

/// @brief Receives a graph G and a vertex and returns the number of neighbours.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @param vertex The vertex.
extern int get_neighbours(graph *g, int vertex);

/// @brief Receives a graph G and a vertex and removes the vertex and all edges incident with it,
/// also updates all labels of the vertices greater than the removed vertex's label.
/// @warning This function is not efficient, watch out for large graphs.
/// @param g The graph G(V,E).
/// @param vertex The vertex.
extern void remove_vertex(graph *g, int vertex);
#endif