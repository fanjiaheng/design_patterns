#pragma once

#include <iostream>
#include <string>
#include <list>

namespace FjhApp
{
    class Element;

    // 抽象访问者（Visitor）角色：声明了一个或者多个访问操作，形成所有的具体元素角色必须实现的接口。
    class Visitor
    {
    public:
        virtual void Visit(Element *element){};
    };

    // 抽象节点（Element）角色：声明一个接受操作，接受一个访问者对象作为一个参量。
    class Element
    {
    public:
        virtual void Accept(Visitor *visitor){};
    };

    // 具体节点（ConcreteElement）角色：实现了抽象元素所规定的接受操作。
    class Employee : public Element
    {
    public:
        std::string name;
        double income;
        int vacationDays;

    public:
        Employee(std::string name, double income, int vacationDays)
        {
            this->name = name;
            this->income = income;
            this->vacationDays = vacationDays;
        }

        void Accept(Visitor *visitor)
        {
            visitor->Visit(this);
        }
    };

    // 具体访问者：收入访客
    class IncomeVisitor : public Visitor
    {
    public:
        void Visit(Element *element)
        {
            Employee *employee = ((Employee *)element);
            employee->income *= 1.10;
            std::cout << employee->name << " 's new income: " << employee->income << std::endl;
        }
    };

    // 具体访问者：假期访客
    class VacationVisitor : public Visitor
    {
    public:
        void Visit(Element *element)
        {
            Employee *employee = ((Employee *)element);
            // Provide 3 extra vacation days
            employee->vacationDays += 3;
            std::cout << employee->name << " 's new vacation days: " << employee->income << std::endl;
        }
    };

    // 结构对象（ObiectStructure）角色：有如下的一些责任，可以遍历结构中的所有元素；如果需要，提
    // 供一个高层次的接口让访问者对象可以访问每一个元素；如果需要，可以设计成一个复合对象或者一个
    // 聚集，如列（List）或集合（Set）。
    class Employees
    {
    private:
        std::list<Employee *> employees;

    public:
        void Attach(Employee *employee)
        {
            employees.push_back(employee);
        }

        void Detach(Employee *employee)
        {
            employees.remove(employee);
        }

        void Accept(Visitor *visitor)
        {
            for (std::list<Employee *>::iterator it = employees.begin(); it != employees.end(); ++it)
            {
                (*it)->Accept(visitor);
            }
        }
    };

} // namespace FjhApp

// 测试用例：
// #include <iostream>
// #include "Src/visitor_pattern.h"

// using namespace std;

// int main(int argc, char **argv)
// {
//     std::cout << "设计模式测试用例" << std::endl;

//     FjhApp::Employees *e = new FjhApp::Employees();
//     e->Attach(new FjhApp::Employee("Tom", 25000.0, 14));
//     e->Attach(new FjhApp::Employee("Thomas", 35000.0, 16));
//     e->Attach(new FjhApp::Employee("Roy", 45000.0, 21));

//     // Create two visitors
//     FjhApp::IncomeVisitor *v1 = new FjhApp::IncomeVisitor();
//     FjhApp::VacationVisitor *v2 = new FjhApp::VacationVisitor();

//     // Employees are visited
//     e->Accept(v1);
//     e->Accept(v2);

//     return 0;
// }

// 输出：
// 设计模式测试用例
// Tom 's new income: 27500
// Thomas 's new income: 38500
// Roy 's new income: 49500
// Tom 's new vacation days: 27500
// Thomas 's new vacation days: 38500
// Roy 's new vacation days: 49500
