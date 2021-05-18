#include <iostream>
#include "container.h"

using namespace std;

Container testowy;

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

    testowy.write();
    testowy.swap(8,1);
    testowy.write();

    return 0;
}
