#include <iostream>
#include "container.h"
#include "Hearing_aid.h"

using namespace std;


Container<Hearing_aid> electronic_devices;
Container<Hearing_aid> electronic_devices2;

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

void addObject()
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

    electronic_devices.addNew(a);
}

void deleteObject()
{
    int int1;
    cout << "Choose number of the element you want to delete: ";
    checkInt(int1);

    try{electronic_devices.deleteElement(int1);}
    catch(string s){cout << s << endl; system("PAUSE");}
}

void swapObjects()
{
    int int1, int2;
    cout << "Select the objects you want to swap: ";
    checkInt(int1);
    checkInt(int2);

    try{electronic_devices.swap(int1, int2);}
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
        {
            try{electronic_devices.write();}
            catch(string s){cout << s << endl;}
            system("PAUSE");
        }
        break;

        case '5':
            try{electronic_devices.save();}
            catch(string s){cout << s << endl; system("PAUSE");}
        break;

        case '6':
            try{electronic_devices.open();}
            catch(string s){cout << s << endl; system("PAUSE");}
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
