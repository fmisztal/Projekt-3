#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <iostream>
#include <cstring>

using namespace std;

///Podobiekt klasy Hearing_aid
class Parameter{
public:
    ///Konstruktor domyślny z parametrami domyślnymi
    /**
    \param name="" nazwa
    \param value=0 wartość
    */
    Parameter(const string name="", const int value=0);

    ///Konstruktor kopiujący
    /**
    \param &p kopiowany obiekt Parameter
    */
    Parameter(const Parameter &p);

    ///Destruktor klasy Parameter
    ~Parameter();

    ///Pobieranie ilości obiektów typu Battery
    /**
    \return zwraca ilość obiektów
    */
    static int parQuantity();

    ///Operator ==
    /** Operator porównujący ze sobą dwa obiekty typu Parameter
    \param &p obiekt porównywany
    \return zwraca true lub false
    */
    bool operator==(const Parameter &p);

    ///Pobieranie nazwy
    /**
    \return zwraca nazwę obiektu
    */
    string name();

    ///Ustawianie nazwy
    /**
    \param &name nazwa obiektu
    */
    void setName(const string &name);

    ///Pobieranie wartości parametru
    /**
    \return zwraca wartość parametru
    */
    int value();

    ///Ustawianie wartości parametru
    /**
    \param value wartość
    */
    void setValue(int value);

protected:
    string m_name; ///< nazwa
    int m_value; ///< wartość
    static int number_of_objects; ///< ilość obiektów typu Parameter
};

///Operator <<
/** Operator wypisujący pola obiektu na strumień
\param &p wypisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<(ostream &ost, Parameter &p);

///Operator <<=
/** Operator wypisujący pola obiektu do bazy danych
\param &p zapisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<=(ostream &ost, Parameter &p);

#endif // PARAMETERS_H
