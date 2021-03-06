#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::fill ; using std::fill_n;

#include <numeric>
using std::accumulate;

#include <iterator>
using std::back_inserter;

#include <iostream>
using std::cin ; using std::cout ; using std::endl;

int main()
{
    vector<int> vec(10);
    fill(vec.begin(), vec.end(), 1);

    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum << endl;

    fill(vec.begin(), vec.begin() + vec.size()/2 , 10);
    cout <<  accumulate(vec.begin(), vec.end(), 0) << endl;

    fill_n(vec.begin(), vec.size()/2 , 0);
    cout << accumulate(vec.begin(), vec.end(),0 ) << endl;


    fill_n(back_inserter(vec), 10, 42);
    cout << accumulate(vec.begin(), vec.end(), 0) << endl;

/*
    vector<string> v;
    string s;
    while (cin >> s)
    {
        v.push_back(s);
    }
    string concat = accumulate(v.cbegin(), v.cend(), string("") );

    cout << concat << endl;
 */   
    return 0;
}