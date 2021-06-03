#include <memory>

using std::unique_ptr; using std::shared_ptr;

#include <iostream>
using std::cout ; using std::endl;
int main()
{
    //up指向未初始化的ints数组
    unique_ptr<int[]> up(new int[10]);
    for(size_t i = 0 ; i != 10; ++i)
    {
        up[i] = i;
        cout << up[i] ;
    }
    cout << endl;

    up.release(); //自动使用delete[] 删除数组指针

    shared_ptr<int> sp(new int[10], [](int *p){ delete[] p ;});

    for(size_t i = 0; i != 10; ++i)
    {
        *(sp.get() + i) = i;
        cout << *(sp.get() + i);
    }
    cout << endl;

    sp.reset(); //自动调用定义时提供的lamda表达式,delete [] 释放数组

}