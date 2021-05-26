#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <fstream>
#include "element.h"

using namespace std;

template<class T>
class Container
{
public:
    Container()
    {
        first=NULL;
        last=NULL;
        number_of_elements=0;
    };

    ~Container()
    {
        Element<T> *temp;
        while(first)
        {
            temp=first;
            first=first->getNext();
            free(temp);
        }
        last=first;
        number_of_elements=0;
    };

    Element <T>*getFirst() const
    {
        return first;
    };

    void setFirst(Element<T> *value)
    {
        first = value;
    };

    Element<T> *getLast() const
    {
        return last;
    };

    void setLast(Element<T> *value)
    {
        last = value;
    };

    int getNumber_of_elements() const
    {
        return number_of_elements;
    };

    void setNumber_of_elements(int value)
    {
        number_of_elements = value;
    };

    void addNew(T new_object)
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
    };

    void write()
    {
        if(number_of_elements==0 || (first==NULL && last==NULL))
            throw string("The container is empty");
        else
        {
            Element<T> *temp=first;
            do
            {
                cout << temp->getPosition() << ". ";
                cout << temp->getObject() << endl;
                temp=temp->getNext();
            }while(temp);
            cout << "The container has " << number_of_elements << " elements" << endl << endl;
        }
    };

    void swap(int one, int two)
    {
        Element<T> *temp=first;
        if(one>two)
        {
            int t=one;
            one=two;
            two=t;
        }
        if(one==two)
            throw string("You chose the same object twice");
        if(two>number_of_elements)
            throw string("Selected object doesn't exist");
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
    };

    void deleteElement(int number)
    {
        Element<T> *temp=first;

        if(number>number_of_elements || number==0)
            throw string("There's no such element");

        if(number==1)
        {
            if(number_of_elements==1)
            {
                first=NULL;
                last=NULL;
                number_of_elements=0;
                return;
            }

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
    };

    void save()
    {
        if(!first)
            throw string("The container is empty");
        ofstream ofs;
        ofs.open("file.txt", ios_base::out);
        if(!ofs.good())
            throw string("Couldn't open the database");
        Element<T> *temp=first;
        while(temp)
        {
            ofs << temp->getObject() << endl;
            temp=temp->getNext();
        }

        ofs.close();
    };

    void open()
    {
        ifstream ifs;
        ifs.open("file.txt", ios_base::in);
        if(!ifs.good())
        {
            throw string("Couldn't open the database");
            return;
        }

        Element<T> *temp;
        while(first)
        {
            temp=first;
            first=first->getNext();
            free(temp);
        }
        last=first;
        number_of_elements=0;

        while(ifs)
        {
            T tempdana;
            ifs >> tempdana;
            if(!ifs)
                break;
            addNew(tempdana);
        }

        ifs.close();
    };

    Container& operator=(const Container &c)
    {
        Element<T> *temp;
        if(first)
        {
            while(first)
            {
                temp=first;
                first=first->getNext();
                free(temp);
            }
            last=first;
            number_of_elements=0;
        }

        temp=c.getFirst();
        while(temp)
        {
            addNew(temp->getObject());
            temp=temp->getNext();
        }

        return *this;
    };

    bool operator==(const Container &c)
    {
        if(number_of_elements==c.getNumber_of_elements())
        {
            Element<T> *temp1, *temp2;
            temp1=first;
            temp2=c.getFirst();
            while(temp1 && temp2)
            {
                if(temp1->getObject()!=temp2->getObject())
                    return false;
                temp1=temp1->getNext();
                temp2=temp2->getNext();
            }
            return true;
        }
        return false;
    };

    void operator+=(const Container &c)
    {
        Element<T> *temp;
        temp=c.getFirst();
        while(temp)
        {
            addNew(temp->getObject());
            temp=temp->getNext();
        }
    }

    bool contains(T &t)
    {
        Element<T> *temp;
        temp=first;
        while(temp)
        {
            if(temp->getObject()==t)
                return true;
            temp=temp->getNext();
        }
        return false;
    };

private:
    Element <T>*first;
    Element <T>*last;
    int number_of_elements;
};

#endif // CONTAINER_H

