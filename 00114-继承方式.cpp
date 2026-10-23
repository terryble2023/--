#include <iostream>
using namespace std;
//公共继承
class Base1
{
    public:
        int m_a;
    protected:
        int m_b;
    private:
        int m_c;
};

class Son1: public Base1
{
    public:
        void func()
        {
            m_a = 100;  //父类中的 公共权限 成员，到子类里面依然是公共权限
            m_b = 200;  //父类中的 保护权限 成员，到子类里面依然是保护权限
            //m_c = 300;  //父类中的 私有权限 成员，到子类里面不能访问
        }
};
void test01()
{
    Son1 s1;
    s1.func();
    cout<<"s1.m_a = "<<s1.m_a<<endl;
    //s1.m_b = 200;  //错误，保护权限成员不能直接访问
    //s1.m_c = 300;  //错误，私有权限成员不能直接访问
}
//保护继承
class Base2
{
    public:
        int m_a;
    protected:
        int m_b;
    private:
        int m_c;
};
class Son2: protected Base2
{
    public:
        void func()
        {
            m_a = 100;  //父类中的 公共权限 成员，到子类里面变成了保护权限
            m_b = 200;
            //m_c = 300;     //错误，私有权限成员不能直接访问
        }
};
void test02()
{
    Son2 s2;
    //s2.m_a = 200;  //错误，保护权限成员不能直接访问
    //s2.m_b = 400;  //错误，保护权限成员不能直接访问
    //s2.m_c = 600;  //错误，私有权限成员不能直接访问
}
//私有继承
class Base3
{
    public:
        int m_a;
    protected:
        int m_b;
    private:
        int m_c;
};
class Son3: private Base3
{
    public:
        void func()
        {
            m_a = 100;  //父类中的 公共权限 成员，到子类里面变成了私有权限
            m_b = 200;  //父类中的 保护权限 成员，到子类里面变成了私有权限
            //m_c = 300;  //错误，私有权限成员不能直接访问
        }
};
class Grandson3: public Son3
{
    public:
        void func()
        {
            //m_a = 100;  
            //m_b = 200;  
            //m_c = 300;  
            //到了孙子类，只能访问了公共继承的保护权限,所以全部报错
        }
};
void test03()
{
    Son3 s3;
    //s3.m_a = 200;  //错误，私有权限成员不能直接访问
    //s3.m_b = 400;  //错误，私有权限成员不能直接访问
    //s3.m_c = 600;  //错误，私有权限成员不能直接访问
}

int main()
{
    test01();
    return 0;
}