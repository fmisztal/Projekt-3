#ifndef ELEMENT_H
#define ELEMENT_H

template<class T>
class Element
{
public:
    //Element();
    ~Element();

    Element<T> *getNext() const;
    void setNext(Element<T> *value);

    Element<T> *getPrev() const;
    void setPrev(Element<T> *value);

    int getPosition() const;
    void setPosition(int value);

    T getObject() const;
    void setObject(const T &value);

private:
    Element <T>*next;
    Element <T>*prev;
    int position;
    T object;
};


#endif // ELEMENT_H
