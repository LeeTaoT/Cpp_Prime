#include <string>

class HasPtr{
    friend void swap(HasPtr&, HasPtr&);
public :

    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)),i(0){ }

    HasPtr(const HasPtr &p):
        ps(new std::string(*p.ps)),i(p.i){ }
    
    HasPtr& operator=(const HasPtr &);

    ~HasPtr() { delete ps;}

private:
    std::string *ps;
    int i ;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);

}

using std::string ;

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;

    return *this;
}

HasPtr f(HasPtr hp)
{
    HasPtr ret = hp;
    return ret;
}

int main()
{
    HasPtr h("Hi mom !"); //分配一个新的""Hi mom"的copy
    f(h);  //在函数f中，h被拷贝构造函数拷贝， 当f退出时copy 被销毁
           //h 创建时分配的字符串空间也在函数退出时销毁
}