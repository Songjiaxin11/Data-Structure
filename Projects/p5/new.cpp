#include "dlist.h"
#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
bool Dlist<T>::isEmpty() const
{
    return this->first == NULL && this->last == NULL;
}

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
        newNode->next = NULL;
        newNode->prev = NULL;
    }
}


// template <class T>
// void Dlist<T>::insertBack(T *op) {
//     node *newnode = new node;
//     newnode->op = op;
//     if (this->isEmpty()){
//         this->first=newnode;
//         this->last=newnode;
//         this->first->next=NULL;
//         this->last->next=NULL;
//         this->first->prev=NULL;
//         this->last->prev=NULL;
//     }
//     else {

//         this->last->next = newnode;
//         newnode->prev = this->last;
//         newnode->next = NULL;

//         this->last = newnode;

// //        if (this->first->next == NULL){
// //            this->first->next = this->last;
// //        }
// //        else {
// //            this->first->next->prev = this->first;
// //        }
//     }
// }
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
        newNode->next = NULL;
        newNode->prev = NULL;
    }
}

template <class T>
Dlist<T>::Dlist()
{
    this->first = this->last = NULL;
}

// template <class T>
// Dlist<T>::Dlist(const Dlist &l)
// {
//     this->first = NULL;
//     this->last = NULL;
//     // this->removeAll();
//     this->copyAll(l);
// }
template <class T>
Dlist<T>::Dlist(const Dlist &l)
{
    this->first = NULL;
    this->last = NULL;
    removeAll();
    copyAll(l);
}


template <class T>
Dlist<T>::~Dlist()
{
    this->removeAll();
}

template <class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l)
{
    this->removeAll();
    this->copyAll(l);
    return *this;
}

template <class T>
void Dlist<T>::removeAll()
{
    while (!this->isEmpty())
    {
        removeFront();
    }
    delete first;
    delete last;
}


template <class T>
void Dlist<T>::copyAll(const Dlist &l)
{
    removeAll();
    if (!l.isEmpty())
    {
        node *cur = l.last;
        while (cur != l.first)
        {
            insertFront(cur->op);
            cur = cur->prev;
        }
        insertFront(cur->op);
    }
}

template <class T>
T *Dlist<T>::removeFront()
{
    // 1. 检查链表是否为空
    if (this->isEmpty())
    {
        throw emptyList();
    }
    // 2. 保存要删除的节点指针
    node *temp = this->first;
    T *op = temp->op; // 复制给了指针op
  if (this->first != this->last || this->last == NULL)
    {
        // 3. 更新链表头指针, 指向原先的第一个节点的下一个节点
        this->first = temp->next;
        this->first->next = temp->next->next;
        // 4. 更新下一个节点的prev指针
        this->first->prev = NULL;
        // 5. 更新结点的next指针
    }
    else
    {
        // first->prev = first->next = NULL;
        this->first = this->last = NULL;
    }
  
    delete temp;
    return op;
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

template <class T>
T *Dlist<T>::removeBack()
{
    // 1. 检查链表是否为空
    if (this->isEmpty())
    {
        throw emptyList();
    }
    // 2. 保存要删除的节点指针
    node *temp = this->last;
    T *op = temp->op; // 复制给了指针op
    if (this->first != this->last || this->first == NULL)
    {
        // 3. 更新链表头指针, 指向原先的last节点的上一个节点
        this->last = temp->prev;
        this->last->prev = temp->prev->prev;
        this->last->next = NULL;
        
    }
    else
    {
      this->first = this->last = NULL;
    }
    delete temp;
    return op;
}



int main()
{
    Dlist<int> intList;

    // 在列表前端插入一些元素
    int value1 = 42;
    int value2 = 24;
    int value3 = 12;
    int value4 = 18;
    // 12 12 24 42
    intList.insertFront(&value1);
    intList.print();
    intList.insertFront(&value2);
    intList.print();
    intList.insertBack(&value3);
    intList.print();
    intList.insertBack(&value4);
    intList.print();
    Dlist l2 = Dlist(intList);
    l2.print();
    l2.insertBack(&value4);
    cout<<"l2 "<<endl;
    l2.print();
    Dlist l3 = Dlist(l2);
    cout<<"l3: "<<endl;
    l3.print();
    l3.removeFront();
    l3.print();
    l3.removeBack();
    l3.print();

   

    // try
    // {
    //     intList.removeFront();
    // }
    // catch (const std::exception &e)
    // {
    //     std::cout << "Caught an emptyList exception" << endl;
    // }

    // catch (emptyList)
    // {
    //     cout << "empty" << endl;
    // }
    return 0;
}