#pragma once
#include <iostream>
#include <cassert>
#include <queue>
#include <cmath>

template <class T>
class Position;

template <class T>
class Iterator;

template<class T>
class BTree
{
private:
    struct Node
    {
        T value;
        Node *left, *right;
        Node(Node * = nullptr, const T& = T(), Node * = nullptr);
    };

    Node *root;
    friend Position<T>;

private:
    Node *copy(Node *, Node *);
    void copy(const BTree&);
    void dealloc(Node *);

private: /* print order traversals */
    void print_pre_order(const Node *) const;
    void print_in_order(const Node *) const;
    void print_post_order(const Node *) const;

private: /* other helper functions */
    void create_rec(Node *&, std::vector<T>, int, int);
    void print(Node *, int) const;
    void print_v2(Node *, int) const;
    bool search_element(Node *, const T&) const;
    int calc_height(const Node *) const;

public:
    BTree();
    BTree(const BTree&);
    ~BTree();

    BTree& operator=(const BTree&);

    Position<T> root_position();
    Iterator<T> begin();
    Iterator<T> end();

    void create();
    void create(std::vector<T> vec)
    bool search(const T&) const;

    void print2D() const;
    void print2D_v2() const;

    void pre_order() const;
    void in_order() const;
    void post_order() const;

    int height() const;
};

#include "BTree.cpp"
