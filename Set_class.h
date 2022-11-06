#pragma once

#include "Node.h"

template <typename T>
class Set 
{
public:
    Set();
    Set(const Set<T>&);
    Set(const Set<T>&&);
    ~Set();

public:
    int size() const;
    bool empty() const;
    void print() const;
    int contain(const T&) const;
    
    void insert(const T&);
    void remove_elem(const T&);
    void clear();
    
    Set<T>& operator=(const Set<T>&);
    Set<T> operator+(const Set<T>&) const;
    bool operator==(const Set<T>&) const;
    T operator[](int) const;
    
private:
    Node<T>* m_head;
    Node<T>* m_back;
    int m_size;
};
