#include <iostream>
#include <string.h>

using namespace std;

//简单工厂模式
//适合场景
//1.程序中需要创建的对象很多，导致new的操作会有很多
//2. 但是创建对象的操作不是重点，应该被关注的点应该是对象的操作，所以需要分离对象的创建和操作，如此，方便后期程序的扩展和维护

typedef enum ProductTypeTag //枚举
{
    TypeA,
    TypeB,
    TypeC
}PRODUCTTYPE;

class Product
{
public:
    virtual void showPro() = 0;
};
class ProductA : public Product
{
public:
    void showPro()
    {
        cout << "I'm ProductA" << endl;
    }
};
int main()
{
    cout << "Hello World!\n";
}