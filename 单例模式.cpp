#include <iostream>
using namespace std;
/*
* 1.构造函数私有化
* 2.提供一个全局的静态方法
* 3.类中定义一个静态指针，指向唯一对象
*/


//懒汉式单例模式(有线程安全问题)
//首次实例化类是会创建单例对象
class Singelton
{
private:
	//私有化构造函数
	Singelton()
	{
		cout << "构造函数调用" << endl;
		m_sing = NULL;
	}
	static Singelton* m_sing;
public:
/*
* Singelton* getInstance()函数在多线程中可能出现的问题
* 线程1在判断if之后认为m_sing为空，但此时失去CPU 认为现在没有创建m_sing
* 线程2也判断if之后认为m_sing为空，创建m_sing
* 线程1得到CPU后再次创建m_sing
* 导致m_sing被创建两次
*/
	static Singelton* getInstance()
	{
		if (m_sing == NULL)
		{
			m_sing = new Singelton;
		}
		return m_sing;
	}

	void show()
	{
		cout << "懒汉式单例模式" << endl;
	}
};
Singelton* Singelton::m_sing = NULL;

void test1()
{
	Singelton* p1 = Singelton::getInstance();
	Singelton* p2 = Singelton::getInstance();
	cout << p1 << endl;
	cout << p2 << endl;
	p1->show();
	p2->show();
}

//——————————————————————————————

//饿汉式单例模式，类加载时就会创建单例对象
//就算不用也会占用内存
class Singelton2
{
private:
	//私有化构造函数
	Singelton2()
	{
		cout << "构造函数调用" << endl;
		m_sing = NULL;
	}
	static Singelton2* m_sing;
public:
	static Singelton2* getInstance()
	{
		return m_sing;
	}

	void show()
	{
		cout << "饿汉式单例模式" << endl;
	}
};
Singelton2* Singelton2::m_sing = new Singelton2;

int main(void)
{
	test1();

	return 0;
}