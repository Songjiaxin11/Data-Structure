#ifndef DLIST_IMPL_H
#define DLIST_IMPL_H
#include <iostream>
#include "dlist.h"
using namespace std;

// Functions

/**
 * @brief  returns true if list is empy, false otherwise
 *
 * @tparam T
 * @return true
 * @return false
 */
template <class T>
bool Dlist<T>::isEmpty() const
{
    return this->first == nullptr;
}

/**
 * @brief insertFront
 *
 * @tparam T
 * @param op
 */
template <class T>
void Dlist<T>::insertFront(T *op)
{
    node *newNode = new node;
    newNode->op = op;
    if (!this->isEmpty())
    {
        newNode->next = this->first;
        newNode->prev = this->last;
        this->first->prev = newNode;
        this->last->next = newNode;
        this->first = newNode;
    }
    else
    {
        this->first = newNode;
        this->last = newNode;
        // 相当于first, last 的prev, next全部为NULL
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
}

/**
 * @brief insertBack
 *
 * @tparam T
 * @param op
 */
template <class T>
void Dlist<T>::insertBack(T *op)
{
    node *newNode = new node;
    newNode->op = op;
    if (!this->isEmpty())
    {
        newNode->prev = this->last;
        newNode->next = this->first;
        this->first->prev = newNode;
        this->last->next = newNode;
        this->last = newNode;
    }
    else
    {
        this->first = newNode;
        this->last = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
}

/**
 * @brief removeFront
 *
 * @tparam T
 * @return T*
 */
template <class T>
T *Dlist<T>::removeFront()
{
    node *temp = this->first;
    T *old = temp->op;
    if (this->isEmpty())
    {
        throw emptyList();
    }
    else
    {
        // 复制给了指针op
        if (this->first == this->last)
        {
            this->first = this->last = nullptr;
        }
        else
        {
            this->first = temp->next;
            this->first->prev = nullptr;
        }
    }
    delete temp;
    return old;
}

/**
 * @brief removeBack
 *
 * @tparam T
 * @return T*
 */
template <class T>
T *Dlist<T>::removeBack()
{
    node *temp = this->last;
    T *old2 = temp->op;
    // 1. 检查链表是否为空
    if (this->isEmpty())
    {
        throw emptyList();
    }
    // 2. 保存要删除的节点指针
    // 复制给了指针op
    else
    {
        if (this->first == this->last)
        {
            this->first = this->last = nullptr;
        }
        else
        {
            this->last = temp->prev;
            this->last->next = nullptr;
        }
    }
    delete temp;
    return old2;
}

/**
 * @brief removeAll
 *
 * @tparam T
 */
template <class T>
void Dlist<T>::removeAll()
{
    while (!this->isEmpty())
    {
        T *nmd = removeFront();
        delete nmd;//invalid pointer
        // this->removeFront();
    }
    // delete last;
    // delete first;
}

template <class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l)
{
    removeAll();
    copyAll(l);
    return *this;
}

/**
 * @brief Construct a new Dlist< T>:: Dlist objectC
 *
 * @tparam T
 */
template <class T>
Dlist<T>::Dlist()
{
    this->first = this->last = NULL;
}

template <class T>
Dlist<T>::~Dlist()
{
    // delete node;
    this->removeAll();
}
// helper function copyAll
template <class T>
void Dlist<T>::copyAll(const Dlist &l)
{
    this->removeAll();
    if (!l.isEmpty())
    {
        node *cur = l.last;
        while (cur != l.first)
        {
            this->insertFront(new T(*cur->op));
            cur = cur->prev;
        }
        this->insertFront(new T(*cur->op));
    }
}

/**
 * @brief copy Constructor
 *
 * @tparam T
 * @param l
 */
template <class T>
Dlist<T>::Dlist(const Dlist &l)
{
    this->first = NULL;
    // this->first->next = nullptr;
    this->last = nullptr;
    if (this != &l)
    {
        this->removeAll();
        this->copyAll(l);
    }
}

template <class T>
void Dlist<T>::print()
{
    node *cur = this->first;
    bool isEnd = false;
    while (cur && !isEnd)
    {
        if (cur == this->last)
        {
            isEnd = true;
        }
        cout << *(cur->op) << " " << flush;
        cur = cur->next;
    }
    cout << endl;
}

#endif