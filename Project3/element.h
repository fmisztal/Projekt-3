#ifndef ELEMENT_H
#define ELEMENT_H
#include <iostream>

using namespace std;

template<class T>
class Element
{
public:
    ~Element()
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
    };

    Element<T> *getNext() const
    {
        return next;
    };

    void setNext(Element<T> *value)
    {
        next = value;
    };

    Element<T> *getPrev() const
    {
        return prev;
    };

    void setPrev(Element<T> *value)
    {
        prev = value;
    };

    int getPosition() const
    {
        return position;
    };

    void setPosition(int value)
    {
        position = value;
    };

    T getObject() const
    {
        return object;
    };

    void setObject(T &value)
    {
        object = value;
    };

private:
    Element <T>*next;
    Element <T>*prev;
    int position;
    T object;
};

#endif // ELEMENT_H
