#pragma once
#include <iostream>
#include "element.h"

using namespace std;

Element::~Element()
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

Element *Element::getNext() const
{
    return next;
}

void Element::setNext(Element *value)
{
    next = value;
}

Element *Element::getPrev() const
{
    return prev;
}

void Element::setPrev(Element *value)
{
    prev = value;
}

int Element::getPosition() const
{
    return position;
}

void Element::setPosition(int value)
{
    position = value;
}

int Element::getObject() const
{
    return object;
}

void Element::setObject(int value)
{
    object = value;
}

