#include <iostream>
#include "Src/facade_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::CWorker *w = new FjhApp::CWorker();

    std::cout << "开始调用总工作1" << std::endl;
    w->work1();
    std::cout << "开始调用总工作2" << std::endl;
    w->work2();

    return 0;
}