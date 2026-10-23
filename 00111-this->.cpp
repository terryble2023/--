#include <iostream>
using namespace std;
class Person
{
    public:
        Person()
        {
            this->age = 0;
        }
        Person(int age)
        {
            this->age = age;
            //解决命名冲突问题
            //this指针的本质 是一个指针常量 指针的指向是不可以修改的
            //this = NULL; 是错误的
            //本质上是Person * const this;
        }
        int age;
        int m_A;
        mutable int m_B;        //特殊变量，可以理解为给const常量配了一把开锁的钥匙
        //假如就是想要const Person * const this;
        //那么,在成员函数后面加const关键字即可
        void showPerson()const{
            this -> m_B = 100;
        }
};
void test01()
{
    Person p;
    p.showPerson();
}
void test02()
{
    const Person p; //变为常对象
    //p.m_A = 100;  不能修改
    p.m_B = 100;
}
int main()  
{
    Person p1(20);
    p1.showPerson();
    return 0;
}