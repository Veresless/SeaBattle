/**********************************************************************
 *  Project        SeaBattle ( Gen20x )
 *  (c) copyright  2020
 *  Company        Luxoft
 *  All rights reserved
 **********************************************************************/
/**
 * @file    Vector.hpp
 * @author  Kirieiev Ivan (ikirieiev@luxoft.com)
 * @brief   The Vector template class
 */

#ifndef H_VECTOR
#define H_VECTOR
namespace Collections
{
    typedef unsigned long long SIZE;
    #define VECTOR_DEFAULT_SIZE 100
    #define VECTOR_DEFAULT_EXTENDS 100
    template <class T>
    class Vector
    {
    public:
        Vector();
        Vector(const SIZE& size);
        Vector(const SIZE& size, const T * array);
        Vector(const Vector& vector);
        Vector(const Vector&& vector);
        Vector& operator = (const Vector& vector);
        T* begin();
        T* end();
        const T& operator [] (const SIZE& index);
        void push_back(const T& element);
        void push_front(const T& element);
        T& pop_back();
        T& pop_front();
        SIZE size();
        void fitSize();
        void clear();
        ~Vector();
    private:
        void resize();
        SIZE m_maxSize;
        SIZE m_size;
        T * m_array;
    };
    template<class T>
    Vector<T>::Vector():
        m_maxSize(VECTOR_DEFAULT_SIZE),
        m_size(0),
        m_array(new T(m_maxSize))
    {

    }
    template<class T>
    Vector<T>::Vector(const SIZE& size):
        m_maxSize(size + VECTOR_DEFAULT_EXTENDS),
        m_size(size),
        m_array(new T(m_maxSize))
    {

    }
    template<class T>
    Vector<T>::Vector(const SIZE& size, const T * array):
        m_maxSize(size + VECTOR_DEFAULT_EXTENDS),
        m_size(size),
        m_array(new T(m_maxSize))
    {
        for (int i = 0; i < size; i++)
        {
            m_array[i] = array[i];
        }
    }
    template<class T>
    Vector<T>::Vector(const Vector& vector):
        m_maxSize(vector.m_maxSize),
        m_size(vector.m_size),
        m_array(new T(m_maxSize))
    {
        for (int i = 0; i < m_size; i++)
        {
            m_array[i] = vector.m_array[i];
        }
    }
    template<class T>
    Vector<T>::Vector(const Vector&& vector):
        m_maxSize(vector.m_maxSize),
        m_size(vector.m_size),
        m_array(m_array)
    {
        vector.m_maxSize = VECTOR_DEFAULT_SIZE;
        vector.m_size = 0;
        vector.m_array = new T(vector.m_maxSize);
    }
    template<class T>
    T* Vector<T>::begin()
    {
        return m_array;
    }
    template<class T>
    T* Vector<T>::end()
    {
        return m_array + m_size;
    }
    template<class T>
    const T& Vector<T>::operator [] (const SIZE& index)
    {
        return m_array[index];
    }
    template<class T>
    void Vector<T>::push_back(const T& element)
    {
        if (m_maxSize == m_size) resize();
        m_array[m_size++] = element;
    }
    template<class T>
    void Vector<T>::push_front(const T& element)
    {
        if (m_maxSize == m_size) resize();
        for (int i = m_size++; i > 0; i--)
        {
            m_array[i] = m_array[i-1];
        }
        m_array[0] = element;
    }
    template<class T>
    T& Vector<T>::pop_back()
    {
        return m_array[--m_size];
    }
    template<class T>
    T& Vector<T>::pop_front()
    {
        T rezult = m_array[0];
        for (int i = 1; i < m_size; i++)
        {
            m_array[i-1] = m_array[i];
        }
        m_array[m_size-1] = rezult;
        return m_array[--m_size];
    }
    template<class T>
    SIZE Vector<T>::size()
    {
        return m_size;
    }
    template<class T>
    void Vector<T>::fitSize()
    {
        if (m_maxSize != m_size)
        {
            T * newArray = new T(m_size);
            for (int i = 0; i < m_size; i++)
            {
                newArray[i] = m_array[i];
            }
            delete m_array;
            m_array = newArray;
            m_maxSize = m_size;
        }
    }
    template<class T>
    void Vector<T>::clear()
    {
        m_size = 0;
    }
    template<class T>
    void Vector<T>::resize()
    {
        T * newArray = new T(m_maxSize + VECTOR_DEFAULT_EXTENDS);
        for (int i = 0; i < m_size; i++)
        {
            newArray[i] = m_array[i];
        }
        delete m_array;
        m_array = newArray;
        m_maxSize += VECTOR_DEFAULT_EXTENDS;
    }
    template<class T>
    Vector<T>::~Vector()
    {
        if (nullptr != m_array)
        delete m_array;
    }
}
#endif
