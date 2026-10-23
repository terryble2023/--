//写在前面：多重继承在开发中尽量避免。
#include <iostream>
using namespace std;
class Base1
{
    public:
        Base1(){
            m_a = 100;
        }
        int m_a;
};
class Base2
{
    public:
        Base2(){
            m_b = 200;
        }
        int m_b;
};
class Son: public Base1, public Base2
{
    public:
        Son(){
            m_c = 300;
            m_d = 400;
        }
        int m_c;
        int m_d;
};
void test01()
{
    Son s;
    cout << sizeof(s) << endl;
    /*
    cout << "Base1::m_a = " << s.m_a << endl;
    cout << "Base2::m_b = " << s.m_b << endl;
    */
    //当父类中出现同名成员，尽量加作用域区分，不区分不会报错，但是尽量避免，以免误用
    cout << "Base1::m_a = " << s.Base1::m_a << endl;
    cout << "Base2::m_b = " << s.Base2::m_b << endl;
}

int main()
{
    test01();
    return 0;
}