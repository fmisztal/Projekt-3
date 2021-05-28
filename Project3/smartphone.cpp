#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "smartphone.h"
#include "phone.h"
#include "electronic_device.h"

int Smartphone::number_of_objects=0;

Smartphone::Smartphone(const int inches, const int weight, const int megapiksels, const string brand, const int processor, const bool dual_sim)
{
    number_of_objects++;

    m_inches=inches;
    m_weight=weight;
    m_megapiksels=megapiksels;
    m_brand=brand;
    m_processor=processor;
    m_dual_sim=dual_sim;
}

Smartphone::Smartphone(const Smartphone &s)
{
    number_of_objects++;

    setProduction_year(s.production_year());

    m_battery.setSize(s.m_battery.size());
    m_battery.setLifespan(s.m_battery.lifespan());

    m_user.setAge(s.m_user.age());
    m_user.setPesel(s.m_user.pesel());
    m_user.setName(s.m_user.name());

    m_inches=s.inches();
    m_weight=s.weight();
    m_megapiksels=s.megapiksels();
    m_brand=s.brand();
    m_processor=s.processor();
    m_dual_sim=s.dual_sim();
}

Smartphone::~Smartphone()
{
    number_of_objects--;
}

int Smartphone::smartphoneQuantity()
{
    return number_of_objects;
}

Smartphone& Smartphone::operator=(const Smartphone &s)
{
    setProduction_year(s.production_year());

    m_battery.setSize(s.m_battery.size());
    m_battery.setLifespan(s.m_battery.lifespan());

    m_user.setAge(s.m_user.age());
    m_user.setPesel(s.m_user.pesel());
    m_user.setName(s.m_user.name());

    m_inches=s.inches();
    m_weight=s.weight();
    m_megapiksels=s.megapiksels();
    m_brand=s.brand();
    m_processor=s.processor();
    m_dual_sim=s.dual_sim();
    return *this;
}

bool Smartphone::operator==(const Smartphone &s)
{
    return m_battery==s.m_battery && m_user==s.m_user && m_brand==s.m_brand && m_processor==s.m_processor &&
            m_dual_sim==s.m_dual_sim && m_inches==s.m_inches && m_weight==s.m_weight && m_megapiksels==s.m_megapiksels;
}

void Smartphone::ownership()
{
    cout << "This SMARTPHONE belongs to " << m_user << endl;
}

int Smartphone::inches() const
{
    return m_inches;
}

void Smartphone::setInches(int inches)
{
    m_inches = inches;
}

int Smartphone::weight() const
{
    return m_weight;
}

void Smartphone::setWeight(int weight)
{
    m_weight = weight;
}

int Smartphone::megapiksels() const
{
    return m_megapiksels;
}

void Smartphone::setMegapiksels(int megapiksels)
{
    m_megapiksels = megapiksels;
}

/*ostream& operator<<(ostream &ost, Smartphone &s)
{
    return ost << "Inches- " << s.inches() << " , weight- " << s.weight() << " , megapiksels- " << s.megapiksels() << endl;
}*/

ostream& operator<<(ostream &ost, Smartphone s)
{
    Phone *ctpr1;
    ctpr1=dynamic_cast<Phone*>(&s);
    ost << *ctpr1;

    return ost << s.inches() << " , " << s.weight() << " , " << s.megapiksels() << endl;
}

ostream& operator<<=(ostream &ost, Smartphone &s)
{
    return ost << s.inches() << " , " << s.weight() << " , " << s.megapiksels() << endl;
}

istream& operator>>(istream &is, Smartphone &s)
{
    string temp;
    char sign;
    int inches, weight, megapiksels;

    Phone *ctpr1;
    ctpr1=dynamic_cast<Phone*>(&s);
    is >> *ctpr1;

    is >> inches >> sign >> weight >> sign >> megapiksels;

    s.setInches(inches);
    s.setMegapiksels(megapiksels);
    s.setWeight(weight);

    return is;
}

void Smartphone::draw()
{
    #ifdef _DEBUG
        cout << "draw() [S]" << endl;
    #endif

    cout << "-----------SMARTPHONE-----------" << endl;
    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(this);
    cout << *ctpr;
    Phone *ctpr1;
    ctpr1=dynamic_cast<Phone*>(this);
    cout << *ctpr1;
    cout << this;
}

void Smartphone::save()
{
    #ifdef _DEBUG
        cout << "save() [S]" << endl;
    #endif

    ofstream ofs;
    ofs.open("file.txt", ios_base::out);
    if(!ofs.good())
    {
        cout << "Couldn't open the database" << endl;
        return;
    }

    ofs << "-----------SMARTPHONE-----------" << endl;

    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(this);
    ofs <<= *ctpr;
    Phone *ctpr1;
    ctpr1=dynamic_cast<Phone*>(this);
    ofs <<= *ctpr1;
    ofs <<= *this;

    ofs.close();
}

void Smartphone::open()
{
    #ifdef _DEBUG
        cout << "open() [S]" << endl;
    #endif

    ifstream ifs;
    ifs.open("file.txt", ios_base::in);
    if(!ifs.good())
    {
        cout << "Couldn't open the database" << endl;
        return;
    }
    string temp;
    getline(ifs, temp);
    while(temp!="-----------SMARTPHONE-----------")
    {
        getline(ifs, temp);
        if(temp=="")
        {
            cout << "Couldn't find this kind of object in database" << endl;
            return;
        }
    }

    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(this);
    ifs >> *ctpr;
    Phone *ctpr1;
    ctpr1=dynamic_cast<Phone*>(this);
    ifs >> *ctpr1;
    ifs >> *this;

    ifs.close();
}







