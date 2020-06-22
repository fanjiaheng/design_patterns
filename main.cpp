#include <iostream>
#include "src/memento_pattern.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

    FjhApp::GameRole *pLiXY = new FjhApp::GameRole(); // 创建李逍遥这个角色
    pLiXY->ShowState();               // 显示初始的状态

    // 存档
    FjhApp::RoleStateCaretaker *pRoleStateCaretaker = new FjhApp::RoleStateCaretaker();
    pRoleStateCaretaker->SetRoleStateMemento(pLiXY->SaveState());

    // 开始打大BOSS
    pLiXY->Fight();
    pLiXY->ShowState();

    // 读档，从新开始
    pLiXY->RecoveryState(pRoleStateCaretaker->GetRoleStateMemento());
    pLiXY->ShowState();

    return 0;
}