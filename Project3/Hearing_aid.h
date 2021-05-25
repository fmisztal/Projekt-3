#ifndef HEARING_AID_H
#define HEARING_AID_H
#include "battery.h"
#include "parameters.h"
#include "electronic_device.h"
#include "vector"

using namespace std;

///Klasa Hearing_aid dziedzicząca po klasie Electronic_device
class Hearing_aid : public Electronic_device{
public:
    ///Konstruktor domyślny z parametrami domyślnymi
    /**
    \param name="" nazwa obiektu
    \param amplification_x=0 amplifikacja
    \param number_of_patrameters=0 liczba parametrów
    */
    Hearing_aid(const string name="", const double amplification_x=0, const int number_of_patrameters=0);

    ///Konstruktor kopiujący
    /**
    \param &h kopiowany obiekt hearing_aid
    */
    Hearing_aid(const Hearing_aid &h);

    ///Destruktor klasy Hearing_aid
    ~Hearing_aid();

    ///Pobieranie ilości obiektów typu Hearing_aid
    /**
    \return zwraca ilość obiektów
    */
    static int objQuantity();

    ///Usuwanie wektora z parametrami
    /** Metoda kasuje wszystkie podobiekty dynamiczne Parameter i czyści wektor
    */
    void deleteVector();

    ///Wypisanie danych właściciela obiektu Hearing_aid
    /** Metoda wirtualna wypisująca dane urzytkownika obiektu Hearing_aid
    */
    virtual void ownership();

    ///Wypisanie obiektu
    /** Metoda wirtualna wypisująca obiekt Hearing_aid
    */
    virtual void draw();

    ///Zapisywanie obiektu
    /** Metoda wirtualna zapisująca obiekt Hearing_aid w bazie danych
    */
    virtual void save();

    ///Odczytywanie obiektu
    /** Metoda wirtualna odczytująca wartości obiektu Hearing_aid z bazy danych
    */
    virtual void open();

    ///Operator =
    /** Operator kopiuje drugi obiekt typu Hearing_aid
    \param &h obiekt kopiowany
    \return zwraca kopię obiektu h
    */
    Hearing_aid& operator=(Hearing_aid &h);

    ///Operator ==
    /** Operator porównujący ze sobą dwa obiekty typu Hearing_aid
    \param &h obiekt porównywany
    \return zwraca true lub false
    */
    bool operator==(const Hearing_aid &h);

    ///Operator string()
    /** Operator rzutujący amplifikację na typ string
    \return zwraca amplifikację wraz z dodatkowym tekstem
    */
    operator string();

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

    ///Pobieranie liczby parametrów
    /**
    \return zwraca ilość parametrów znajdujących się w obiekcie
    */
    int number_of_parameters() const;

    ///Ustawianie liczby parametrów
    /**
    \param number_of_parameters ilość parametrów
    */
    void setNumber_of_parameters(int number_of_parameters);

    ///Pobieranie amplifikacji
    /**
    \return zwraca wartość amplifikacji
    */
    double amplification_x() const;

    ///Ustawianie amplifikacji
    /**
    \param amplification_x wartosć amplifikacji
    */
    void setAmplification_x(double amplification_x);

    vector<Parameter*> parameters; ///< wektor podobiektów dynamicznych typu Parameter

private:
    string m_name; ///< nazwa obiektu
    int m_number_of_parameters; ///< liczba parametrów
    double m_amplification_x; ///< wartość amplifikacji
    static int number_of_objects; ///< ilość obiektów typu Hearing_aid
};

///Operator <<
/** Operator wypisujący pola obiektu na strumień
\param &h wypisywany obiekt
\param &os strumień
\return zwraca strumień
*/
//ostream& operator<<(ostream &os, Hearing_aid &h);
ostream& operator<<(ostream &os, Hearing_aid h);

///Operator <<=
/** Operator wypisujący pola obiektu do bazy danych
\param &h zapisywany obiekt
\param &os strumień
\return zwraca strumień
*/
ostream& operator<<=(ostream &os, Hearing_aid &h);

///Operator >>
/** Operator przypisuje polom danego obiektu wartości ze strumienia
\param &h opisywany obiekt
\param &is strumień
\return zwraca strumień
*/
istream& operator>>(istream &is, Hearing_aid &h);

///Operator |=
/** Operator przypisuje polom danego obiektu wartości ze strumienia
\param x nowa wartość amplifikacji
\param &h obiekt ze zmienianą amplifikacją
*/
void operator|=(double x, Hearing_aid &h);

#endif // HEARING_AID_H


