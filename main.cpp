#include <iostream>
#include "src/chain_of_responsibility_pattern.h"

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    
	FjhApp::DM* pDM = new FjhApp::DM(NULL);//部门经理
	FjhApp::PS* pPS= new FjhApp::PS(pDM);//部门主管
	FjhApp::PM* pPM = new FjhApp::PM(pPS);//项目经理
	FjhApp::HolidayRequest* Prequest = new FjhApp::HolidayRequest(10);
	pPM->HandleRequest(Prequest);
	delete Prequest;
	
	Prequest = new FjhApp::HolidayRequest(2);
	pPM->HandleRequest(Prequest);
	delete pDM;
	delete pPS;
	delete pPM;
	delete Prequest;

    return 0;
}
