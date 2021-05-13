#include <cstddef>
using std::size_t;

#include <deque>
using std::deque;

#include <stack>
using std::stack;

#include <iostream>
using std::cout ; using std::cerr; using std::endl;

bool process(int);

int main()
{
    stack<int> inStack;

    for(size_t ix = 0; ix != 10 ; ++ix)
    {
        inStack.push(ix);
    }

    while(!inStack.empty())
    {
        int value = inStack.top();

        cout << value ;
        inStack.pop();
    }
    cout <<  endl ;

    return 0;
}