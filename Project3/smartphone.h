#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "phone.h"

///Klasa Smartphone dziedzicząca po klasie Phone
class Smartphone : public Phone{
public:
    ///Konstruktor domyślny z parametrami domyślnym
    /**
    \param inches=0 przekątna ekranu
    \param weight=0 waga
    \param megapiksels=0 ilość megapikseli
    \param brand="" marka
    \param processor=0 procesor
    \param dual_sim=false czy posiada dual sim
    */
    Smartphone(const int inches=0, const int weight=0, const int megapiksels=0, const string brand="", const int processor=0, const bool dual_sim=false);

    ///Konstruktor kopiujący
    /**
    \param &p kopiowany obiekt Smartphone
    */
    Smartphone(const Smartphone &s);

    ///Destruktor klasy Smartphone
    ~Smartphone();

    ///Operator =
    /** Operator kopiuje drugi obiekt typu Smartphone
    \param &s obiekt kopiowany
    \return zwraca kopię obiektu s
    */
    Smartphone& operator=(const Smartphone &s);

    ///Operator ==
    /** Operator porównujący ze sobą dwa obiekty typu Smartphone
    \param &s obiekt porównywany
    \return zwraca true lub false
    */
    bool operator==(const Smartphone &s);

    ///Pobieranie ilości obiektów typu Smartphone
    /**
    \return zwraca ilość obiektów
    */
    static int smartphoneQuantity();

    ///Wypisanie danych właściciela obiektu Smartphone
    /** Metoda wirtualna wypisująca dane urzytkownika obiektu Smartphone
    */
    virtual void ownership();

    ///Wypisanie obiektu
    /** Metoda wirtualna wypisująca obiekt Smartphone
    */
    virtual void draw();

    ///Zapisywanie obiektu
    /** Metoda wirtualna zapisująca obiekt Smartphone w bazie danych
    */
    virtual void save();

    ///Odczytywanie obiektu
    /** Metoda wirtualna odczytująca wartości obiektu Smartphone z bazy danych
    */
    virtual void open();

    ///Pobieranie ilości cali
    /**
    \return zwraca przekątną ekranu obiektu
    */
    int inches() const;

    ///Ustawianie ilości cali
    /**
    \param inches ilość cali
    */
    void setInches(int inches);

    ///Pobieranie wagi
    /**
    \return zwraca wagę obiektu
    */
    int weight() const;

    ///Ustawianie wagi
    /**
    \param weight waga obiektu
    */
    void setWeight(int weight);

    ///Pobieranie ilości megapikseli
    /**
    \return zwraca ilość megapikseli
    */
    int megapiksels() const;

    ///Ustawianie ilości megapikseli
    /**
    \param megapiksels ilość megapikseli
    */
    void setMegapiksels(int megapiksels);

private:
    int m_megapiksels; ///< megapiksele
    int m_inches; ///< cale
    int m_weight; ///< waga
    static int number_of_objects; ///< ilość obiektów typu Smartphone
};

///Operator <<
/** Operator wypisujący pola obiektu na strumień
\param &s wypisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
//ostream& operator<<(ostream &ost, Smartphone &s);
ostream& operator<<(ostream &ost, Smartphone s);

///Operator <<=
/** Operator wypisujący pola obiektu do bazy danych
\param &s zapisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<=(ostream &ost, Smartphone &s);

///Operator >>
/** Operator przypisuje polom danego obiektu wartości ze strumienia
\param &s opisywany obiekt
\param &is strumień
\return zwraca strumień
*/
istream& operator>>(istream &is, Smartphone &s);

#endif // SMARTPHONE_H
