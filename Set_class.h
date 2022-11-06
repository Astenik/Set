#pragma once

#include "Node.h"

template <typename T>
class Set 
{
public:
    Set();
    Set(const Set&);
    Set(const Set&&);
    ~Set();

public:
    int size() const;
    bool empty() const;
    friend void print(const Set&);
    
    void insert(const T&);
    void remove_elem(const T&);
    void clear();
    
    Set& operator=(const Set&);
    Set operator+(const Set&) const;
    bool operator==(const Set&) const;
    T operator[](int) const;
    
print:
    Node<T>* m_head;
    Node<T>* m_back;
    int m_size;
};
