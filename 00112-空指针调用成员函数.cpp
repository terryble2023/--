#include <iostream>
using namespace std;
class Person
{
    public:
        void showClassName()
        {
            cout << "this is Person" << endl;
        }
        void showAge1()
        {
            cout << "this->age = " << m_Age1<< endl;
        }
        int m_Age1;
        void showAge2()
        {
            //报错的原因是因为传入的指针是NULL
            //cout << "this->age = " << this->m_Age2<< endl;
            
            //解决方法是判断指针是否为空
            if(this == NULL)
            {
                cout << "this is NULL" << endl;
                return;
            }
            
        }
        int m_Age2;
};
void test01()
{
    Person * p = NULL;
    p->showClassName();
    //p->showAge1(); 空指针调用成员函数，会报错
    p->showAge2();
}
int main()
{
    test01();
    return 0;
}