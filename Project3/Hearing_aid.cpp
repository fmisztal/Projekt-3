#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Hearing_aid.h"
#include "electronic_device.h"

using namespace std;

int Hearing_aid::number_of_objects=0;

Hearing_aid::Hearing_aid(const string name, const double amplification_x, const int number_of_parameters)
{
    number_of_objects++;

    m_name=name;
    m_amplification_x=amplification_x;
    m_number_of_parameters=number_of_parameters;

    for(int i=0; i<number_of_parameters; i++)
    {
        Parameter *a = new Parameter;
        parameters.push_back(a);
    }
};

Hearing_aid::Hearing_aid(const Hearing_aid &h)
{
    number_of_objects++;

    m_name=h.m_name;
    m_amplification_x=h.m_amplification_x;
    m_number_of_parameters=h.m_number_of_parameters;

    setProduction_year(h.production_year());

    m_battery.setSize(h.m_battery.size());
    m_battery.setLifespan(h.m_battery.lifespan());

    m_user.setAge(h.m_user.age());
    m_user.setPesel(h.m_user.pesel());
    m_user.setName(h.m_user.name());

    for(int i=0; i<m_number_of_parameters; i++)
    {
        Parameter *temp = new Parameter;
        temp->setName(h.parameters[i]->name());
        temp->setValue(h.parameters[i]->value());
        parameters.push_back(temp);
    }
};

Hearing_aid::~Hearing_aid()
{
    number_of_objects--;

    deleteVector();
};

int Hearing_aid::objQuantity()
{
    return number_of_objects;
};

void Hearing_aid::deleteVector()
{
    while(parameters.size()!=0)
    {
        delete *(--parameters.end());
        parameters.pop_back();
    }
    parameters.clear();
}

Hearing_aid& Hearing_aid::operator=(Hearing_aid &h)
{
    m_name=h.m_name;
    m_amplification_x=h.m_amplification_x;
    m_number_of_parameters=h.m_number_of_parameters;

    setProduction_year(h.production_year());
    setBattery(h.battery());
    setUser(h.user());

    if(parameters.size()!=0)
        deleteVector();

    if(h.number_of_parameters()!=0)
    {
        for(int i=0; i<number_of_parameters(); i++)
        {
            Parameter *temp = new Parameter;
            temp->setName(h.parameters[i]->name());
            temp->setValue(h.parameters[i]->value());
            parameters.push_back(temp);
        }
    }

    return *this;
};

bool Hearing_aid::operator==(const Hearing_aid &h)
{
    if(m_battery==h.m_battery && m_user==h.m_user && m_production_year==h.m_production_year && m_name==h.m_name && m_amplification_x==h.m_amplification_x)
        if(m_number_of_parameters==h.m_number_of_parameters)
        {
            int x=0;
            for(int i=0; i<m_number_of_parameters; i++)
                if(*parameters[i]==*h.parameters[i])
                    x++;
            if(x==m_number_of_parameters)
                return true;
        }
    return false;
};

void Hearing_aid::ownership()
{
    cout << "This HEARING AID belongs to " << m_user << endl;
}

/*ostream& operator<<(ostream &os, Hearing_aid &h)
{
    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(&h);
    os << *ctpr;

    os << h.name() << endl;
    os << h.amplification_x() << " , " << h.number_of_parameters() << endl;
    if(h.number_of_parameters()!=0)
        for(int i=0; i<h.number_of_parameters(); i++)
            os << *(h.parameters[i]);
    return os;
}*/

ostream& operator<<(ostream &os, Hearing_aid h)
{
    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(&h);
    os << *ctpr;

    os << h.name() << endl;
    os << h.amplification_x() << " , " << h.number_of_parameters() << endl;
    if(h.number_of_parameters()!=0)
        for(int i=0; i<h.number_of_parameters(); i++)
            os << *(h.parameters[i]);
    return os;
}

istream& operator>>(istream &is, Hearing_aid &h)
{
    string temp, name, par_name, username;
    char sign;
    int amplification, number_of_parameters, par_value;

    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(&h);
    is >> *ctpr;

    getline(is, temp);
    getline(is, name);
    h.setName(name);
    is >> amplification >> sign >> number_of_parameters;
    h.setAmplification_x(amplification);
    h.setNumber_of_parameters(number_of_parameters);

    h.deleteVector();
    getline(is, temp);
    cout << temp;

    for(int i=0; i<number_of_parameters; i++)
    {
        getline(is, par_name);
        is >> par_value;
        getline(is, temp);
        Parameter *temporary = new Parameter;
        temporary->setName(par_name);
        temporary->setValue(par_value);
        h.parameters.push_back(temporary);
    }

    return is;
}

Hearing_aid::operator string()
{
    return "Current sound amplification: " + to_string(m_amplification_x);
};

string Hearing_aid::name() const
{
    return m_name;
}

void Hearing_aid::setName(const string &name)
{
    m_name = name;
}

int Hearing_aid::number_of_parameters() const
{
    return m_number_of_parameters;
}

void Hearing_aid::setNumber_of_parameters(int number_of_parameters)
{
    m_number_of_parameters = number_of_parameters;
}

double Hearing_aid::amplification_x() const
{
    return m_amplification_x;
}

void Hearing_aid::setAmplification_x(double amplification_x)
{
    m_amplification_x = amplification_x;
}

void operator|=(double x, Hearing_aid &h)
{
    h.setAmplification_x(x);
};

void Hearing_aid::draw()
{
    cout << "-----------HEARING_AID-----------" << endl;
    Electronic_device *ctpr;
    ctpr=dynamic_cast<Electronic_device*>(this);
    cout <<= *ctpr;
    cout << "Name: " << name() << " , Amplification: " << amplification_x() << endl;
    if(number_of_parameters()!=0)
    {
        cout << "Number of parameters- " << number_of_parameters() << " : ";
        for(int i=0; i<number_of_parameters(); i++)
        {
            if(i!=0 && i<number_of_parameters())
                cout << " , ";
            cout <<= *(parameters[i]);
        }
        cout << endl;
    }
}

void Hearing_aid::save()
{ 
    ofstream ofs;
    ofs.open("file.txt", ios_base::out);
    if(!ofs.good())
    {
        cout << "Couldn't open the database" << endl;
        return;
    }

    ofs << "-----------HEARING_AID-----------" << endl;
    ofs << *this;

    ofs.close();
}

void Hearing_aid::open()
{
    ifstream ifs;
    ifs.open("file.txt", ios_base::in);
    if(!ifs.good())
    {
        cout << "Couldn't open the database" << endl;
        return;
    }
    string temp;
    getline(ifs, temp);
    while(temp!="-----------HEARING_AID-----------")
    {
        getline(ifs, temp);
        if(temp=="")
        {
            cout << "Couldn't find this kind of object in database" << endl;
            return;
        }
    }

    ifs >> *this;

    ifs.close();
}











