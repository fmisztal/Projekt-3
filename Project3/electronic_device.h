#ifndef ELECTRONIC_DEVICE_H
#define ELECTRONIC_DEVICE_H
#include "battery.h"
#include "user.h"

///Klasa abstrakcyjna Electronic_device
class Electronic_device{
public:
    ///Konstruktor domyślny z parametrem domyślnym
    /**
    \param production_year=0 rok produkcji
    */
    Electronic_device(const int production_year=0);

    ///Konstruktor kopiujący
    /**
    \param &e kopiowany obiekt Electronic_device
    */
    Electronic_device(const Electronic_device &e);

    ///Destruktor klasy Electronic_device
    virtual ~Electronic_device();

    ///Pobieranie ilości obiektów typu Electronic_device
    /**
    \return zwraca ilość obiektów
    */
    static int eleQuantity();

    ///Operator ++
    /** zwiększa wartość pola lifespan podobiektu Baterry o 5
    */
    void operator++();

    ///Operator ++
    /** zmniejsza wartość pola lifespan podobiektu Baterry o 5
    */
    void operator--();

    ///Wypisanie danych właściciela danego obiektu
    /** Metoda wirtualna wypisująca typ obiektu i dane jego urzytkownika
    */
    virtual void ownership()=0;

    ///Wypisanie obiektu
    /** Metoda wirtualna wypisująca dany obiekt
    */
    virtual void draw()=0;

    ///Zapisywanie obiektu
    /** Metoda wirtualna zapisująca dany obiekt w bazie danych
    */
    virtual void save()=0;

    ///Odczytywanie obiektu
    /** Metoda wirtualna odczytująca wartości danego obiektu z bazy danych
    */
    virtual void open()=0;

    ///Pobieranie podobiektu User
    /**
    \return zwraca referencję do podobiektu typu User
    */
    User& user();

    ///Ustawianie podobiektu User
    /**
    \param &user podobiekt typu User
    */
    void setUser(const User &user);

    ///Pobieranie roku produkcji
    /**
    \return zwraca rok produkcji
    */
    int production_year() const;

    ///Ustawianie roku produkcji
    /**
    \param production_year ustawia rok produkcji
    */
    void setProduction_year(int production_year);

    ///Pobieranie podobiektu Battery
    /**
    \return zwraca referencję do podobiektu typu Battery
    */
    Battery& battery();

    ///Ustawianie podobiektu Battery
    /**
    \param &user podobiekt typu Battery
    */
    void setBattery(const Battery &b);

protected:
    Battery m_battery; ///< podobiekt bateria
    User m_user; ///< podobiekt użytkownik
    int m_production_year; ///< rok produkcji
    static int number_of_objects; ///< ilość obiektów typu Electronic_device
};

///Operator <<
/** Operator wypisujący pola obiektu na strumień
\param &e wypisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<(ostream &ost, Electronic_device &e);

///Operator <<=
/** Operator wypisujący pola obiektu do bazy danych
\param &e zapisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<=(ostream &ost, Electronic_device &e);

///Operator >>
/** Operator przypisuje polom danego obiektu wartości ze strumienia
\param &e opisywany obiekt
\param &ist strumień
\return zwraca strumień
*/
istream& operator>>(istream &ist, Electronic_device &e);

#endif // ELECTRONIC_DEVICE_H
