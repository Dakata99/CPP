#pragma once
#include "../Graph.h"
#include <stack>
#include <queue>
#include <map>
#include <list>

/* TODO: simplify, cause of too complex solution */
template<class Vertex, class Edge>
void BFS(const Graph<Vertex, Edge>&, const Vertex&);

/* TO CHECK IF IT WILL BE THE SAME FOR NON-ORIENTED GRAPHS */
template<class Vertex, class Edge>
void DFS(const Graph<Vertex, Edge>&, const Vertex&);

template<class Vertex, class Edge>
bool is_connected(const Graph<Vertex, Edge>&);

template<class Vertex, class Edge>
bool contains_path(const Graph<Vertex, Edge>&, const Vertex&, const Vertex&);

template<class Vertex, class Edge>
bool contains_cycle(const Graph<Vertex, Edge>&);

template<class Vertex, class Edge>
Edge Prim_algo(const Graph<Vertex, Edge>&);

template<class Vertex, class Edge>
Edge Kruskal_algo(const Graph<Vertex, Edge>&);

template<class Vertex, class Edge>
Edge Dijkstra_algo(const Graph<Vertex, Edge>&);

template<class Vertex, class Edge>
void topological_sorting(const Graph<Vertex, Edge>&);

#include "Algorithms.cpp"