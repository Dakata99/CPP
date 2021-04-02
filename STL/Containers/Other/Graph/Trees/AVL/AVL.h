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
class AVL
{
private:
    struct Node
    {
        int height;
        T value;
        Node *left, *right;
        Node(Node * = nullptr, const T& = T(), Node * = nullptr);
    };

    Node *root;
    friend Position<T>;

private:
    void copy_rec(Node *&, const Node *);
    void dealloc(Node *);

private: /* print order traversals */
    void print_pre_order(const Node *) const;
    void print_in_order(const Node *) const;
    void print_post_order(const Node *) const;

private: /* other helper functions */
    void create_rec(Node *&, const std::vector<T>&, size_t, size_t);
    Node *insert_rec(Node *, const T&);
    bool search_element(Node *, const T&) const;
    Node *remove_rec(Node *, const T&);

private:
    int balance_factor(Node *);
    Node *LL_rotation(Node *);
    Node *RR_rotation(Node *);
    Node *LR_rotation(Node *);
    Node *RL_rotation(Node *);

private:
    void print(Node *, int) const;
    void print_v2(Node *, int) const;
    int calc_height(const Node *) const;
    Node *find_min(Node *);

public:
    AVL();
    AVL(const AVL&);
    ~AVL();
    AVL& operator=(const AVL&);

    Position<T> root_position();

    void create(const std::vector<T>&);
    void insert_rec(const T&);
    void insert_iter(const T&);
    bool search_rec(const T&) const;
    bool search_iter(const T&) const;
    void remove(const T&);

    void print2D() const;
    void print2D_v2() const;

    void pre_order() const;
    void in_order() const;
    void post_order() const;

    int height() const;
};

#include "AVL.cpp"
