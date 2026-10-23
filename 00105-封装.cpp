#include <iostream>
using namespace std;
class circle{
    public:
        int m_r;
        double calculateZC(){
            return 2 * 3.14 * m_r;
        }
    
};
int main(){
    circle c;
    //声明对象，可以看成int i;
    c.m_r = 5;
    cout << "周长为：" << c.calculateZC() << endl;
    return 0;
}
