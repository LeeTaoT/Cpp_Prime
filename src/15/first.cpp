#include <iostream>
#include <bitset>
using namespace std;
/*
** variadic templates 数量不定的模板参数
** ...就是一个所谓的pack（包）
** 用于template parameters     ,就是template parametes pack       -- 模板参数包
** 用于function parameter types,就是function parameter types pack -- 函数参数类型包
** 用于function parameters     , 就是function parametrs pack      -- 函数参数包
*/
void print()
{
	cout << endl;
}

template <typename T, typename... TYPES>
void print(const T& firstArg, const TYPES&... args)
{
	cout << firstArg << " ";
	print(args...);     //递归调用，直到参数为空，调用无参数版本的print

}

int main()
{
	print(7.5,"hello",bitset<16>(377),42);
  

	/* 
	* output : ldt@ldt-PC:~/tmp$ ./first 
               7.5 hello 0000000101111001 42 
	*/
}