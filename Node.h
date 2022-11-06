#pragma once

template <typename T>
struct Node
{
public:
    Node(T v, Node<T>* p = nullptr, Node<T>* n = nullptr)
        : value(v)
        , prev(p)
        , next(n)
    {}
    ~Node() {}
    
public:
    T value;
    Node<T>* prev;
    Node<T>* next;
};
