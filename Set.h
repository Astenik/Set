#pragma once

#include "Set_class.h"
#include <iostream>

template <typename T>
Set<T>::Set()
    : m_head(nullptr)
    , m_back(nullptr)
    , m_size(0)
{
    std::cout << "default ctor" << std::endl;
}

template <typename T>
Set<T>::Set(const Set<T>& ob)
    : m_head(nullptr)
    , m_back(nullptr)
    , m_size(0)
{
    Node<T>* ptr = ob.m_head;
    while(ptr)
    {
        insert(ptr->value);
        ptr = ptr->next;
    }
    std::cout << "copy ctor" << std::endl;
}

template <typename T>
Set<T>::~Set()
{
    clear();
    std::cout << "dtor" << std::endl;
}

template <typename T>
int Set<T>::size() const
{
    return m_size;
}

template <typename T>
bool Set<T>::empty() const
{
    return m_head == nullptr;
}

template <typename T>
void Set<T>::print() const
{
    for(int i = 0; i < m_size; ++i)
    {
        std::cout << (*this)[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int Set<T>::contain(const T& el) const
{
    int start = 0;
    int end = m_size - 1;
    int mid;
    while(start <= end)
    {
        mid = (start + end) / 2;
        if((*this)[mid] == el)
        {
            return mid;
        }
        else if((*this)[mid] > el)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}


template <typename T>
void Set<T>::insert(const T& el)
{
    if(!empty() && contain(el) == -1)
    {
        Node<T>* ptr = m_head;
        while(ptr && ptr->value < el)
        {
            ptr = ptr->next;
        }
        if(ptr == nullptr)
        {
            m_back->next = new Node<T>(el, m_back);
            m_back = m_back->next;
        }
        else if(ptr == m_head)
        {
            m_head = m_head->prev = new Node<T>(el, nullptr, m_head);
        }
        else
        {
            ptr = ptr->prev;
            ptr->next = ptr->next->prev = new Node<T>(el, ptr, ptr->next);
        }
        ++m_size;
    }
    else if(empty())
    {
        m_head = m_back = new Node<T>(el);
        ++m_size;
    }
}

template <typename T>
void Set<T>::remove_elem(const T& el)
{
    int ind = contain(el);
    if(ind != -1)
    {
        Node<T>* p = m_head;
        for(int i = 0; i < ind; ++i)
        {
            p = p->next;
        }
        if(p->next && p->prev)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            p = nullptr;
        }
        else if(p->next)
        {
            m_head = m_head->next;
            delete m_head->prev;
            m_head->prev = p = nullptr;
        }
        else if(p->prev)
        {
            m_back = m_back->prev;
            delete m_back->next;
            m_back->next = p = nullptr;
        }
        else
        {
            delete p;
            p = m_head = m_back = nullptr;
        }
        --m_size;
    }
    else
    {
        throw "element is not found";
    }
}

template <typename T>
void Set<T>::clear()
{
    while(!empty())
    {
        remove_elem(m_head->value);
    }
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& ob)
{
    if(&ob == this)
    {
        return *this;
    }
    clear();
    for(int i = 0; i < ob.m_size; ++i)
    {
        insert(ob[i]);
    }
    return *this;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T>& ob) const
{
    Set<T> res(*this);
    for(int i = 0; i < ob.m_size; ++i)
    {
        res.insert(ob[i]);
    }
    return res;
}

template <typename T>
bool Set<T>::operator==(const Set& ob) const
{
    if(&ob == this)
    {
        return true;
    }
    if(m_size != ob.m_size)
    {
        return false;
    }
    for(int i = 0; i < m_size; ++i)
    {
        if((*this)[i] != ob[i])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
T Set<T>::operator[](int i) const
{
    Node<T>* p = m_head;
    for(int j = 0; j < i; ++j)
    {
        p = p->next;
    }
    return p->value;
}
