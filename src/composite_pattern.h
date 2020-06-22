#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>

namespace FjhApp {
class Company
{
public:
    Company(std::string name) { m_name = name; }
    virtual ~Company(){}
    virtual void Add(Company *pCom){}
    virtual void Show(int depth) {}
protected:
    std::string m_name;
};

//具体公司
class ConcreteCompany : public Company
{
public:
    ConcreteCompany(std::string name): Company(name) {}
    virtual ~ConcreteCompany() {}
    void Add(Company *pCom) { m_listCompany.push_back(pCom); } //位于树的中间，可以增加子树
    void Show(int depth)
    {
        for(int i = 0;i < depth; i++)
            std::cout << "-";
        std::cout << m_name << std::endl;
        std::list<Company *>::iterator iter = m_listCompany.begin();
        for(; iter != m_listCompany.end(); iter++) //显示下层结点
            (*iter)->Show(depth + 2);
    }
private:
    std::list<Company *> m_listCompany;
};

//具体的部门，财务部
class FinanceDepartment : public Company
{
public:
    FinanceDepartment(std::string name):Company(name){}
    virtual ~FinanceDepartment() {}
    virtual void Show(int depth) //只需显示，无限添加函数，因为已是叶结点
    {
        for(int i = 0; i < depth; i++)
            std::cout << "-";
        std::cout << m_name << std::endl;
    }
};

//具体的部门，人力资源部
class HRDepartment :public Company
{
public:
    HRDepartment(std::string name):Company(name){}
    virtual ~HRDepartment() {}
    virtual void Show(int depth) //只需显示，无限添加函数，因为已是叶结点
    {
        for(int i = 0; i < depth; i++)
            std::cout << "-";
        std::cout << m_name << std::endl;
    }
};

} //FjhApp

// 测试用例:
// #include <iostream>
// #include "Src/composite_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     FjhApp::Company *root = new FjhApp::ConcreteCompany("总公司");
//     FjhApp::Company *leaf1=new FjhApp::FinanceDepartment("财务部");
//     FjhApp::Company *leaf2=new FjhApp::HRDepartment("人力资源部");
//     root->Add(leaf1);
//     root->Add(leaf2);

//     //分公司A
//     FjhApp::Company *mid1 = new FjhApp::ConcreteCompany("分公司A");
//     FjhApp::Company *leaf3=new FjhApp::FinanceDepartment("财务部");
//     FjhApp::Company *leaf4=new FjhApp::HRDepartment("人力资源部");
//     mid1->Add(leaf3);
//     mid1->Add(leaf4);
//     root->Add(mid1);

//     //分公司B
//     FjhApp::Company *mid2=new FjhApp::ConcreteCompany("分公司B");
//     FjhApp::FinanceDepartment *leaf5=new FjhApp::FinanceDepartment("财务部");
//     FjhApp::HRDepartment *leaf6=new FjhApp::HRDepartment("人力资源部");
//     mid2->Add(leaf5);
//     mid2->Add(leaf6);
//     root->Add(mid2);
//     root->Show(0);

//     delete leaf1; delete leaf2;
//     delete leaf3; delete leaf4;
//     delete leaf5; delete leaf6;
//     delete mid1; delete mid2;
//     delete root;


//     return 0;
// }

// 输出:
// 设计模式测试用例
// 总公司
// --财务部
// --人力资源部
// --分公司A
// ----财务部
// ----人力资源部
// --分公司B
// ----财务部
// ----人力资源部