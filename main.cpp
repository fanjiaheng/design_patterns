#include <iostream>
#include "Src/decorator_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;
    
    FjhApp::IWomen *myWife = new FjhApp::Wife();
    FjhApp::Lipstick *lips  = new FjhApp::Lipstick(myWife);
    FjhApp::Mascara *mas = new FjhApp::Mascara(lips);
    FjhApp::Perfume *per = new FjhApp::Perfume(mas);

    myWife = per;
    myWife->lookIntoTheMirror();
    
    return 0;
}