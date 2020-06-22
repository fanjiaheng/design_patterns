#include <iostream>
#include "Src/adapter_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::TwoPhaseOutlet* outlet = new FjhApp::OutletConvertor();
    outlet->doPlugin();

    return 0;
}