#include <iostream>
#include "container.h"
#include "Hearing_aid.h"
#include "phone.h"
#include "smartphone.h"

using namespace std;

Container<int> inty;
Container<int> inty2;
Container<Hearing_aid> hearingaids;
Container<Hearing_aid> hearingaids2;
Container<Phone> phones;
Container<Phone> phones2;
Container<Smartphone> smartphones;
Container<Smartphone> smartphones2;


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

    cout << "Which container do you want to add to: 0- phones, 1- phones2: ";
    checkInt(int1);
    if(int1==0)
        phones.addNew(a);
    if(int1==1)
        phones2.addNew(a);
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

    cout << "Which container do you want to add to: 0- smartphones, 1- smartphones2: ";
    checkInt(int1);
    if(int1==0)
        smartphones.addNew(a);
    if(int1==1)
        smartphones2.addNew(a);
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

    cout << "Which container do you want to add to: 0- hearingaids, 1- hearingaids2: ";
    checkInt(int1);
    if(int1==0)
        hearingaids.addNew(a);
    if(int1==1)
        hearingaids2.addNew(a);
}

void addObject()
{
    system("cls");
    int int1;
    cout << "Which object do you want to add: 1-Hearing aid, 2-Phone, 3-Smartphone: ";
    checkInt(int1);
    system("cls");
    if(int1==1) addHearingaid();
    if(int1==2) addPhone();
    if(int1==3) addSmartphone();
}

void deleteObject()
{
    system("cls");
    int int1, int2;
    cout << "From which container do you want to delete: " << endl;
    cout << "1-hearingaids, 2-hearingaids2 " << endl;
    cout << "3-phones, 4-phones2 " << endl;
    cout << "5-smartphones, 6-smartphones2 " << endl;
    checkInt(int1);
    cout << "Choose number of the element you want to delete: ";
    checkInt(int2);

    if(int1==1)
        try{hearingaids.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{hearingaids2.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{phones.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==4)
        try{phones2.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==5)
        try{smartphones.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==6)
        try{smartphones2.deleteElement(int2);}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void swapObjects()
{
    system("cls");
    int int1, int2, int3;
    cout << "Which object do you want to swap: " << endl;
    cout << "1-hearingaids, 2-hearingaids2 " << endl;
    cout << "3-phones, 4-phones2 " << endl;
    cout << "5-smartphones, 6-smartphones2 " << endl;
    checkInt(int1);
    cout << "Select the objects you want to swap: ";
    checkInt(int2);
    checkInt(int3);

    if(int1==1)
        try{hearingaids.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{hearingaids2.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{phones.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==4)
        try{phones2.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==5)
        try{smartphones.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==6)
        try{smartphones2.swap(int2, int3);}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void writeContainer()
{
    system("cls");
    int int1;
    cout << "Which container do you want to write: " << endl;
    cout << "1-hearingaids, 2-hearingaids2 " << endl;
    cout << "3-phones, 4-phones2 " << endl;
    cout << "5-smartphones, 6-smartphones2 " << endl;
    checkInt(int1);

    if(int1==1)
    {
        try{hearingaids.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
    if(int1==2)
    {
        try{hearingaids2.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
    if(int1==3)
    {
        try{phones.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
    if(int1==4)
    {
        try{phones2.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
    if(int1==5)
    {
        try{smartphones.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
    if(int1==6)
    {
        try{smartphones2.write();}
        catch(string s){cout << s << endl;}
        system("PAUSE");
    }
}

void saveContainer()
{
    system("cls");
    int int1;
    cout << "Which container do you want to save: " << endl;
    cout << "1-hearingaids, 2-hearingaids2 " << endl;
    cout << "3-phones, 4-phones2 " << endl;
    cout << "5-smartphones, 6-smartphones2 " << endl;
    checkInt(int1);

    if(int1==1)
        try{hearingaids.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{hearingaids2.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{phones.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==4)
        try{phones2.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==5)
        try{smartphones.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==6)
        try{smartphones2.save();}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void openContainer()
{
    system("cls");
    int int1;
    cout << "Which container do you want to save: " << endl;
    cout << "1-hearingaids, 2-hearingaids2 " << endl;
    cout << "3-phones, 4-phones2 " << endl;
    cout << "5-smartphones, 6-smartphones2 " << endl;
    checkInt(int1);

    if(int1==1)
        try{hearingaids.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==2)
        try{hearingaids2.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==3)
        try{phones.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==4)
        try{phones2.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==5)
        try{smartphones.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
    if(int1==6)
        try{smartphones2.open();}
        catch(string s){cout << s << endl; system("PAUSE");}
}

void containsObject()
{
    system("cls");
    int int1, int2;
    cout << "Which type of object do you want to search for: " << endl;
    cout << "1-hearingaid, 2-phone, 3-smartphone: ";
    checkInt(int1);
    cout << "Select an object from container1 that you want to find in container2: " << endl;
    checkInt(int2);
    if(int1==1 && int1<=hearingaids.getNumber_of_elements())
    {
        if(hearingaids2.contains(hearingaids.getElement(int2)->getObject()))
            cout << "Object found" << endl;
        else
            cout << "Object not found" << endl;
    }
    if(int1==2 && int1<=phones.getNumber_of_elements())
    {
        if(phones2.contains(phones.getElement(int2)->getObject()))
            cout << "Object found" << endl;
        else
            cout << "Object not found" << endl;
    }
    if(int1==3 && int1<=smartphones.getNumber_of_elements())
    {
        if(smartphones2.contains(smartphones.getElement(int2)->getObject()))
            cout << "Object found" << endl;
        else
            cout << "Object not found" << endl;
    }
    system("PAUSE");
}

void checkEqual()
{
    system("cls");
    int int1;
    cout << "Which containers do you want to compare: 1-hearingaids, 2-phones, 3-smartphones" << endl;
    checkInt(int1);
    if(int1==1)
    {
        if(hearingaids==hearingaids2)
            cout << "Containers are equal" << endl;
        else
            cout << "Containers are not equal" << endl;
        system("PAUSE");
    }
    if(int1==2)
    {
        if(phones==phones2)
            cout << "Containers are equal" << endl;
        else
            cout << "Containers are not equal" << endl;
        system("PAUSE");
    }
    if(int1==3)
    {
        if(smartphones==smartphones2)
            cout << "Containers are equal" << endl;
        else
            cout << "Containers are not equal" << endl;
        system("PAUSE");
    }
}

void addContainers()
{
    system("cls");
    int int1;
    cout << "Which containers do you want to add: 1-hearingaids, 2-phones, 3-smartphones" << endl;
    checkInt(int1);
    if(int1==1)
        hearingaids+=hearingaids2;
    if(int1==2)
        phones+=phones2;
    if(int1==3)
        smartphones+=smartphones2;
}

void copyContainers()
{
    system("cls");
    int int1;
    cout << "Which containers do you want to copy: 1-hearingaids, 2-phones, 3-smartphones" << endl;
    checkInt(int1);
    if(int1==1)
        hearingaids=hearingaids2;
    if(int1==2)
        phones=phones2;
    if(int1==3)
        smartphones=smartphones2;
}

void menu()
{
    char option;
    while(1)
    {
        cout << "1. Add object \n2. Delete object \n3. Swap objects \n4. Write the container " << endl;
        cout << "5. Save the container \n6. Read the container \n7. Check if container contains the object " << endl;
        cout << "8. Check if containers are equal \n9. Add containers \n0. Copy containers" << endl;
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
            containsObject();
        break;

        case '8':
            checkEqual();
        break;

        case '9':
            addContainers();
        break;

        case '0':
            copyContainers();
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
