#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
public:
    //Element();
    ~Element();

    Element *getNext() const;
    void setNext(Element *value);

    Element *getPrev() const;
    void setPrev(Element *value);

    int getPosition() const;
    void setPosition(int value);

    int getObject() const;
    void setObject(int value);

private:
    Element *next;
    Element *prev;
    int position;
    int object;
};


#endif // ELEMENT_H
