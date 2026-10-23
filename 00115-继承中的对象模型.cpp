#include <iostream>
using namespace std;
class Base
{
    public:
        int m_a;
    protected:
        int m_b;
    private:
        int m_c;
};
class Son: public Base
{
    public:
        int m_d;
};
void test01()
{
    cout << sizeof(Son) << endl;
    //16
    //因此，父类里面的所有非静态成员，都会被子类继承过来
    //父类中的私有成员属性 是被编译器给隐藏了，因此访问不到。但确实是被继承下去了
}
int main()
{
    test01();
    return 0;
}