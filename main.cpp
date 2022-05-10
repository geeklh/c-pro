#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <typeinfo>

using namespace std; // 命名空间

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
    void exerungame() //重写虚函数
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
    Basicrun3 *m_b; // 声明一个公共指针ss
};

void test03()
{
    Basicrun3 *bs = new examl(10, 20); // 父类指针指向子类的对象
    actGame act = actGame(bs); // 父类指针指向子类的对象  传参
    act.m_b->exerungame();
}
//综合应用
//初始化CPU类
class BasicCpu
{
public:
    virtual void calcuate() = 0;
};

class interCpu: public BasicCpu
{
    virtual void calcuate()
    {
        cout << "intercpu 开始工作：" << endl;
    }
};

class amdCpu: public BasicCpu
{
    virtual void calcuate()
    {
        cout << "amdcpu 开始工作：" << endl;
    }
};

//初始化内存类
class BasicMemory
{
public:
    virtual void strong() = 0;
};
class interMemory: public BasicMemory
{
public:
    virtual void strong()
    {
        cout << "inter 内存类开始工作***" << endl;
    }
};
class amdMemory: public BasicMemory
{
    virtual void strong()
    {
        cout << "amd 内存类开始工作*** " << endl;
    }
};

class vCard
{
public:
    virtual void show() = 0;
};
class interVCard: public vCard
{
public:
    virtual void show()
    {
        cout << "inter vcardL类 开始工作：" << endl;
    }
};
class amdVCard: public vCard
{
public:
    virtual void show()
    {
        cout << "amd card类 开始工作： " << endl;
    }
};

class computer
{
public:
    computer( BasicCpu *c, BasicMemory *m, vCard *v, string com_name)
    {
        bcpu = c;
        bmemory = m;
        vcard = v;
        this->com_name = com_name;
    }
    void comWork()
    {
        cout << com_name << "启动***" << endl;
        bcpu->calcuate();
        bmemory->strong();
        vcard->show();
    }
    void mountWork(BasicCpu *c1, BasicMemory *m1, vCard *v1)
    {
        cout << com_name << "程序启动进行加载" << endl;
        c1->calcuate();
        m1->strong();
        v1->show();
    }
public:
    BasicCpu *bcpu;
    BasicMemory *bmemory;
    vCard *vcard;
    string com_name;
};
//测试方法
void test04()
{
    interVCard *ic = new interVCard();
    amdVCard *ac = new amdVCard();
    interMemory *im = new interMemory();
    amdMemory *am = new amdMemory();
    interCpu *iu = new interCpu();
    amdCpu *au = new amdCpu();
    computer acomputer = computer(au, im, ic, "A机器");
    acomputer.comWork();
    cout << "=====================" << endl;
    computer bcomputer = computer(iu, im, ac, "B机器");
    bcomputer.comWork();
    cout << "=====================" << endl;
    computer ccomputer = computer(iu, im, ic, "C机器");
    ccomputer.comWork();
    cout << "=====================" << endl;
    computer dcomputer = computer(au, am, ac, "D机器");
    dcomputer.comWork();
}
int main() {
//    test01();
//    test02();
//    test03();
    test04();
    cout << "Hello, World!" << endl;
    return 0;
}