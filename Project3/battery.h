#ifndef BATTERY_H
#define BATTERY_H
#include <iostream>

using namespace std;

///Podobiekt klasy Electronic_device
class Battery{
public:
    ///Konstruktor domyślny z parametrami domyślnymi
    /**
    \param size=0 pojemność
    \param lifespan=0 długość czasu pracy
    */
    Battery(const int size=0, const int lifespan=0);

    ///Konstruktor kopiujący
    /**
    \param &b kopiowany obiekt Bateria
    */
    Battery(const Battery &b);

    ///Destruktor klasy Bateria
    ~Battery();

    ///Pobieranie ilości obiektów typu Battery
    /**
    \return zwraca ilość obiektów
    */
    static int batQuantity();

    ///Operator =
    /** Operator kopiuje drugi obiekt typu Battery
    \param &b obiekt kopiowany
    \return zwraca kopię obiektu b
    */
    Battery& operator=(const Battery &b);

    ///Operator ==
    /** Operator porównujący ze sobą dwa obiekty typu Battery
    \param &b obiekt porównywany
    \return zwraca true lub false
    */
    bool operator==(const Battery &b);

    ///Pobieranie wartości size
    /**
    \return zwraca wartość size
    */
    int size() const;

    ///Ustawianie wartości size
    /**
    \param size wartość size
    */
    void setSize(int size);

    ///Pobieranie wartości lifespan
    /**
    \return zwraca wartość lifespan
    */
    int lifespan() const;

    ///Ustawianie wartości lifespan
    /**
    \param lifespan wartość lifespan
    */
    void setLifespan(int lifespan);

private:
    int m_size; ///< rozmiar pojemności baterii
    int m_lifespan; ///< długość czasu pracy baterii
    static int number_of_objects; ///<ilość obiektów typu Battery
};

///Operator <<
/** Operator wypisujący pola obiektu na strumień
\param &b wypisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<(ostream &ost, Battery &b);

///Operator <<=
/** Operator wypisujący pola obiektu do bazy danych
\param &b zapisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<=(ostream &ost, Battery &b);

///Operator >>
/** Operator przypisuje polom danego obiektu wartości ze strumienia
\param &b opisywany obiekt
\param &is strumień
\return zwraca strumień
*/
istream& operator>>(istream &is, Battery &b);

#endif // BATTERY_H
