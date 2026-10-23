#include <iostream>
using namespace std;
//继承中的同名静态成员处理方式
class Base{
    public:
        static int m_a;

        static void func()
        {
            cout<<"Base::func"<<endl;
        }
};
int Base::m_a = 100;

class Son: public Base
{
    public:
        static int m_a;
        static void func()
        {
            cout<<"Son::func"<<endl;
        }
};
int Son::m_a = 200;
void test01()
{
    //通过对象访问
    Son s;
    cout<<s.Base::m_a<<endl;
    cout<<s.m_a<<endl;
    s.Base::m_a = 120;  //错误，静态成员不能直接访问

    //通过类名访问
    cout<<Base::m_a<<endl;
    cout<<Son::m_a<<endl;

    cout<<Son::Base::m_a<<endl;
    //上面这个，第一个双冒号代表通过类名访问，第二个双冒号代表访问父类作用域的静态成员
}

void test02()
{
    //通过对象访问
    Son s;
    s.func();
    s.Base::func();
    //通过类名访问
    Base::func();
    Son::func();
    Son::Base::func();
}
//值得说明的是，以上的Son::Base::语句不常用，在实际开发中尽量避免。
//在两种情况下才会不可避免地用到该场景：
//1.模板里面只有派生类的名字。（派生没学所以不多讲）
//2.多重继承指出走哪条路：
/*
class A { public: static int id; };   // id = 1
class B { public: static int id; };   // id = 2
class C : public A, public B {};

//cout << C::id;        // 有歧义，编译不过
cout << C::A::id << " " << C::B::id << endl;   // 1 2
*/
//然而实际开发中，尽量少用多重继承。
int main()
{
    test01();
    test02();

    return 0;
}