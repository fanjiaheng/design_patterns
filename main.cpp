#include <iostream>
#include "src/interpreter_pattern.h"

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::Context* c = new FjhApp::Context();
    c->SetInput("Hello");
    c->SetOutput("World");

    FjhApp::AbstractExpression* exp1 = new FjhApp::TerminalExpression();
    FjhApp::AbstractExpression* exp2 = new FjhApp::NonterminalExpression(exp1);
    exp1->Interpret(c); // TerminalExpression: Hello, World
    exp2->Interpret(c); // NonterminalExpression: Hello, World
                        // TerminalExpression: Hello, World
    delete exp1;
    delete exp2;

    return 0;
}
