#include <iostream>
#include "container.h"
#include "Hearing_aid.h"

using namespace std;

Container testowy;
Container testowy1;

int main()
{
    int a=11, b=22, c=33, d=44, e=55, f=66, g=77, h=88;
    testowy.addNew(a);
    testowy.addNew(b);
    testowy.addNew(c);
    testowy.addNew(d);
    testowy.addNew(e);
    testowy.addNew(f);
    testowy.addNew(g);
    testowy.addNew(h);

    /*testowy.write();
    testowy.swap(2,8);
    testowy.write();*/

    testowy.write();
    testowy.save();
    testowy1.open();
    testowy1.write();

    /*Hearing_aid a("HerzMedical",3,2);
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

    Hearing_aid b;

    cout << endl << endl;
    a.save();
    b.open();
    b.draw();
    cout << endl << endl;*/

    return 0;
}
