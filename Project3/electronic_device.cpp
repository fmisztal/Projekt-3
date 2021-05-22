#pragma once
#include <fstream>
#include "electronic_device.h"

int Electronic_device::number_of_objects=0;

Electronic_device::Electronic_device(const int production_year)
{
    number_of_objects++;

    m_production_year=production_year;
}

Electronic_device::Electronic_device(const Electronic_device &e)
{
    number_of_objects++;

    m_production_year=e.production_year();
    m_battery=battery();
    m_user=user();
}

Electronic_device::~Electronic_device()
{
    number_of_objects--;
}

int Electronic_device::eleQuantity()
{
    return number_of_objects;
};

int Electronic_device::production_year() const
{
    return m_production_year;
}

void Electronic_device::setProduction_year(int production_year)
{
    m_production_year = production_year;
}

Battery &Electronic_device::battery()
{
    return m_battery;
}

void Electronic_device::setBattery(const Battery &b)
{
    m_battery = b;
}

User &Electronic_device::user()
{
    return m_user;
}

void Electronic_device::setUser(const User &user)
{
    m_user = user;
}

void Electronic_device::operator++()
{
    int x=m_battery.lifespan()+5;
    m_battery.setLifespan(x);
};

void Electronic_device::operator--()
{
    int x=m_battery.lifespan()-5;
    m_battery.setLifespan(x);
}

istream &operator>>(istream &is, Electronic_device &e)
{
    string temp;
    int year;
    is >> year >> e.battery();
    e.setProduction_year(year);
    getline(is, temp);
    is >> e.user();
    return is;
}

ostream& operator<<=(ostream &ost, Electronic_device &e)
{
    ost << "Production year: " << e.production_year() << endl;
    ost <<= e.battery();
    return ost <<= e.user();
}

ostream& operator<<(ostream &ost, Electronic_device &e)
{
    ost << e.production_year() << endl;
    ost << e.battery();
    return ost << e.user();
}





