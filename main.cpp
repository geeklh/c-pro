#include <iostream>
#include <string>

using namespace std;

//多态指的是调用同一个接口，表现处不同的特性，分为静态多态和动态多态
//静态多态指的是编译期间就能确定其特性的多态，动态多态是在运行时确定其特性

class BasicGame
{
public:
    virtual void exeGame() = 0; // 虚函数
};
class TCSGame: public BasicGame //继承抽象类
{
public:
    TCSGame(string name) // 构造函数
    {
        m_Name = name;
    }
    virtual void  exeGame()// 1.重写虚函数
    {
        cout << "运行程序1: " << m_Name << endl;
    }

public:
    string  m_Name;
};

class WingGame: public BasicGame
{
public:
    WingGame(string name) // 构造函数
    {
        m_Name= name;
    }
    virtual void exeGame() //重写虚函数
    {

        cout << "运行程序2: " << m_Name << endl;
    }

public:
    string m_Name;
};
void test01()
{
    BasicGame *game;
    game = new TCSGame("俄罗斯方块");
    game->exeGame();// 3. 用该指针调用子类的 虚函数 使用引用也可以 引用的本质也是指针
    cout << "************" << endl;
    game = new WingGame("魂斗罗");
    game->exeGame();
    return;
}
//多态实现2
class runBasic
{
    friend void func(runBasic *b); //声明友元函数 方便调用成员变量

public:
    virtual void runGame() = 0; // 纯虚函数
};

class runTCSGame: public runBasic
{
public:
    runTCSGame(string name) // 构造函数
    {
        m_Name = name;
    }
    virtual void runGame() // 重写虚函数
    {
        cout << "运行程序run1：" << m_Name << endl;
    }
public:
    string m_Name;
};

class RunWingGame: public runBasic
{
public:
    RunWingGame(string name) // 构造函数
    {
        m_Name = name;
    }
    virtual void runGame()
    {
        cout << "运行程序run2：" << m_Name << endl;
    }

public:
    string m_Name;
};
void func(runBasic *b)
{
    b->runGame();
}
void test02()
{
    runBasic *b;
    b = new runTCSGame("运行程序名称1");
//    b->runGame();
    func(b);// 通过传参的方式来调用
    b = new RunWingGame("运行程序名称2");
//    b->runGame();
    func(b);// 同上
}

//多态实现3
class Basicrun3
{
public:
    virtual void exerungame() = 0;
    int A;
    int B;
};
class examl: public Basicrun3 //继承抽象函数
{
public:
    examl(int a, int b)
    {
        A = a;
        B = b;
    }
    void exerungame()
    {
        cout << "A= " << A << ", B= " << B << endl;
    }
};

class actGame
{
public:
    actGame(Basicrun3 *b) //父类指针指向子类的对象
    {
        m_b = b;
    }

public:
    Basicrun3 *m_b;
};

void test03()
{
    Basicrun3 *bs = new examl(10, 20); // 父类指针指向子类的对象
    actGame act = actGame(bs); // 父类指针指向子类的对象  传参
    act.m_b->exerungame();
}

int main() {
//    test01();
//    test02();
    test03();
    cout << "Hello, World!" << endl;
    return 0;
}