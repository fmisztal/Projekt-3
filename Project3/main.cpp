#include <iostream>
#include "container.h"
#include "Hearing_aid.h"

using namespace std;

//Container<int> testowy;
//Container<int> testowy1;

Container<Electronic_device*> electronic_devices;
Container<Electronic_device*> electronic_devices2;

int main()
{
    /*int a1=11, b2=22, c3=33, d=44, e=55, f=66, g=77, h=88;

    testowy.addNew(a1);
    testowy.addNew(b2);
    testowy.addNew(c3);
    testowy.addNew(d);
    testowy.addNew(e);
    testowy.addNew(f);
    testowy.addNew(g);
    testowy.addNew(h);

    //testowy1=testowy;

    testowy.write();
    testowy.swap(2,8);
    testowy.write();

    testowy.write();
    testowy.save();
    testowy1.open();
    testowy1.write();

    testowy1.write();*/

    Hearing_aid a("HerzMedical",3,2);
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

    Hearing_aid b("?????",7,1);
    b.parameters[0]->setName("NUMBER");
    b.parameters[0]->setValue(77777);
    b.setProduction_year(2999);
    b.user().setName("JA");
    b.user().setAge(20);
    b.user().setPesel(987654321);
    b.battery().setSize(1000);
    b.battery().setLifespan(500);

    Hearing_aid c("ABCDE",5,3);
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

    electronic_devices.addNew(&a);
    electronic_devices.addNew(&b);
    electronic_devices.addNew(&c);

    electronic_devices.write();
    electronic_devices.save();
    //electronic_devices2.open();
    //electronic_devices2.write();

    return 0;
}
