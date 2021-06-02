#include <iostream>
using std::cout ; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <cstddef>
using std::size_t;

#include <new>
using std::nothrow;


size_t get_size() { return 42;}

int main()
{
    //如果分配失败，new操作会返回一个NULL 指针
    int *p1 = new int; //如果 allocation 失败, new 会抛出一个std::bad_alloc
    int *p2 = new (nothrow) int ; // 抛出空指针，如果失败

    int i0; 

    int *p0 = new int; // p0  指向一个未初始化的动态分配的int 内存,

    delete p0;        // 释放内存空间

    int i(1024);
    string s(10, '9');
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};

    int *pi = new int(1024); //pi  指向初始化未1024的 int型的内存空间
    string *ps = new string(10 , '9'); //*ps 为9999999999
    vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};

    cout << "*pi: " << *pi
         << "\ti: " << i << endl
         << "*ps: " << *ps
         << "\ts: " << s << endl;

    for(auto b = pv->begin(); b != pv->end(); ++b)
    {
        cout << *b << " ";
    }
    cout << endl;

    // 释放pi，ps，pv 指向的内存空间
    delete pi;
    delete ps;
    delete pv;

    //调用get_size()决定需要分配多少int 型内存空间
    int *pia = new int[get_size()];
    delete [] pia; // 数组[]  号用来删除数组中的元素

    typedef int arrT[42];
    int *p = new arrT;
    delete [] p;   // []  必须

    return 0;


}

