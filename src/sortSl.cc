#include <algorithm>
using std::sort;

#include <vector>
using std::vector;

#include <iostream>
using std::cout ; using std::cin; using std::endl;

#include "../include/Sales_item.h"

int main()
{
    Sales_item trans;
    vector<Sales_item> file;

    while(std::cin >> trans)
    {
        file.push_back(trans);
    }

    for(auto i : file)
    {
        cout << i << endl;
    }
    cout << "\n\n";

    sort(file.begin(), file.end(),compareIsbn);
    for(auto i : file)
    {
        cout << i << endl;
    }
    
    return 0;
}