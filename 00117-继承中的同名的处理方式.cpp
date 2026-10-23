#include <iostream>
using namespace std;
class Base
{
    public:
        Base()
        {
            m_a = 100;
        }
        void func()
        {
            cout<<"Base的func()调用"<<endl;
        }
        void func(int a)
        {
            cout<<"Base的func(int a)调用"<<endl;
        }
        int m_a;
};
class Son: public Base
{
    public:
        Son()
        {
            m_a = 200;
        }
        void func()
        {
            cout<<"Son的func()调用"<<endl;
        }
        int m_a;
};
//同名成员属性处理方式
void test01()
{
    Son s;
    cout<<"s.m_a = "<<s.m_a<<endl;
    //200
    //因此，先访问子类的成员
    //那么怎么访问父类的成员呢？
    //使用作用域运算符，来访问父类的成员
    cout<<"s.m_a = "<<s.Base::m_a<<endl;
    //100
}
//同名成员函数调用处理方式
void test02()
{
    Son s;
    s.func();
    //上面的是Son的func()调用
    //下面的是Base的func()调用
    s.Base::func(); 

    //如果子类中出现和父类中同名的成员函数，子类的同名成员会隐藏掉父类中的所有同名成员
    //如果想访问父类中被隐藏的成员函数，需要使用作用域运算符，来访问父类的成员函数
    s.Base::func(100);
    //Base的func(int a)调用
    //100
}
int main()
{
    test01();
    test02();
    return 0;
    //1.子类对象可以直接访问到子类中的同名成员
    //2.子类对象加作用域运算符，来访问父类的同名成员函数
    //3.当子类与父类中出现同名的成员函数时，子类的同名成员函数会隐藏掉父类中的所有同名成员函数，
    //如果想访问父类中被隐藏的成员函数，需要使用作用域运算符，来访问父类的成员函数
}
