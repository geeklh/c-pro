#include <iostream>
#include <string.h>

using namespace std;

//在函数使用中 . 和 -> 的区别是：.用于类的实例，->用于类的指针

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
class ProductA: public Product
{
public:
    void showPro()
    {
        cout << "I'm ProductA" << endl;
    }
};

class ProductB: public Product
{
public:
    void showPro()
    {
        cout << "I'm ProductB" << endl;
    }
};

class ProductC : public Product
{
public:
    void showPro()
    {
        cout << "I'm ProductC" << endl;
    }
};

class Factory
{
public:
    Product* CreateProduct(PRODUCTTYPE type)
    {
        switch(type)
        {
        case TypeA:
            return new ProductA();
        case TypeB:
            return new ProductB();
        case TypeC:
            return new ProductC();
        default:
            return NULL;
        }
    }
};

void testsimplefactory() // 调用简单工厂的方法
{
    Factory* ProductFactory = new Factory();
    Product* productObjA = ProductFactory->CreateProduct(TypeA);
    if (productObjA != NULL)
    {
        productObjA->showPro();
    }
    Product* productObjB = ProductFactory->CreateProduct(TypeB);
    if (productObjB != NULL)
    {
        productObjB->showPro();
    }
    Product* productObjC = ProductFactory->CreateProduct(TypeC);
    if (productObjC != NULL)
    {
        productObjC->showPro();
    }
    delete ProductFactory;
    ProductFactory = NULL;

    delete productObjA;
    productObjA = NULL;

    delete productObjB;
    productObjB = NULL;

    delete productObjC;
    productObjC = NULL;
}

//工厂模式
//适用情况：设计初期，考虑到产品在后期会进行扩展的情况，或者是产品结构比较复杂的情况


class formProduct
{
public:
    virtual void formShow() = 0; //虚函数
};

class formProductA : public formProduct
{
public:
    void formShow()
    {
        cout << "I'm ProductA" << endl; //重写虚函数
    }
};

class formProductB : public formProduct
{
public:
    void formShow()
    {
        cout << "I'm ProductB" << endl;
    }
};

class formFactory //调用这个会制造出一个专门早特定对象的工厂类出来
{
public:
    virtual formProduct* CreateformProduct() = 0; // 虚函数
};

class formFactoryA :public formFactory
{
public:
    formProduct* CreateformProduct() {
        return new formProductA(); // 重写虚函数
    }
};

class formFactoryB :public formFactory {
public:
    formProduct* CreateformProduct() {
        return new formProductB();
    }
};

void useformfactory() { // 调用工厂方法的实例
    formFactory* runformFactoruA = new formFactoryA(); // 初始化一个工厂类的指针
    formProduct* formproducta = runformFactoruA->CreateformProduct(); //利用工厂类里面的方法制造出给对应的产品类指针
    formproducta->formShow(); //指令产品的功能函数

    formFactory* runformFactoruB = new formFactoryB();
    formProduct* formproductb = runformFactoruB->CreateformProduct();
    formproductb->formShow();

    if (runformFactoruA != NULL) {
        delete runformFactoruA;
        runformFactoruA = NULL;
    }

    if (formproducta != NULL) {
        delete formproducta;
        formproducta = NULL;
    }

    if (runformFactoruB != NULL) {
        delete runformFactoruB;
        runformFactoruB = NULL;
    }

    if (formproductb != NULL) {
        delete formproductb;
        formproductb = NULL;
    }
}

//抽象工厂模式 就是工厂模式的扩展和延伸，但是更加具有一般性和代表性，
//工厂方法模式适用于产品种类结构单一的场合，为一类产品提供创建的接口；
//而抽象工厂方法适用于产品种类结构多的场合，主要用于创建一组（有多个种类）相关的产品，为它们提供创建的接口；
//就是当具有多个抽象角色时，抽象工厂便可以派上用场。

class abstractProductA {
public:
    virtual void absShow() = 0; //虚函数
};

class absProductA1 :public abstractProductA {
public:
    void absShow() {
        cout << "I'm ProductA1" << endl;
    }
};

class absProductA2 :public abstractProductA {
public:
    void absShow() { //重写虚函数
        cout << "I'm ProductA2" << endl;
    }
};

class abstractProductB {
public:
    virtual void absShow() = 0; //虚函数
};

class absProductB1 :public abstractProductB {
public:
    void absShow() {
        cout << "I'm ProductB1" << endl;
    }
};

class absProductB2 :public abstractProductB {
public:
    void absShow() {
        cout << "I'm ProductB2" << endl;
    }
};

class abstractFactory {
public:
    virtual abstractProductA* CreateAbsProductA() = 0;
    virtual abstractProductB* CreateAbsProductB() = 0;
};

class abstractFactory1 :public abstractFactory {
public:
    abstractProductA* CreateAbsProductA() { //重写函数
        return new absProductA1();
    }

    abstractProductB* CreateAbsProductB() {
        return new absProductB1();
    }
};

class abstractFactory2 :public abstractFactory {
public:
    abstractProductA* CreateAbsProductA() { //重写函数
        return new absProductA2();
    }

    abstractProductB* CreateAbsProductB() {
        return new absProductB2();
    }
};
void abstrctfactoryform(){ //抽象工厂模式的调用实例


    abstractFactory* absfactoryObj1 = new abstractFactory1();
    abstractProductA* absproductObjA1 = absfactoryObj1->CreateAbsProductA();
    abstractProductB* absproductObjB1 = absfactoryObj1->CreateAbsProductB();

    absproductObjA1->absShow();
    absproductObjB1->absShow();

    abstractFactory* absfactoryObj2 = new abstractFactory2(); //实例避免复用，产生脏数据
    abstractProductA* absproductObjA2 = absfactoryObj2->CreateAbsProductA();
    abstractProductB* absproductObjB2 = absfactoryObj2->CreateAbsProductB();

    absproductObjA2->absShow();
    absproductObjB2->absShow();

    if (absfactoryObj1) {
        delete absfactoryObj1;
        absfactoryObj1 = NULL;
    }
    if (absproductObjA1) {
        delete absproductObjA1;
        absproductObjA1 = NULL;
    }
    if (absproductObjB1) {
        delete absproductObjB1;
        absproductObjB1 = NULL;
    }
    if (absfactoryObj2) {
        delete absfactoryObj2;
        absfactoryObj2 = NULL;
    }
    if (absproductObjA2) {
        delete absproductObjA2;
        absproductObjA2 = NULL;
    }
    if (absproductObjB2) {
        delete absproductObjB2;
        absproductObjB2 = NULL;
    }
}
int main()
{
    
    cout << "Hello World!\n";
}