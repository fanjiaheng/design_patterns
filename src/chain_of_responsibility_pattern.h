#pragma once 

#include <iostream>

namespace FjhApp {
//责任链模式

class HolidayRequest
{
public:
	HolidayRequest(int hour):m_iHour(hour){}
	int GetHour()
	{
		return m_iHour;
	}
private:
	int  m_iHour;
};

class Manager
{
public:
	virtual bool HandleRequest(HolidayRequest* request) = 0;
};
 
class PM : public  Manager   //PM:Project manager项目经理
{
public:
	PM(Manager* handler):m_Handler(handler){}
	bool HandleRequest(HolidayRequest* request)
	{
		if (request->GetHour() <= 2 || m_Handler == NULL)
		{
			std::cout << "PM said: OK" << std::endl;
			return true;
		}
		return m_Handler->HandleRequest(request);
	}
private:
	Manager* m_Handler;
};
 
class DM : public Manager //DM：Department Manager部门经理
{
public:
	DM(Manager* handler):m_handler(handler){}
	bool HandleRequest(HolidayRequest* request)
	{
		std::cout <<"DM said: OK" << std::endl;
		return true;
	}
	bool IsIn()
	{
		return true;
	}
private:
	Manager *m_handler;
};
 
class PS : public Manager //Project Supervisor部门主管
{
public:
	PS(Manager* handler):m_handler(handler){}
	bool HandleRequest(HolidayRequest* request)
	{
		DM* pDM = dynamic_cast<DM* >(m_handler);
		if (pDM != NULL)
		{
			if (pDM->IsIn())
				return pDM->HandleRequest(request);
		}
		std::cout <<"PS said: OK" << std::endl;
		return true;
	}
private:
	Manager* m_handler;
};

} //FjhApp

// 测试用例：
// #include <iostream>
// #include "src/chain_of_responsibility_pattern.h"

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;
    
// 	FjhApp::DM* pDM = new FjhApp::DM(NULL);//部门经理
// 	FjhApp::PS* pPS= new FjhApp::PS(pDM);//部门主管
// 	FjhApp::PM* pPM = new FjhApp::PM(pPS);//项目经理
// 	FjhApp::HolidayRequest* Prequest = new FjhApp::HolidayRequest(10);
// 	pPM->HandleRequest(Prequest);
// 	delete Prequest;
	
// 	Prequest = new FjhApp::HolidayRequest(2);
// 	pPM->HandleRequest(Prequest);
// 	delete pDM;
// 	delete pPS;
// 	delete pPM;
// 	delete Prequest;

//     return 0;
// }

// 输出:
// 设计模式测试用例
// DM said :OK
// PM said : OK