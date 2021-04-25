
#include <iostream>
using std::endl;
using std::flush;
using std::ends;
using std::unitbuf;
using std::nounitbuf;
using std::cout ;

int main()
{
    // 通过endl 刷新输出缓冲区,默认加上换行符
    cout << "Hi !" << endl;

    // 通过flush 刷新输出缓冲区 ，什么都不加上
    cout << "hi !" << flush;

    // 输出hi 和一个null然后刷新缓冲区
    cout << "hI !" << ends;

    // 立即刷新被置位,所有写入输出缓冲区的内容会立马被刷新
    cout << unitbuf ;

    // 立即刷新，不加上换行符
    cout << "first" << "second" << endl;

    // 置位恢复原来值
    cout << nounitbuf;

    return 0;
}