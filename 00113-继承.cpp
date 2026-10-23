#include <iostream>
using namespace std;
class Base
{
    public:
        void header()
        {
            cout<<"程序的头"<<endl;
        }
        void footer()
        {
            cout<<"程序的尾"<<endl;
        }
        void left()
        {
            cout<<"程序的左"<<endl;
        }
        void content()
        {
            cout<<"程序的内容"<<endl;
        }
};
/*class Python
{
    public:
        void header()
        {
            cout<<"Python程序的头"<<endl;
        }
        void footer()
        {
            cout<<"Python程序的尾"<<endl;
        }
        void left()
        {
            cout<<"Python程序的左"<<endl;
        }
        void content()
        {
            cout<<"Python程序的内容"<<endl;
        }
};
*/
//继承的好处：减少重复代码
//语法：class 子类名: public 父类名
//     {
//         成员函数
//     };
//子类也称为派生类，父类也称为基类或超类
class Java: public Base
{
    public:
        void content()
        {
            cout<<"Java程序的内容"<<endl;
        }
};
class cpp: public Base
{
    public:
        void content()
        {
            cout<<"cpp程序的内容"<<endl;
        }
};
class Python: public Base
{
    public:
        void content()
        {
            cout<<"Python程序的内容"<<endl;
        }
};
void test01()
{
    cout << "Jvav程序如下：" << endl;
    Java j;
    j.header();
    j.footer();
    j.left();
    j.content();
    cout << "------" << endl;
    cpp cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
    cout << "------" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    
}
int main()
{
    test01();
    return 0;
}