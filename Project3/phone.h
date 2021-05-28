#ifndef PHONE_H
#define PHONE_H
#include "electronic_device.h"

///Klasa Phone dziedzicząca po klasie Electronic_device
class Phone : public Electronic_device{
public:
    ///Konstruktor domyślny z parametrami domyślnym
    /**
    \param brand="" marka
    \param processor=0 procesor
    \param dual_sim=false czy posiada dual sim
    */
    Phone(string brand="", const int processor=0, const bool dual_sim=false);

    ///Konstruktor kopiujący
    /**
    \param &p kopiowany obiekt Phone
    */
    Phone(const Phone &p);

    ///Destruktor klasy Phone
    ~Phone();

    ///Operator =
    /** Operator kopiuje drugi obiekt typu Phone
    \param &p obiekt kopiowany
    \return zwraca kopię obiektu p
    */
    Phone& operator=(const Phone &p);

    ///Operator ==
    /** Operator porównujący ze sobą dwa obiekty typu Phone
    \param &p obiekt porównywany
    \return zwraca true lub false
    */
    bool operator==(const Phone &p);

    ///Pobieranie ilości obiektów typu Phone
    /**
    \return zwraca ilość obiektów
    */
    static int phoneQuantity();

    ///Wypisanie danych właściciela obiektu Phone
    /** Metoda wirtualna wypisująca dane urzytkownika obiektu Phone
    */
    virtual void ownership();

    ///Wypisanie obiektu
    /** Metoda wirtualna wypisująca obiekt Phone
    */
    virtual void draw();

    ///Zapisywanie obiektu
    /** Metoda wirtualna zapisująca obiekt Phone w bazie danych
    */
    virtual void save();

    ///Odczytywanie obiektu
    /** Metoda wirtualna odczytująca wartości obiektu Phone z bazy danych
    */
    virtual void open();

    ///Pobieranie nazwy marki
    /**
    \return zwraca markę obiektu
    */
    string brand() const;

    ///Ustawianie marki
    /**
    \param &brand marka obiektu
    */
    void setBrand(const string &brand);

    ///Pobieranie wartości procesora
    /**
    \return zwraca wartość procesora obiektu
    */
    int processor() const;

    ///Ustawianie wartości procesora
    /**
    \param processor wartość procesora
    */
    void setProcessor(int processor);

    ///Pobieranie stanu dual sim
    /**
    \return zwraca informację czy obiekt posiada dual sim
    */
    bool dual_sim() const;

    ///Ustawianie stanu dual sim
    /**
    \param dual_sim stan dual sim
    */
    void setDual_sim(bool dual_sim);

protected:
    string m_brand; ///< marka
    int m_processor; ///< procesor
    bool m_dual_sim; ///< czy posiada dual sim
    static int number_of_objects; ///< ilość obiektów typu Phone
};

///Operator <<
/** Operator wypisujący pola obiektu na strumień
\param &p wypisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
//ostream& operator<<(ostream &ost, Phone &p);
ostream& operator<<(ostream &ost, Phone p);

///Operator <<=
/** Operator wypisujący pola obiektu do bazy danych
\param &p zapisywany obiekt
\param &ost strumień
\return zwraca strumień
*/
ostream& operator<<=(ostream &ost, Phone &p);

///Operator >>
/** Operator przypisuje polom danego obiektu wartości ze strumienia
\param &p opisywany obiekt
\param &is strumień
\return zwraca strumień
*/
istream& operator>>(istream &is, Phone &p);

#endif // PHONE_H
