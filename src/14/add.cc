#include <iostream>
using std::cin; using std::cout ; using std::endl;

#include "../../include/Sales_data.h"
#include "Sales_item.h"

int main()
{
    Sales_item item1, item2;

    cin >> item1 >> item2;

    cout << item1 + item2 << endl;

    Sales_data data1 , data2;
    read(read(cin,data1), data2);
    print(cout , add(data1, data2));
    cout << std::endl;

    cin >> data1 >> data2;
    cout << data1 + data2 << endl;

    return 0;


}