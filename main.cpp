#include <iostream>
#include "src/command_pattern.h"

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    srand(time(0));
    FjhApp::Button b1("Button 1"),b2("Button 2"),b3("Button 3");
    FjhApp::CheckButton cb1(b1),cb2(b2),cb3(b3);
    FjhApp::TaskRunner::add(cb1);
    FjhApp::TaskRunner::add(cb2);
    FjhApp::TaskRunner::add(cb3);
    std::cout<< "Control-C to exit" << std::endl;

    while (true) {
        FjhApp::procedure1();
        FjhApp::procedure2();
        FjhApp::procedure3();
    }
    return 0;
}
