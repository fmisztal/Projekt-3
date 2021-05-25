#include <iostream>
#include "container.h"
#include "Hearing_aid.h"

using namespace std;

/*Container<int*> testowy;
Container<int*> testowy1;

Container<Electronic_device*> electronic_devices;
Container<Electronic_device*> electronic_devices2;*/

Container<int> testowy;
Container<int> testowy1;

Container<Hearing_aid> electronic_devices;
Container<Hearing_aid> electronic_devices2;

Hearing_aid a("HerzMedical",3,2);
Hearing_aid b("?????",7,1);
Hearing_aid c("ABCDE",5,3);

void addObject()
{
    char choice;
    cout << "Which object: a, b or c do you want to add: " << endl;
    cin >> choice;
    if(choice=='a'){electronic_devices.addNew(a);}
    if(choice=='b'){electronic_devices.addNew(b);}
    if(choice=='c'){electronic_devices.addNew(c);}
    //kontrola błędów
    //else{cout << "There's no such object" << endl;}
}

void deleteObject()
{
    int choice;
    cout << "Currently container has " << electronic_devices.getNumber_of_elements() << " elements. Which one do you want to delete?" << endl;
    cin >> choice;
    //kontrola błędów
    electronic_devices.deleteElement(choice);
}

void swapObjects()
{
    int choice1, choice2;
    cout << "Select the objects you want to swap" << endl;
    cout << "Object 1: " << endl;
    cin >> choice1;
    cout << "Object 2: " << endl;
    cin >> choice2;
    //kontrola błędów
    electronic_devices.swap(choice1,choice2);
}

void addContainers()
{
    if(electronic_devices2.getNumber_of_elements()==0)
    {
        electronic_devices2.addNew(a);
        electronic_devices2.addNew(b);
        electronic_devices2.addNew(c);
    }
    electronic_devices+=electronic_devices2;
}

void searchObject()
{
    char choice;
    cout << "Which object would you like to check: a, b or c? " << endl;
    cin >> choice;
    if(choice=='a'){electronic_devices.contains(a);}
    if(choice=='b'){electronic_devices.contains(b);}
    if(choice=='c'){electronic_devices.contains(c);}
    //kontrola błędów;
}

void menu()
{
    char option;
    while(1)
    {
        cout << "1. Add object \n2. Delete object \n3. Swap objects \n4. Write the container \n5. Save the container" << endl;
        cout << "6. Read the container \n7. Add containers \n8. Check if the object is in the container \n9.Leave \n\n";
        cin >> option;
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
            electronic_devices.write();
        break;

        case '5':
            electronic_devices.save();
        break;

        case '6':
            electronic_devices.open();
        break;

        case '7':
            addContainers();
        break;

        case '8':
            searchObject();
        break;

        case '9':
            return;
        break;

        default:
        {
            system("cls");
            continue;
        }
        break;
        }
        system("PAUSE");
        system("cls");
    }
}

int main()
{
    int a1=11, b2=22, c3=33, d=44, e=55, f=66, g=77, h=88;

    a.parameters[0]->setName("Model");
    a.parameters[0]->setValue(13151);
    a.parameters[1]->setName("Number of overlays");
    a.parameters[1]->setValue(3);
    a.setProduction_year(2010);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(800);
    a.battery().setLifespan(100);



    b.parameters[0]->setName("NUMBER");
    b.parameters[0]->setValue(77777);
    b.setProduction_year(2999);
    b.user().setName("JA");
    b.user().setAge(20);
    b.user().setPesel(987654321);
    b.battery().setSize(1000);
    b.battery().setLifespan(500);


    c.parameters[0]->setName("abc");
    c.parameters[0]->setValue(111);
    c.parameters[1]->setName("def");
    c.parameters[1]->setValue(222);
    c.parameters[2]->setName("ghi");
    c.parameters[2]->setValue(333);
    c.setProduction_year(1999);
    c.user().setName("TY");
    c.user().setAge(25);
    c.user().setPesel(999999999);
    c.battery().setSize(900);
    c.battery().setLifespan(90);


    /*testowy.addNew(&a1);
    testowy.addNew(&b2);
    testowy.addNew(&c3);
    testowy.addNew(&d);
    testowy.addNew(&e);
    testowy.addNew(&f);
    testowy.addNew(&g);
    testowy.addNew(&h);

    electronic_devices.addNew(&a);
    electronic_devices.addNew(&b);
    electronic_devices.addNew(&c);

    testowy.write();
    testowy.swap(2,8);
    testowy.write();
    testowy.save();
    testowy1.open();
    //testowy1.write();

    electronic_devices.write();
    electronic_devices.save();
    //electronic_devices2.open();
    //electronic_devices2.write();*/



    /*testowy.addNew(a1);
    testowy.addNew(b2);
    testowy.addNew(c3);
    testowy.addNew(d);
    testowy.addNew(e);
    testowy.addNew(f);
    testowy.addNew(g);
    testowy.addNew(h);

    electronic_devices.addNew(a);
    electronic_devices.addNew(b);
    electronic_devices.addNew(c);

    testowy.write();
    testowy.swap(2,1);
    testowy.save();
    testowy1.open();
    testowy1.write();

    electronic_devices.write();
    electronic_devices.swap(2,1);
    electronic_devices.save();
    electronic_devices2.open();
    electronic_devices2.write();*/

    menu();

    return 0;
}
