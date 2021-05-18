#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

///Podobiekt klasy Electronic_device
class User{
public:
    ///Konstruktor domyślny z parametrami domyślnymi
    /**
    \param name="" nazwa użytkownika
    \param age=0 wiek użytkownika
    \param pesel=0 pesel uzytkownika
    */
    User(string name="", const int age=0, const int pesel=0);

    ///Konstruktor kopiujący
    /**
    \param &u kopiowany obiekt User
    */
    User(const User &u);

    ///Destruktor klasy User
    ~User();

    ///Pobieranie ilości obiektów typu User
    /**
    \return zwraca ilość obiektów
    */
    static int userQuantity();

    ///Operator =
    /** Operator kopiuje drugi obiekt typu User
    \param &u obiekt kopiowany
    \return zwraca kopię obiektu u
    */
    User& operator=(const User &u);

    ///Operator ==
    /** Operator porównujący ze sobą dwa obiekty typu User
    \param &u obiekt porównywany
    \return zwraca true lub false
    */
    bool operator==(const User &u);

    ///Pobieranie nazwy
    /**
    \return zwraca nazwę obiektu
    */
    string name() const;

    ///Ustawianie nazwy
    /**
    \param &name nazwa obiektu
    */
    void setName(const string &name);

    ///Pobieranie wieku
    /**
    \return zwraca wiek użytkownika
    */
    int age() const;

    ///Ustawianie wieku
    /**
    \param age wiek użytkownika
    */
    void setAge(int age);

    ///Pobieranie peselu
    /**
    \return zwraca pesel użytkownika
    */
    int pesel() const;

    ///Ustawianie peselu
    /**
    \param pesel pesel użytkownika
    */
    void setPesel(int pesel);

private:
    string m_name; ///< imię
    int m_age; ///< wiek
    int m_pesel; ///< pesel
    static int number_of_objects; ///< ilość obiektów typu User
};

///Operator <<
/** Operator wypisujący pola obiektu na strumień
\param &u wypisywany obiekt
\param &s strumień
\return zwraca strumień
*/
ostream& operator<<(ostream &s, User &u);

///Operator <<=
/** Operator wypisujący pola obiektu do bazy danych
\param &u zapisywany obiekt
\param &s strumień
\return zwraca strumień
*/
ostream& operator<<=(ostream &s, User &u);

///Operator >>
/** Operator przypisuje polom danego obiektu wartości ze strumienia
\param &u opisywany obiekt
\param &is strumień
\return zwraca strumień
*/
istream& operator>>(istream &is, User &u);

#endif // USER_H
