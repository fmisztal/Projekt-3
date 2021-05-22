#pragma once
#include <iostream>
#include <cstring>
#include "parameters.h"

using namespace std;

int Parameter::number_of_objects=0;

Parameter::Parameter(const string name, const int value)
{
    number_of_objects++;

    m_name=name;
    m_value=value;
};

Parameter::Parameter(const Parameter &p)
{
    number_of_objects++;

    m_name=p.m_name;
    m_value=p.m_value;
}

Parameter::~Parameter()
{
    number_of_objects--;
};

int Parameter::parQuantity()
{
    return number_of_objects;
};

bool Parameter::operator==(const Parameter &p)
{
    return m_name==p.m_name && m_value==p.m_value;
}

string Parameter::name()
{
    return m_name;
}

void Parameter::setName(const string &name)
{
    m_name = name;
}

int Parameter::value()
{
    return m_value;
}

void Parameter::setValue(int value)
{
    m_value = value;
};

ostream& operator<<=(ostream &ost, Parameter &p)
{
    if(p.name()=="")
        return ost << "";

    if(p.value()==0)
        return ost << p.name();

    return ost << p.name() << " - " << p.value();
};

ostream& operator<<(ostream &ost, Parameter &p)
{
    return ost << p.name() << endl << p.value() << endl;
}







