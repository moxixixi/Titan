// Titan.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Observer/Observer.h"
#include <string>

//具体主题
class Secreat
	: public Subject
{
public:
	Secreat(void){};
	~Secreat(void){};

public:
	void SetStatus(const char* pszStatus)
	{
		if(pszStatus != NULL)
		{
			m_strStatus = pszStatus;
			printf("%s\n", m_strStatus.c_str());
		}
	}
	std::string GetStatus()
	{
		return m_strStatus;
	}

private:
	std::string m_strStatus;
};

//具体观察者
class NBAOb
	:public Observer
{
public:
	NBAOb(Subject* pSubject)
		:Observer(pSubject)
	{
	};
	~NBAOb(){};

public:
	void Update()
	{
		Secreat* pSub = reinterpret_cast<Secreat*>(m_pSubject);
		if(pSub->GetStatus() == "所长来了")
		{
			printf("%s", "关闭NBA, 立刻工作!\n");
		}
	}
};

//具体观察者
class StockOb
	:public Observer
{
public:
	StockOb(Subject* pSubject)
		:Observer(pSubject)
	{
	};
	~StockOb(){};

public:
	void Update()
	{
		Secreat* pSub = reinterpret_cast<Secreat*>(m_pSubject);
		if(pSub->GetStatus() == "所长来了")
		{
			printf("%s", "关闭股票, 立刻工作!\n");
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	/*******************************观察者模式实例  begin ***************************/
	Secreat* pSc = new Secreat;
	NBAOb* pNBA = new NBAOb(pSc);
	StockOb* pStock = new StockOb(pSc);

	pSc->Attach(pNBA);
	pSc->Attach(pStock);
	pSc->SetStatus("123");
	pSc->Notify();
	pSc->SetStatus("所长来了");
	pSc->Notify();
	pSc->Detach(pNBA);
	pSc->Notify();


	delete pNBA;
	delete pStock;
	delete pSc;

	/*******************************观察者模式实例  end ***************************/

	system("pause");
	return 0;
}