#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <typeinfo>

using namespace std; // 命名空间

//单例模式
//保证一个类只有一个函数 并提供一个访问他的全局访问点 在类中，构造一个实例，就必须调用类的构造函数
//为了防止外部调用类的构造函数而构造实例  需要将构造函数的访问权限标记为protectd或者是private
// （注意：）最后需要提供出一个全局访问点，需要在类中定义一个（静态）static函数 返回在类内部唯一构造的实例

//单例1
class Singleton1 {
private:
    int m_Test;
    Singleton1(){ m_Test = 10;}
    static Singleton1 *m_instance;
public:
    static Singleton1 *GetInstance() { // 创建实例
        if( m_instance == NULL) {
            m_instance = new Singleton1();
        }
        return m_instance;
    }
    static void DestoryInstance() { // 删除实例
        if ( m_instance != NULL) {
            delete m_instance;
            m_instance = NULL;
        }
    }
    int Gettest() { // 只是一个例子
        return m_Test;
    }
};

Singleton1 *Singleton1 ::m_instance = NULL;

void Singleton1form () {
    Singleton1 *singleton1obj = Singleton1 ::GetInstance();
    cout << singleton1obj->Gettest() << endl;
    Singleton1::DestoryInstance();
}
//实例1有很不好的地方 没有考虑到多线程的问题 在多线程的情况小爱，可能需要创建多个singleton实例

class Singleton2 {
private:
    Singleton2(){m_test2 = 0;}
    static Singleton2 *m_instance2;
    int m_test2;
public:
    static Singleton2 *GetInstance() {
        if( m_instance2 == NULL)
        {
            //        Lock(); //可以使用boost库的 资源锁 为了解决多线程资源污染的问题
            if( m_instance2 == NULL)
                // 这里进行两次检索字段为空 "双检锁" 是因为进行一次加锁和解锁 同时保证线程安全
            {
                m_instance2 = new Singleton2();
            }
            //          UnLock() //资源解锁
        }
        return m_instance2;
    }

    static void DestoryInstance() {
        if ( m_instance2 != NULL) {
            delete m_instance2;
            m_instance2 == NULL;
        }
    }

    int Gettest() {
        return m_test2;
    }
};
Singleton2 *Singleton2::m_instance2 = NULL;

void Singleton2form() { //使用案例
    Singleton2 *singleton2obj = Singleton2::GetInstance();
    cout << singleton2obj->Gettest() << endl;
    Singleton2::DestoryInstance();
}

//单例实例3
class Singleton3 {
private:
    int m_test;
    Singleton3(){ m_test = 3; }
    static const Singleton3 *m_instance;
public:
    static Singleton3 *GetInstance() {
        return const_cast< Singleton3 * >(m_instance);
    }

    static void DestoryInstance() {
        if( m_instance == NULL) {
            delete m_instance;
            m_instance = NULL;
        }
    }

    int Gettest(){
        return m_test;
    }
};
const Singleton3 *Singleton3::m_instance = new Singleton3();

void simplesingleform() {
    Singleton3 *singleton3obj = Singleton3::GetInstance();
    cout << singleton3obj->Gettest() << endl;
    Singleton3::DestoryInstance();
}

int main() {
    Singleton3 *singleton3obj = Singleton3::GetInstance();
    cout << singleton3obj->Gettest() << endl;
    Singleton3::DestoryInstance();
    cout << "Hello, World!" << endl;
    return 0;
}