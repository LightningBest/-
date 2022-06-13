#include <iostream>
using namespace std;
/*
* 1.���캯��˽�л�
* 2.�ṩһ��ȫ�ֵľ�̬����
* 3.���ж���һ����ָ̬�룬ָ��Ψһ����
*/


//����ʽ����ģʽ(���̰߳�ȫ����)
//�״�ʵ�������ǻᴴ����������
class Singelton
{
private:
	//˽�л����캯��
	Singelton()
	{
		cout << "���캯������" << endl;
		m_sing = NULL;
	}
	static Singelton* m_sing;
public:
/*
* Singelton* getInstance()�����ڶ��߳��п��ܳ��ֵ�����
* �߳�1���ж�if֮����Ϊm_singΪ�գ�����ʱʧȥCPU ��Ϊ����û�д���m_sing
* �߳�2Ҳ�ж�if֮����Ϊm_singΪ�գ�����m_sing
* �߳�1�õ�CPU���ٴδ���m_sing
* ����m_sing����������
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
		cout << "����ʽ����ģʽ" << endl;
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

//������������������������������������������������������������

//����ʽ����ģʽ�������ʱ�ͻᴴ����������
//���㲻��Ҳ��ռ���ڴ�
class Singelton2
{
private:
	//˽�л����캯��
	Singelton2()
	{
		cout << "���캯������" << endl;
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
		cout << "����ʽ����ģʽ" << endl;
	}
};
Singelton2* Singelton2::m_sing = new Singelton2;

int main(void)
{
	test1();

	return 0;
}