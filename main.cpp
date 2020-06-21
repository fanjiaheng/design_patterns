#include <iostream>
#include "Src/prototype_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::ConcretePrototype1 *test = new FjhApp::ConcretePrototype1("小李");
    FjhApp::ConcretePrototype2 *test2 = (FjhApp::ConcretePrototype2 *)test->clone();
    test->show();
    test2->show();

    return 0;
}