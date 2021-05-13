#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout ; using std::endl;

int main()
{
    string s = "some string", s2 = "some other string";

    s.insert(s.begin(), s2.begin() , s2.end());
    cout << "insert iterators version:         " << s << endl;

    s = "some string";
    s.insert(0, s2);
    cout << "insert string at given poostin:    " << s << endl;

    s = "some string";
    s.insert(0,s2,2,s2.size());
    cout << "insert iterators version:          " << s << endl;

    s = "";
    vector<char> c_vec(1,'a');
    s.insert(s.begin() , c_vec.begin(), c_vec.end());
    s.insert(s.size(), 5, '!');
    cout << s << endl;

    s.erase(s.size() -5 , 5);
    cout << s << endl;


    s  = "C++ Primer";
    s2 = s;
    s.insert(s.size() , " 4th Ed.");
    s2.append(" 4th Ed.");
    cout << s << "   " << s2 << endl;


    return 0;

}