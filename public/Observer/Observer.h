/**Copyright (C), 2017
* @file Observer.h
* @brief �̲߳���ȫ�Ĺ۲���ģʽʵ��
* @date 2017-7-16
* @author chengtao
*
* @version 1.0
*
*/
#ifndef Observer_h__
#define Observer_h__
#include <list>

class Subject;

//�۲��߻���
class Observer
{
public:  
	Observer(Subject* pSubject)
	{
		m_pSubject = pSubject;
	}
	~Observer(void){};

public:
	virtual void Update() = 0;

protected:
	Subject* m_pSubject;
};

//����������
class Subject
{
public:
	Subject(void){};
	~Subject(void){};

public:
	//���ӹ۲���
	void Attach(Observer* pObserver){m_Observers.push_back(pObserver);}
	//�Ƴ��۲���
	void Detach(Observer* pObserve){m_Observers.remove(pObserve);}
	//֪ͨ���й۲��� 
	void Notify()
	{
		std::list<Observer*>::iterator itr = m_Observers.begin();
		for(; itr != m_Observers.end(); itr++)
		{
			if((*itr) != NULL)
			{
				(*itr)->Update();
			}
		}
	}

private:
	std::list<Observer*> m_Observers; 
};

#endif // Observer_h__