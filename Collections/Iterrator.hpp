/**********************************************************************
 *  Project        SeaBattle ( Gen20x )
 *  (c) copyright  2020
 *  Company        Luxoft
 *  All rights reserved
 **********************************************************************/
/**
 * @file    Itterator.hpp
 * @author  Kirieiev Ivan (ikirieiev@luxoft.com)
 * @brief   The Itterator for List
 */
#ifndef H_ITTERATOR
#define H_ITTERATOR
namespace Collections
{
template <class C, class T> 
class Iterator
{
    #ifdef H_LIST
	template <class P>
	friend class List;
    #endif
  private:
	Iterator(C *p);

  public:
	Iterator(const Iterator &it);

	bool operator!=(Iterator const &other) const;
	bool operator==(Iterator const &other) const;
	const T &operator*() const;
	Iterator &operator++();

  private:
	C *m_p;
};
template <class C, class T>
Iterator<C, T>::Iterator(C *p) : m_p(p) {}

template <class C, class T>
Iterator<C, T>::Iterator(const Iterator &it) : m_p(it.m_p) {}

template <class C, class T>
bool Iterator<C, T>::operator!=(Iterator const &other) const
{
	return m_p != other.m_p;
}

template <class C, class T>
bool Iterator<C, T>::operator==(Iterator const &other) const
{
	return m_p == other.m_p;
}

template <class C, class T>
const T &Iterator<C, T>::operator*() const
{
        return(*m_p).mValue;
}
template <class C, class T>
Iterator<C, T> &Iterator<C, T>::operator++()
{
        m_p = m_p->mNext;
	return *this;
}
}
#endif
