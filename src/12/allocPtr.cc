#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::istream; using std::ostream;
using std::cin; using std::cout ; using std::endl;

#include "Foo.h"

Foo *factory(T arg)
{
    return new Foo(arg);
}

Foo *use_factory(T arg)
{
    Foo *p = factory(arg);
    print(cout , *p);
    cout << endl;
    return p;
}

int main()
{
    T arg ;
    while (cin >> arg)
    {
        /* code */
        auto p = use_factory(arg);
        delete p;
    }

    return 0;
    
}