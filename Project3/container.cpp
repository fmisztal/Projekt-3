#pragma once
#include <iostream>
#include <fstream>
#include "container.h"

using namespace std;

template<class T>
Container<T>::Container()
{
    #ifdef _DEBUG
        cout << "Container()" << endl;
    #endif

    first=NULL;
    last=NULL;
    number_of_elements=0;
}

template<class T>
Container<T>::~Container()
{
    #ifdef _DEBUG
        cout << "~Container()" << endl;
    #endif

    Element<T> *temp;
    while(first)
    {
        temp=first;
        first=first->getNext();
        free(temp);
    }
    last=first;
    number_of_elements=0;
}

template<class T>
Element<T> *Container<T>::getFirst() const
{
    return first;
}

template<class T>
void Container<T>::setFirst(Element<T> *value)
{
    first = value;
}

template<class T>
Element<T> *Container<T>::getLast() const
{
    return last;
}

template<class T>
void Container<T>::setLast(Element<T> *value)
{
    last = value;
}

template<class T>
int Container<T>::getNumber_of_elements() const
{
    return number_of_elements;
}

template<class T>
void Container<T>::setNumber_of_elements(int value)
{
    number_of_elements = value;
}

template<class T>
void Container<T>::addNew(T new_object)
{
    Element<T> *temp;
    if(number_of_elements==0)
    {
        first=new Element<T>;
        last=first;
        number_of_elements=1;
        temp=first;
        temp->setObject(new_object);
        temp->setPosition(1);
        temp->setNext(NULL);
        temp->setPrev(NULL);
    }
    else
    {
        temp=last;
        temp->setNext(new Element<T>);
        temp->getNext()->setPrev(temp);
        temp=temp->getNext();
        temp->setPosition(temp->getPrev()->getPosition());
        temp->setPosition(temp->getPosition()+1);
        temp->setNext(NULL);
        temp->setObject(new_object);
        last=temp;
        number_of_elements++;
    }
}

template<class T>
void Container<T>::write()
{
    if(number_of_elements==0 || (first==NULL && last==NULL))
        cout << "Lista jest pusta" << endl;
    else
    {
        Element<T> *temp=first;
        do
        {
            cout << temp->getPosition() << ". " << temp->getObject() << endl;
            temp=temp->getNext();
        }while(temp);
        cout << "Lista ma " << number_of_elements << " elementow" << endl;
    }
}

template<class T>
void Container<T>::swap(int one, int two)
{
    Element<T> *temp=first;
    if(one>two)
    {
        int t=one;
        one=two;
        two=t;
    }
    if(one==two)
        cout << "Wybrales dwa razy ten sam obiekt" << endl;
    if(two>number_of_elements)
        cout << "Podany element nie istnieje" << endl;
    while(temp)
    {
        Element<T> *temp1, *temp2;
        if(temp->getPosition()==one)
            temp1=temp;
        if(temp->getPosition()==two)
        {
            if(one==1 && two!=number_of_elements)
            {
                first=temp;
                temp->getNext()->setPrev(temp1);
            }

            if(one!=1 && two==number_of_elements)
            {
                last=temp1;
                temp1->getPrev()->setNext(temp);
            }

            if(one==1 && two==number_of_elements)
            {
                last=temp1;
                first=temp;
            }

            if(one!=1 && two!=number_of_elements)
            {
                temp1->getPrev()->setNext(temp);
                temp->getNext()->setPrev(temp1);
            }

            temp->getPrev()->setNext(temp1);
            temp1->getNext()->setPrev(temp);

            temp2=temp->getNext();
            temp->setNext(temp1->getNext());
            temp1->setNext(temp2);

            temp2=temp->getPrev();
            temp->setPrev(temp1->getPrev());
            temp1->setPrev(temp2);

            int tempposition=temp->getPosition();
            temp->setPosition(temp1->getPosition());
            temp1->setPosition(tempposition);

            break;
        }
        temp=temp->getNext();
    }
}

template<class T>
void Container<T>::deleteElement(int number)
{
    Element<T> *temp=first;

    if(number>number_of_elements)
    {
        cout << "Nie ma takiego elementu" << endl;
        return;
    }

    if(number==1)
    {
        first->getNext()->setPrev(NULL);
        temp=first->getNext();
        delete first;
        first=temp;
        number_of_elements--;
        while(temp)
        {
            temp->setPosition(temp->getPosition()-1);
            temp=temp->getNext();
        }
        return;
    }

    if(number==number_of_elements)
    {
        temp=last;
        last->getPrev()->setNext(NULL);
        temp=last->getPrev();
        delete last;
        last=temp;
        number_of_elements--;
        return;
    }

    while(temp)
    {
        if(temp->getPosition()==number)
        {
            delete temp;
            number_of_elements--;
            return;
        }
        temp=temp->getNext();
    }
}

template<class T>
void Container<T>::save()
{
    ofstream ofs;
    ofs.open("file.txt", ios_base::out);
    if(!ofs.good())
    {
        cout << "Couldn't open the database" << endl;
        return;
    }
    Element<T> *temp=first;
    while(temp)
    {
        ofs << temp->getObject() << endl;
        temp=temp->getNext();
    }

    ofs.close();
}

template<class T>
void Container<T>::open()
{
    ifstream ifs;
    ifs.open("file.txt", ios_base::in);
    if(!ifs.good())
    {
        cout << "Couldn't open the database" << endl;
        return;
    }

    while(ifs)
    {
        int tempdana;
        ifs >> tempdana;
        if(!ifs)
            break;
        addNew(tempdana);
    }

    ifs.close();
}
