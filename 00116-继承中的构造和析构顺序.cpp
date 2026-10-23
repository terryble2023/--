#include <iostream>
using namespace std;
class Base
{
    public:
        Base()
        {
            cout<<"Base的构造函数"<<endl;
        }
        ~Base()
        {
            cout<<"Base的析构函数"<<endl;
        }
};
class Son: public Base
{
    public:
        Son()
        {
            cout<<"Son的构造函数"<<endl;
        }
        ~Son()
        {
            cout<<"Son的析构函数"<<endl;
        }
};
void test01()
{
    Son s;
}
int main()
{
    test01();
    return 0;
    //因此，父类先构造，子类后构造
    //子类先析构，父类后析构
    //可以理解为先有鸡后有蛋，但是先吃蛋后吃鸡
}
