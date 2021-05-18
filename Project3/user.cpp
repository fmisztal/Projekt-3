#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "battery.h"
#include "user.h"

using namespace std;

int User::number_of_objects=0;

User::User(string name, const int age, const int pesel)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "User(string, const int, const int) [" << number_of_objects << "]" << endl;
    #endif

    m_name=name;
    m_age=age;
    m_pesel=pesel;
}

User::User(const User &u)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "User(const User) [" << number_of_objects << "]" << endl;
    #endif

    m_name=u.name();
    m_age=u.age();
    m_pesel=u.pesel();
}

User::~User()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~User() [" << number_of_objects << "]" << endl;
    #endif
}

int User::userQuantity()
{
    return number_of_objects;
};

User& User::operator=(const User &u)
{
    m_name=u.name();
    m_age=u.age();
    m_pesel=u.pesel();
    return *this;
}

bool User::operator==(const User &u)
{
    return m_name==u.m_name && m_age==u.m_age && m_pesel==u.m_pesel;
}

string User::name() const
{
    return m_name;
}

void User::setName(const string &name)
{
    m_name = name;
}

int User::age() const
{
    return m_age;
}

void User::setAge(int age)
{
    m_age = age;
}

int User::pesel() const
{
    return m_pesel;
}

void User::setPesel(int pesel)
{
    m_pesel = pesel;
};

ostream& operator<<=(ostream &s, User &u)
{
    return s << "user: " << u.name() << " , " << u.age() << " , " << u.pesel() << endl;
}

ostream& operator<<(ostream &s, User &u)
{
    return s << u.name() << endl << u.age() << " , " << u.pesel() << endl;
}

istream& operator>>(istream &is, User &u)
{
    string name;
    int pesel, age;
    char sign;
    getline(is, name);
    is >> age >> sign >> pesel;
    u.setName(name);
    u.setAge(age);
    u.setPesel(pesel);
    return is;
}











