#ifndef CONTAINER_H
#define CONTAINER_H
#include "element.h"

class Container
{
public:
    Container();
    ~Container();

    Element *getFirst() const;
    void setFirst(Element *value);

    Element *getLast() const;
    void setLast(Element *value);

    int getNumber_of_elements() const;
    void setNumber_of_elements(int value);

    void addNew(int nowa_dana);
    void write();
    void swap(int one, int two);
    void deleteElement(int number);
    void save();
    void open();

private:
    Element *first;
    Element *last;
    int number_of_elements;
};

#endif // CONTAINER_H
