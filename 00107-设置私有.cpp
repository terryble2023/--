#include <iostream>
using namespace std;

//成员属性设置为私有
//1.可以自己控制读写权限
//2.对于写的属性，可以自己定义一个set方法，来设置属性的值

class Person{
    public:
        void setName(string name){
            m_Name = name;
        }
        string getName(){
            return m_Name;
        }
        int getAge(){
            return m_Age;
        }
        void setAge(int age){
            if(age < 0 || age > 120){
                cout << "年龄设置错误" << endl;
                return;
            }
            m_Age = age;
        }
        void setGender(string gender){
            m_Gender = gender;
        }
    private:
        string m_Name;  //姓名  可读可写
        int m_Age = 18;  //年龄  只读   也可以写，需要自己去定义一个set方法，来设置属性的值
        string m_Gender;  //性别  只写
};


int main()
{
    Person p;
    p.setName("张三");
    cout << p.getName() << endl;
    //年龄设置
    //p.setAge(20);
    //p.m_Age = 20;
    //上面两个是可以的
    //p.setAge(121);
    //这个不行
    cout << p.getAge() << endl;
    p.setGender("男");
    //cout << p.getGender() << endl;    只写状态  不能读取

    return 0;
}
