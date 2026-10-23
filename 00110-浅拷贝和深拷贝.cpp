#include <iostream>
using namespace std;
class Person
{
    public:
        Person()
        {
            cout << "默认构造函数" << endl;
        }
        Person(int age, int height)
        {
            m_age = age;
            m_height = new int(height);
            cout << "有参构造函数" << endl;
        }

        //拷贝构造函数 解决浅拷贝带来的问题
        Person(const Person & p)
        {
            m_age = p.m_age;
            
            //深拷贝操作
            m_height = new int(*p.m_height);
            cout << "拷贝构造函数" << endl;
        }
        ~Person()
        {
            //析构函数，将堆区开辟数据做释放操作
            if (m_height != NULL)
            {
                delete m_height;
                m_height = NULL;
            }
            cout << "析构函数" << endl;
        }
        int m_age;
        int * m_height;
};

void test01()
{
    Person p1(18, 180);
    cout << "p1.m_age = " << p1.m_age << endl;
    cout << "p1.m_height = " << *p1.m_height << endl;
    Person p2(p1);
    cout << "p2.m_age = " << p2.m_age << endl;
    cout << "p2.m_height = " << *p2.m_height << endl;
    cout << "----------------" << endl;
}
int main()
{
    test01();
    return 0;
}