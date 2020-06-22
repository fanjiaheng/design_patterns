#include <iostream>
#include "Src/state_pattern.h"

using namespace std;


int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    // 状态模式
	FjhApp::Context *p = new FjhApp::Context(new FjhApp::ConcreteStateA());
	p->SomeOperation();
	p->SomeOperation();
	delete p;

    return 0;
}