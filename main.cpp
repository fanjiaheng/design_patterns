#include <iostream>
#include "Src/intermediary_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    // Create the mediator
    FjhApp::Mediator *pMediator = new FjhApp::ConcreteMediator();

    FjhApp::Colleague *pColleague1 = new FjhApp::ConcreteColleague1(pMediator);
    FjhApp::Colleague *pColleague2 = new FjhApp::ConcreteColleague2(pMediator);

    FjhApp::ConcreteMediator *pConcreteMediator = dynamic_cast<FjhApp::ConcreteMediator *>(pMediator);
    pConcreteMediator->SetColleague1(pColleague1);
    pConcreteMediator->SetColleague2(pColleague2);

    wchar_t message[260] = L"Where are you from?";
    pColleague1->Send(message);

    return 0;
}