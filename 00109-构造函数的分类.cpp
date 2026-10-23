#include <iostream>
using namespace std;
class Person
{
    public:
        int age;
        //默认构造函数：没有参数，也没有返回值
        Person(){
            cout << "默认构造函数" << endl;
        }
        //有参构造函数：有参数，有返回值
        Person(int a){
            age = a;
            cout << "有参构造函数" << endl;
        }
        
        //拷贝构造函数：有参数，有返回值
        Person(const Person& p){
            cout << "拷贝构造函数" << endl;
            age = p.age;
            //将传入的人身上的所有属性，拷贝到自己身上
        }
        ~Person(){
            cout << "析构函数" << endl;
        }
};
//调用
void test01()
{
    //1.括号法
    Person p1;      //默认调用函数不要加括号
    Person p2(10);
    cout << p2.age << endl;
    Person p3(p2);
    cout << p3.age << endl;
    cout << "----------------" << endl;
    //2.显示法：
    Person p4;
    Person p5 = Person(12); //有参构造
    Person p6 = Person(p5); //拷贝构造

    Person(13); //匿名对象  特点：执行结束后系统自动收回(自动析构)
    (void)Person(14);   //匿名对象(消歧)
    Person{15}; //匿名对象(消歧)
    cout << "----------------" << endl;

    //不要利用拷贝构造函数，初始化匿名对象，编译器会认为是对象声明
    //Person(p5);   重定义报错
    Person{p5};
    (void)Person{p5};
    //匿名对象(消歧)
    cout << "----------------" << endl;
    
    //3.隐式转换法
    Person p7 = 16;
    //相当于Person p7 = Person(16);
    cout << "----------------" << endl;
}
int main()
{
    test01();
    return 0;
}