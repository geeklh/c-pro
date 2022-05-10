#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <typeinfo>

using namespace std; // 命名空间

//设计模式
// 1. 工厂模式
class Product
{
public:
    virtual ~Product(); //析构函数
protected:
    Product();
};
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}