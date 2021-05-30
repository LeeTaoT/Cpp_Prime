#include <vector>
using std::vector;

#include <iostream>
using std::cout ; using std::endl;




int main()
{

    vector<int> ivec;

    // 默认创建一个vector的容器 大小为0 , capacity 被隐性的定义 
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;

    // 向容器中加入24个元素
   for(vector<int>::size_type ix = 0 ; ix != 24 ; ++ix) 
   {
       ivec.push_back(ix);
   }
 
   //容器大小为24 , capacity 将会大于等于24,这取决于默认定义大小
   cout << "ivec: size: " << ivec.size()
        << " capacity: "  << ivec.capacity() << endl;

   ivec.reserve(50);  //设置capacity 至少为50 可能会分配的更多

    // 容器大小为24, capacity >= 50
   cout << "ivec: size: " << ivec.size()
        << " capacity: "  << ivec.capacity() << endl;

    // 将capacity 大小全部填充满
    while(ivec.size() != ivec.capacity())
    {
        ivec.push_back(0);
    }

    cout << "ivec: size: " << ivec.size()
        << " capacity: "  << ivec.capacity() << endl;
    ivec.push_back(42);   //再往容器里添加一个元素

    // size 应该有51个元素，capacity >= 51 个
    cout << "ivec: size: " << ivec.size()
        << " capacity: "  << ivec.capacity() << endl;

    ivec.shrink_to_fit();  // 要求回收多余的内存空间

    // size 未变 ,capacity 隐式定义
    cout << "ivec: size: " << ivec.size()
        << " capacity: "  << ivec.capacity() << endl;
    

    return 0;
    
}