// A simple graph library written in C, the graph is represented as an adjacency list.
// The graph can be directed or undirected. Weighted graphs are not supported.
//
// Written by: Victor A. Miranda - GitHub: @VicAlexandre

#ifndef GRAPH_H
#define GRAPH_H

/*
 * Includes
 */
#include <stdlib.h>

/*
 * Typedefs
 */
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
graph *create_trivial_graph();

/// @brief Creates a graph with n vertices.
/// @param n The number of vertices.
/// @return A pointer to the graph.
graph *create_graph(int n);

/// @brief Deallocates the graph and it's nodes.
/// @param g The graph G(V,E).
void destroy_graph(graph *g);

/// @brief Receives a graph G and adds a new vertex to it.
/// @param g The graph G(V,E).
void add_vertex(graph *g);

/// @brief Receives a graph G and adds n new vertices to it.
/// @param g The graph G(V,E).
/// @param n The number of vertices to be added.
void add_vertices(graph *g, int n);

/// @brief Receives a graph G, two vertices and adds an arc between them.
/// Should be used in directed graphs.
/// @param g The graph G(V,E).
/// @param src_vertex The starting vertex of the directed edge.
/// @param destination_vertex The ending vertex of the directed edge.
/// @warning This function does not check it the arc already exists.
void add_arc(graph *g, int src_vertex, int destination_vertex);

/// @brief Receives a graph G, two vertices and adds an edge between them.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @param vertex_a The first vertex.
/// @param vertex_b The second vertex.
/// @warning This function does not check it the edge already exists.
void add_edge(graph *g, int vertex_a, int vertex_b);

/// @brief Receives a graph G, two vertices and removes an arc between them.
/// Should be used in directed graphs.
/// @param g The graph G(V,E).
/// @param src_vertex The starting vertex of the directed edge.
/// @param destination_vertex The ending vertex of the directed edge.
void remove_arc(graph *g, int src_vertex, int dest_vertex);

/// @brief Receives a graph G, two vertices and adds an edge between them.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @param vertex_a The first vertex.
/// @param vertex_b The second vertex.
void remove_edge(graph *g, int vertex_a, int vertex_b);

/// @brief Receives a graph G and a vertex and removes the vertex and all edges incident with it,
/// also updates all labels of the vertices greater than the removed vertex's label.
/// @warning This function is not efficient, watch out for large graphs.
/// @param g The graph G(V,E).
/// @param vertex The vertex.
void remove_vertex(graph *g, int vertex);

/// @brief Receives a graph G and prints the adjacency list of each vertex.
/// @param g The graph G(V,E).
void print_graph(const graph *g);

/// @brief Receives a graph G and returns the number of edges.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @return The number of edges.
int get_num_edges(const graph *g);

/// @brief Receives a graph G and a vertex and returns the number of neighbours.
/// Should be used in undirected graphs.
/// @param g The graph G(V,E).
/// @param vertex The vertex.
int get_neighbours(const graph *g, int vertex);

#endif