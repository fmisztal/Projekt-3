#include <iostream>
#include "container.h"
#include "Hearing_aid.h"

using namespace std;

Container<int> testowy;
Container<int> testowy1;

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

    return 0;
}
