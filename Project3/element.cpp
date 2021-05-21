#pragma once
#include <iostream>
#include "element.h"

using namespace std;

template<class T>
Element<T>::~Element()
{
    #ifdef _DEBUG
        cout << "~Element()" << endl;
    #endif

    if(prev && next)
    {
        prev->setNext(next);
        next->setPrev(prev);
        Element *temp=this->next;
        while(temp)
        {
            temp->setPosition(temp->getPosition()-1);
            temp=temp->getNext();
        }
    }
}

template<class T>
Element<T> *Element<T>::getNext() const
{
    return next;
}

template<class T>
void Element<T>::setNext(Element<T> *value)
{
    next = value;
}

template<class T>
Element<T> *Element<T>::getPrev() const
{
    return prev;
}

template<class T>
void Element<T>::setPrev(Element<T> *value)
{
    prev = value;
}

template<class T>
int Element<T>::getPosition() const
{
    return position;
}

template<class T>
void Element<T>::setPosition(int value)
{
    position = value;
}

template<class T>
T Element<T>::getObject() const
{
    return object;
}

template<class T>
void Element<T>::setObject(const T &value)
{
    object = value;
}




