#include <iostream>
using std::cout ; using std::endl; using std::ostream;

#include <map>
using std::map;

#include <string>
using std::string;

#include <functional>
using std::bind; using std::function;
using namespace std::placeholders;


int add(int i, int j) { return  i + j;}

auto mod = [](int i , int j){ return i % j;};

struct divide {
    int operator()(int deniminator , int divisor)
    {
        return deniminator/divisor;
    }
    
};

int main()
{
    function<int(int , int)> f1 = add;     //函数指针
    function<int(int , int)> f2 = divide(); // 可调用类类型
    function<int(int , int)> f3 = [](int i, int j)
                                    { return i * j ;}; //lambda表达式
    
    cout << f1(4,2) << endl;
    cout << f2(4,2) << endl;
    cout << f3(4,2) << endl;

    // 可调用对象表中每一项对应一个操作
    //所有的元素必须输入两个int 型参数返回int
    // 每个元素可以是一个函数指针，函数对象，或者lanbda表达式
    map<string , function<int(int , int)>> binops = 
    {
        {"+",add},    //函数指针
        {"-",std::minus<int>()}, // 库函数对象
        {"/", divide()},         // 用户自定义的函数对象
        {"*", [](int i , int j){ return i * j ;}}, // lambda表达式
        {"%",mod}      // 命名的lambda可调用对象
    };

    cout << "binops[+](10, 5) : " << binops["+"](10,5) << endl;
    cout << "binops[-](10, 5) : " << binops["-"](10,5) << endl;
    cout << "binops[/](10, 5) : " << binops["/"](10,5) << endl;
    cout << "binops[*](10, 5) : " << binops["*"](10,5) << endl;
    cout << "binops[%](10, 5) : " << binops["%"](10,5) << endl;

}