#include <iostream>
using namespace std;

class Animal
{
    public:
        int m_age;
};

class Sheep: public Animal
{};

class Camel: public Animal
{};

class Alpaca: public Sheep, public Camel
{};

void test01()
{
    Alpaca a;
    /*
    a.m_age = 10;
    cout<<"a.m_age = "<<a.m_age<<endl;
    */
    //上面的会报错，报错显示：request for member ‘m_age’ is ambiguous
    //解决方法：使用作用域解析运算符
    a.Sheep::m_age = 10;
    cout<<"a.Sheep::m_age = "<<a.Sheep::m_age<<endl;
    a.Camel::m_age = 20;
    cout<<"a.Camel::m_age = "<<a.Camel::m_age<<endl;
    //当菱形继承，两个父类拥有相同数据，需要加作用域符来区分

    //这份数据只要有一份就可以，菱形继承会导致数据有两份造成浪费
    //解决方法：使用虚继承
    class Alpaca: virtual public Sheep, public virtual Camel
    {};
    //virtual的先后顺序没有讲究，但是建议放在第一个位置
    Alpaca a1;
    a1.Sheep::m_age = 100;
    cout<<"a1.Sheep::m_age = "<<a1.Sheep::m_age<<endl;
    a1.Camel::m_age = 200;
    cout<<"a1.Camel::m_age = "<<a1.Camel::m_age<<endl;

}

int main()
{
    test01();
    return 0;
}