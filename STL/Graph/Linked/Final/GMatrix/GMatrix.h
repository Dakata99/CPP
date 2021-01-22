#pragma once
#include "../Graph.h"
#include <map>

template<class Vertex, class Edge>
class GMatrix : public Graph<Vertex, Edge>
{
private:
    std::map<std::pair<Vertex, Vertex>, Edge> matrix;

    typename std::map<std::pair<Vertex, Vertex>, Edge>::iterator it;

    void print_weighted() const override;
    void print_non_weighted() const override;

public:
    GMatrix();
    GMatrix(const bool = false, const bool = false);
    GMatrix(const GMatrix&);
    ~GMatrix();

    GMatrix& operator=(const GMatrix&);

    void add_vertex(const Vertex&) override;
    void add_edge(const Vertex&, const Vertex&, const Edge& = Edge()) override;

    void remove_vertex(const Vertex&) override;
    void remove_edge(const Vertex&, const Vertex&) override;

    bool has_vertex(const Vertex&) const override;
    bool has_edge(const Vertex&, const Vertex&) const override;

    int enter_degree(const Vertex&) const override;
    int exit_degree(const Vertex&) const override;
    
    bool has_way(const Vertex&, const Vertex&) const override;
    bool isolated(const Vertex&) const override;

    std::list<Vertex> get_predecessors(const Vertex&) const override;
    std::list<Vertex> get_successors(const Vertex&) const override;

    size_t count_of_vertices() const override;
    size_t count_of_edges() const override;
    
    void BFS(const Vertex&) const override;
    void DFS(const Vertex&) const override;

    void print() const override;
    void print_degrees() const override;
};

#include "GMatrix.cpp"
