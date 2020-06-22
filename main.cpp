#include <iostream>
#include "Src/visitor_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::Employees *e = new FjhApp::Employees();
    e->Attach(new FjhApp::Employee("Tom", 25000.0, 14));
    e->Attach(new FjhApp::Employee("Thomas", 35000.0, 16));
    e->Attach(new FjhApp::Employee("Roy", 45000.0, 21));

    // Create two visitors
    FjhApp::IncomeVisitor *v1 = new FjhApp::IncomeVisitor();
    FjhApp::VacationVisitor *v2 = new FjhApp::VacationVisitor();

    // Employees are visited
    e->Accept(v1);
    e->Accept(v2);

    return 0;
}