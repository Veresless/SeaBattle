/**********************************************************************
 *  Project        SeaBattle ( Gen20x )
 *  (c) copyright  2020
 *  Company        Luxoft
 *  All rights reserved
 **********************************************************************/
/**
 * @file    List.hpp
 * @author  Kirieiev Ivan (ikirieiev@luxoft.com)
 * @brief   The List template class
 */

#ifndef H_LIST
#define H_LIST
#include "Iterrator.hpp"
namespace Collections
{
typedef unsigned long long SIZE;
template<class T>
class List
{
	struct Node;
public:
    Iterator<Node, T> begin();
    Iterator<Node, T> end();
    Iterator<Node, const T> begin() const;
    Iterator<Node, const T> end() const;

    List();
    List(const List& list);
    List(const List&& list);
    List& operator = (const List& list);
    List(unsigned int count, const T* arr);
    void push_back(const T& data);
    void push_front(const T& data);
    template <class... Args>
    void emplace_back(Args&&... data);
    template <class... Args>
    void emplace_front(Args&&... data);
    bool pop_back();
    bool pop_front();
    inline const T& front();
    inline const T& back();
    bool insert(const unsigned int position, const T& data);
    SIZE size();
    void clear();
    ~List();
private:

struct Node
    {
    	template <class C>
    	friend class List;
        Node * mNext;
        Node * mPrev;
        T mValue;
        Node(T _val):mValue(_val), mNext(nullptr), mPrev(nullptr){}
        Node(Node& node):mNext(node.mNext), mPrev(node.mPrev), mValue(node.mValue) {}
        Node(Node&& node):mNext(node.mNext),  mPrev(node.mPrev), mValue(node.mValue)
        {
                node.mNext = nullptr;
                node.mPrev = nullptr;
        }
    };
    Node* m_head;
    Node* m_tail;
    SIZE m_size;
};
template<class T>
List<T>::List()
    : m_head(nullptr)
    , m_tail(nullptr),
    m_size(0)
{

}

template<class T>
List<T>::List(unsigned int count, const T* arr):m_head(nullptr), m_tail(nullptr), m_size(0)
{
    for (int i = 0; i < count && nullptr != (arr + i); i++)
    {
        push_back(arr[i]);
    }
}
template<class T>
List<T>::List(const List& list): m_head(nullptr), m_tail(nullptr),m_size(0)
{
    if (nullptr != list.m_head)
    {
        Node* itterator = list.m_head;
        while (nullptr != itterator->mNext)
        {
            push_back(itterator->mValue);
            itterator = itterator->mNext;
        }
        push_back(itterator->mValue);
    }
}
template<class T>
List<T>::List(const List&& list): m_head(list.m_head), m_tail(list.m_tail), m_size(list.m_size)
{
    list.m_head = nullptr;
    list.m_tail = nullptr;
    m_size =0;
}
template<class T>
List<T>& List<T>::operator = (const List& list)
{
	clear();
    if (nullptr != list.m_head)
    {
        Node* itterator = list.m_head;
        while (nullptr != itterator->mNext)
        {
            push_back(itterator->mValue);
            itterator = itterator->mNext;
        }
        push_back(itterator->mValue);
    }
}
template<class T>
void List<T>::push_back(const T& data)
{
    Node* node = new Node(data);
    if (nullptr == m_tail)
    {
        m_tail = m_head = node;
    }
    else
    {
        m_tail->mNext = node;
        node->mPrev = m_tail;
        m_tail = node;
    }
    m_size++;
}
template<class T>
void List<T>::push_front(const T& data)
{
    Node* node = new Node(data);
    if (nullptr == m_head)
    {
        m_tail = m_head = node;
    }
    else
    {
        m_head->mPrev = node;
        node->mNext = m_head;
        m_head = node;
    }
    m_size++;
}
template<class T>
template <class... Args>
void List<T>::emplace_back(Args&&... data)
{
    Node* node = new Node(data...);
    if (nullptr == m_tail)
    {
        m_tail = m_head = node;
    }
    else
    {
        m_tail->mNext = node;
        node->mPrev = m_tail;
        m_tail = node;
    }
    m_size++;
}
template<class T>
template <class... Args>
void List<T>::emplace_front(Args&&... data)
{
    Node* node = new Node(data...);
    if (nullptr == m_head)
    {
        m_tail = m_head = node;
    }
    else
    {
        m_head->mPrev = node;
        node->mNext = m_head;
        m_head = node;
    }
    m_size++;
}
template<class T>
bool List<T>::pop_back()
{
    bool rezult;
    if (nullptr == m_tail)
    {
        rezult = false;
    }
    else
    if (nullptr == m_tail->mPrev)
    {
        delete m_tail;
        m_tail = m_head = nullptr;
        rezult = true;
    }
    else
    {
        m_tail = m_tail->mPrev;
        delete m_tail->mNext;
        m_tail->mNext = nullptr;
        rezult = true;
    }
    if (rezult) m_size--;
    return rezult;
}
template<class T>
bool List<T>::pop_front()
{
    bool rezult;
    if (nullptr == m_head)
    {
        rezult = false;
    }
    else
    if (nullptr == m_head->mNext)
    {
        delete m_head;
        m_head = m_tail = nullptr;
        rezult = true;
    }
    else
    {
        m_head = m_head->mNext;
        delete m_head->mPrev;
        m_head->mPrev = nullptr;
        rezult = true;
    }
    if (rezult) m_size--;
    return rezult;
}
template<class T>
bool List<T>::insert(const unsigned int position, const T& data)
{
    bool rezult = true;
    if (0 == position)
    {
        push_front(data);
    }
    else
    {
        if (nullptr != m_head)
        {
            Node* keyNode = m_head;
            for (int i = 1; (rezult || nullptr != keyNode) && i < position; i++)
            {
                if (nullptr == keyNode->mNext)
                {
                    rezult = false;
                }
                keyNode=keyNode->mNext;
            }
            if (nullptr != keyNode)
            {
                push_back(data);
                rezult = true;
                if (rezult)
                {
                    Node* node = new Node(data);
                    node->mNext=keyNode->mNext;
                    node->mPrev=keyNode;
                    keyNode->mNext->mPrev = node;
                    keyNode->mNext = node;
                }
            }
        }
        else
        {
            rezult = false;
        }
    }
    if (rezult) m_size++;
    return rezult;
}
template<class T>
Iterator<typename List<T>::Node, T> List<T>::begin()
{
    return Iterator<Node, T>(m_head);
}
template<class T>
Iterator<typename List<T>::Node, T> List<T>::end()
{
   return Iterator<Node, T>(nullptr);
}
template<class T>
Iterator<typename List<T>::Node, const T> List<T>::begin() const
{
    return Iterator<Node, const T> (m_head);
}
template<class T>
Iterator<typename List<T>::Node, const T> List<T>::end() const
{
   return Iterator<Node, const T>(nullptr);
}
template<class T>
inline const T& List<T>::front()
{
    return ((nullptr != m_head)? m_head->mValue: 0);
}
template<class T>
inline const T& List<T>::back()
{
    return ((nullptr != m_tail)? m_tail->mValue: 0);
}

template<class T>
void List<T>::clear()
{
    if (nullptr != m_head)
    while (nullptr != m_head->mNext)
    {
        pop_front();
    }
    pop_front();
}
template<class T>
SIZE List<T>::size()
{
	return m_size;
}
template<class T>
List<T>::~List()
{
    clear();
}
}
#endif
