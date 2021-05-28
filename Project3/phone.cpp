#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "phone.h"
#include "electronic_device.h"

int Phone::number_of_objects=0;

Phone::Phone(string brand, const int processor, const bool dual_sim)
{
    number_of_objects++;

    m_brand=brand;
    m_processor=processor;
    m_dual_sim=dual_sim;
}

Phone::Phone(const Phone &p)
{
    number_of_objects++;

    setProduction_year(p.production_year());

    m_battery.setSize(p.m_battery.size());
    m_battery.setLifespan(p.m_battery.lifespan());

    m_user.setAge(p.m_user.age());
    m_user.setPesel(p.m_user.pesel());
    m_user.setName(p.m_user.name());

    m_brand=p.brand();
    m_processor=p.processor();
    m_dual_sim=p.dual_sim();
}

Phone::~Phone()
{
    number_of_objects--;
}

int Phone::phoneQuantity()
{
    return number_of_objects;
};

Phone& Phone::operator=(const Phone &p)
{
    setProduction_year(p.production_year());

    m_battery.setSize(p.m_battery.size());
    m_battery.setLifespan(p.m_battery.lifespan());

    m_user.setAge(p.m_user.age());
    m_user.setPesel(p.m_user.pesel());
    m_user.setName(p.m_user.name());

    m_brand=p.brand();
    m_processor=p.processor();
    m_dual_sim=p.dual_sim();
    return *this;
}

bool Phone::operator==(const Phone &p)
{
    return m_battery==p.m_battery && m_user==p.m_user && m_brand==p.m_brand && m_processor==p.m_processor && m_dual_sim==p.m_dual_sim;
}

void Phone::ownership()
{
    cout << "This PHONE belongs to " << m_user << endl;
}

string Phone::brand() const
{
    return m_brand;
}

void Phone::setBrand(const string &brand)
{
    m_brand = brand;
}

int Phone::processor() const
{
    return m_processor;
}

void Phone::setProcessor(int processor)
{
    m_processor = processor;
}

bool Phone::dual_sim() const
{
    return m_dual_sim;
}

void Phone::setDual_sim(bool dual_sim)
{
    m_dual_sim = dual_sim;
}

/*ostream& operator<<(ostream &ost, Phone &p)
{
    return ost << "Brand- " << p.brand() << " , processor- " << p.processor() << " , dual sim- " << p.dual_sim() << endl;
};*/


ostream& operator<<=(ostream &ost, Phone &p)
{
    ost << p.brand() << endl;
    return ost << p.processor() << " , " << p.dual_sim() << endl;;
}

ostream& operator<<(ostream &ost, Phone p)
{
    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(&p);
    ost << *ctpr;
    ost << p.brand() << endl;
    return ost << p.processor() << " , " << p.dual_sim() << endl;;
}

istream& operator>>(istream &is, Phone &p)
{
    string temp, brand;
    char sign;
    bool dual_sim;
    int processor;

    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(&p);
    is >> *ctpr;

    getline(is, temp);
    getline(is, brand);
    is >> processor >> sign >> dual_sim;
    p.setBrand(brand);
    p.setDual_sim(dual_sim);
    p.setProcessor(processor);

    return is;
}

void Phone::draw()
{
    #ifdef _DEBUG
        cout << "draw() [P]" << endl;
    #endif

    cout << "-----------PHONE-----------" << endl;
    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(this);
    cout << *ctpr;
    cout << *this;
}

void Phone::save()
{
    #ifdef _DEBUG
        cout << "save() [P]" << endl;
    #endif

    ofstream ofs;
    ofs.open("file.txt", ios_base::out);
    if(!ofs.good())
    {
        cout << "Couldn't open the database" << endl;
        return;
    }

    ofs << "-----------PHONE-----------" << endl;

    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(this);
    ofs <<= *ctpr;
    ofs <<= *this;

    ofs.close();
}

void Phone::open()
{
    #ifdef _DEBUG
        cout << "open() [P]" << endl;
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
    while(temp!="-----------PHONE-----------")
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
    ifs >> *this;

    ifs.close();
}




