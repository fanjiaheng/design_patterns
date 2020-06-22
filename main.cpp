#include <iostream>
#include "Src/composite_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::Company *root = new FjhApp::ConcreteCompany("总公司");
    FjhApp::Company *leaf1=new FjhApp::FinanceDepartment("财务部");
    FjhApp::Company *leaf2=new FjhApp::HRDepartment("人力资源部");
    root->Add(leaf1);
    root->Add(leaf2);

    //分公司A
    FjhApp::Company *mid1 = new FjhApp::ConcreteCompany("分公司A");
    FjhApp::Company *leaf3=new FjhApp::FinanceDepartment("财务部");
    FjhApp::Company *leaf4=new FjhApp::HRDepartment("人力资源部");
    mid1->Add(leaf3);
    mid1->Add(leaf4);
    root->Add(mid1);

    //分公司B
    FjhApp::Company *mid2=new FjhApp::ConcreteCompany("分公司B");
    FjhApp::FinanceDepartment *leaf5=new FjhApp::FinanceDepartment("财务部");
    FjhApp::HRDepartment *leaf6=new FjhApp::HRDepartment("人力资源部");
    mid2->Add(leaf5);
    mid2->Add(leaf6);
    root->Add(mid2);
    root->Show(0);

    delete leaf1; delete leaf2;
    delete leaf3; delete leaf4;
    delete leaf5; delete leaf6;
    delete mid1; delete mid2;
    delete root;


    return 0;
}