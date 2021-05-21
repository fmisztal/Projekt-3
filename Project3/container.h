#ifndef CONTAINER_H
#define CONTAINER_H
#include "element.h"

template<class T>
class Container
{
public:
    Container();
    ~Container();

    Element <T>*getFirst() const;
    void setFirst(Element<T> *value);

    Element<T> *getLast() const;
    void setLast(Element<T> *value);

    int getNumber_of_elements() const;
    void setNumber_of_elements(int value);

    void addNew(T new_object);
    void write();
    void swap(int one, int two);
    void deleteElement(int number);
    void save();
    void open();

private:
    Element <T>*first;
    Element <T>*last;
    int number_of_elements;
};

#endif // CONTAINER_H
