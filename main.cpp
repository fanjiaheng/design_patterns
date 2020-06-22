#include <iostream>
#include "Src/template_pattern.h"

using namespace std;


int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    
    // 类的指针，用的是内存堆，是个永久变量，除非你释放它，需要用new运算符分配内存

    // 阿里校招
    FjhApp::Company *alibaba = new FjhApp::Alibaba();
    alibaba->Recruit();
 
    // 腾讯校招
    FjhApp::Company *tencent = new FjhApp::Tencent();
    tencent->Recruit();
 
    delete tencent;
    delete alibaba;

    return 0;
}