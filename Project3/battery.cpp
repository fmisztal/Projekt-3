#pragma once
#include <iostream>
#include "battery.h"

using namespace std;

int Battery::number_of_objects=0;

Battery::Battery(const int size, const int lifespan)
{
    number_of_objects++;

    m_size=size;
    m_lifespan=lifespan;
};

Battery::Battery(const Battery &b)
{
    number_of_objects++;

    m_size=b.size();
    m_lifespan=b.lifespan();
}

Battery::~Battery()
{
    number_of_objects--;
};

int Battery::batQuantity()
{
    return number_of_objects;
};

Battery& Battery::operator=(const Battery &b)
{
    m_size=b.size();
    m_lifespan=b.lifespan();
    return *this;
}

bool Battery::operator==(const Battery &b)
{
    return m_size==b.m_size && m_lifespan==b.m_lifespan;
}

ostream& operator<<=(ostream &ost, Battery &b)
{
    return ost << "Battery: size- " << b.size() << " , Lifespan- " << b.lifespan() << " hours" << endl;
};

ostream& operator<<(ostream &ost, Battery &b)
{
    return ost << b.size() << " , " << b.lifespan() << endl;
}

int Battery::size() const
{
    return m_size;
}

void Battery::setSize(int size)
{
    m_size = size;
}

int Battery::lifespan() const
{
    return m_lifespan;
}

void Battery::setLifespan(int lifespan)
{
    m_lifespan = lifespan;
}

istream& operator>>(istream &is, Battery &b)
{
    int size, lifespan;
    char sign;
    is >> size >> sign >> lifespan;
    b.setSize(size);
    b.setLifespan(lifespan);
    return is;
}









