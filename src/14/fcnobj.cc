#include <functional>
using std::plus; using std::negate;
using std::function;  using std::placeholders::_1;
using std::bind; using std::less_equal;

#include <iostream>
using std::cout ; using std::endl;

#include <algorithm>
using  std::count_if;

#include <vector>
using  std::vector;

#include <iostream>
using std::cin;

#include <string>
using std::string;

bool size_compare(const string &s , string::size_type sz)
{
    return s.size() >= sz;
}

int main()
{
    cout << plus<int>()(3,4) << endl; //输出7

    plus<int> intAdd;
    negate<int> intNegate;

    int sum = intAdd(10,20);
    cout << sum << endl;

    sum = intNegate(intAdd(10,20));
    cout << sum << endl;

    sum = intAdd(10, intNegate(10));
    cout << sum << endl;

    vector<int> vec = { 0, 1,2,3,4,5,16,17,18,19};

    // bind second arfument to less_equal
    cout << count_if(vec.begin(), vec.end(), 
                        bind(less_equal<int>(), _1, 10));
    
    cout << endl;


    vector<string> svec;
    string in;
    while (cin >> in)
    {
        /* code */
        svec.push_back(in);
    }
    
    // decltype(fp1)::result_type ret;
    function<decltype(size_compare)>  fp1 = size_compare;

    function<bool(const string&)> fp2 = bind(size_compare, _1 , 6);
    cout << count_if(svec.begin(), svec.end(), fp2) << endl;
    cout << count_if(svec.begin(), svec.end(), bind(size_compare, _1,6)) << endl;

    return 0;



}