// Titan.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Observer/Observer.h"
#include <string>

//��������
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

//����۲���
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
		if(pSub->GetStatus() == "��������")
		{
			printf("%s", "�ر�NBA, ���̹���!\n");
		}
	}
};

//����۲���
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
		if(pSub->GetStatus() == "��������")
		{
			printf("%s", "�رչ�Ʊ, ���̹���!\n");
		}
	}
};

int _tmain(int argc, _TCHAR* argv[])
{

	/*******************************�۲���ģʽʵ��  begin ***************************/
	Secreat* pSc = new Secreat;
	NBAOb* pNBA = new NBAOb(pSc);
	StockOb* pStock = new StockOb(pSc);

	pSc->Attach(pNBA);
	pSc->Attach(pStock);
	pSc->SetStatus("123");
	pSc->Notify();
	pSc->SetStatus("��������");
	pSc->Notify();
	pSc->Detach(pNBA);
	pSc->Notify();


	delete pNBA;
	delete pStock;
	delete pSc;

	/*******************************�۲���ģʽʵ��  end ***************************/

	system("pause");
	return 0;
}