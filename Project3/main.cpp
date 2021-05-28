#include <iostream>
#include "container.h"
#include "Hearing_aid.h"
#include "phone.h"
#include "smartphone.h"

using namespace std;


Container<Hearing_aid> hearingaids;
Container<Phone> phones;
Container<Smartphone> smartphones;


void checkInt(int &i)
{
    string data;
    cin >> data;
    int length=data.size();
    for(int j=0; j<length; j++)
    {
        if(!isdigit(data[j]))
        {
            cout << "Invalid data type" << endl;
            i=0;
            return;
        }
    }
    i=atoi(data.c_str());
}

void checkLength(char &i)
{
    string data;
    cin >> data;
    int length=data.size();
    if(length>1)
    {
        i=0;
        return;
    }
    i=data[0];
}

template<class T>
void addElectronic_device(T &a)
{
    string name;
    int int1,int2;
    cout << "Enter the username, age and pesel: ";
    cin >> name;
    checkInt(int1);
    checkInt(int2);
    a.user().setName(name);
    a.user().setAge(int1);
    a.user().setPesel(int2);

    cout << "Set year of production: ";
    checkInt(int1);
    a.setProduction_year(int1);

    cout << "Enter the size and lifespan of battery: ";
    checkInt(int1);
    checkInt(int2);
    a.battery().setSize(int1);
    a.battery().setLifespan(int2);
}

void addPhone()
{
    string name;
    int int1, int2;
    bool sim;
    cout << endl << "Enter the name, processor and dual_sim (0 or 1): ";
    cin >> name;
    checkInt(int1);
    checkInt(int2);
    if(int2==1)
        sim=true;
    else
        sim=false;
    Phone a(name,int1,sim);

    addElectronic_device(a);

    phones.addNew(a);
}

void addSmartphone()
{
    string name;
    bool sim;
    int int1, int2;
    int int3, int4, int5;
    cout << endl << "Enter the name, processor, dual_sim (0 or 1), inches, weight and megapiksels: ";
    checkInt(int1);
    checkInt(int2);
    checkInt(int3);
    checkInt(int4);
    checkInt(int5);
    if(int2==1)
        sim=true;
    else
        sim=false;
    Smartphone a(int3,int4,int5,name,int1,sim);

    addElectronic_device(a);

    smartphones.addNew(a);
}

void addHearingaid()
{
    string name;
    int int1, int2;
    cout << endl << "Enter the name, amplification and number of parameters: ";
    cin >> name;
    checkInt(int1);
    checkInt(int2);
    Hearing_aid a(name,int1,int2);

    for(int i=0; i<int2; i++)
    {
        cout << "Provide a name and value for the " << i << " parameter: ";
        cin >> name;
        checkInt(int1);
        a.parameters[i]->setName(name);
        a.parameters[i]->setValue(int1);
    }

    addElectronic_device(a);

    hearingaids.addNew(a);
}

void addObject()
{
    int int1;
    cout << "Which object do you want to add: 1-Hearing aid, 2-Phone, 3-Smartphone: ";
    checkInt(int1);
    if(int1==1) addHearingaid();
    if(int1==2) addPhone();
    if(int1==3) addSmartphone();
}

void deleteObject()
{
    int int1, int2;
    cout << "Which object do you want to delete: 1-Hearing aid, 2-Phone, 3-Smartphone: ";
    checkInt(int1);
    cout << "Choose number of the element you want to delete: ";
    checkInt(int2);

    if(int1==1)
        try{hearingaids.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{phones.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{smartphones.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void swapObjects()
{
    int int1, int2, int3;
    cout << "Which object do you want to swap: 1-Hearing aid, 2-Phone, 3-Smartphone: ";
    checkInt(int1);
    cout << "Select the objects you want to swap: ";
    checkInt(int2);
    checkInt(int3);

    if(int1==1)
        try{hearingaids.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{phones.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{smartphones.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void writeContainer()
{
    int int1;
    cout << "Which container do you want to write: 1-Hearing aid, 2-Phone, 3-Smartphone: ";
    checkInt(int1);

    if(int1==1)
    {
        try{hearingaids.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
    if(int1==2)
    {
        try{phones.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
    if(int1==3)
    {
        try{smartphones.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
}

void saveContainer()
{
    int int1;
    cout << "Which container do you want to save: 1-Hearing aid, 2-Phone, 3-Smartphone: ";
    checkInt(int1);

    if(int1==1)
        try{hearingaids.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{phones.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{smartphones.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void openContainer()
{
    int int1;
    cout << "Which container do you want to save: 1-Hearing aid, 2-Phone, 3-Smartphone: ";
    checkInt(int1);

    if(int1==1)
        try{hearingaids.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{phones.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{smartphones.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void menu()
{
    char option;
    while(1)
    {
        cout << "1. Add object \n2. Delete object \n3. Swap objects \n4. Write the container " << endl;
        cout << "5. Save the container \n6. Read the container \n7. Leave \n\n";
        checkLength(option);
        switch(option)
        {
        case '1':
            addObject();
        break;

        case '2':
            deleteObject();
        break;

        case '3':
            swapObjects();
        break;

        case '4':
            writeContainer();
        break;

        case '5':
            saveContainer();
        break;

        case '6':
            openContainer();
        break;

        case '7':
            return;
        break;

        default:
        {
            system("cls");
            continue;
        }
        break;
        }

        system("cls");
    }
}


int main()
{
    menu();

    return 0;
}
