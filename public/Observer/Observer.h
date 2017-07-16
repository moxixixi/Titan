/**Copyright (C), 2017
* @file Observer.h
* @brief 线程不安全的观察者模式实现
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

//观察者基类
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

//抽象主题类
class Subject
{
public:
	Subject(void){};
	~Subject(void){};

public:
	//增加观察者
	void Attach(Observer* pObserver){m_Observers.push_back(pObserver);}
	//移除观察者
	void Detach(Observer* pObserve){m_Observers.remove(pObserve);}
	//通知所有观察者 
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