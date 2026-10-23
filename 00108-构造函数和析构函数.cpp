#include <iostream>
using namespace std;
class Person
{
    public:
    //构造函数：没有返回值不用写void
    //构造函数的参数可以有多个
    //创建对象的时候，构造函数会自动调用，而且只调用一次
        Person(){
            cout << "构造函数" << endl;
        }
    //析构函数：进行清理的操作，没有返回值不用写void
    //函数名和原本的类名相同，在名称前加上～
    //析构函数不可以有参数，不能有重载
    //对象在销毁前，会自动调用析构函数，而且只会调用一次
        ~Person(){
            cout << "析构函数" << endl;
        }
};
//构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
void test01()
{
    Person p;   //在栈上的数据，test01执行完毕后，释放该对象
}
int main()
{
    //Person p;
    test01();
    return 0;
}