#include <iostream>
#include "src/bridge_pattern.h"

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;

	// 创建三种枪
	FjhApp::Gun_base* gun_01 = new FjhApp::Pistol();
	FjhApp::Gun_base* gun_02 = new FjhApp::Rifle();
	FjhApp::Gun_base* gun_03 = new FjhApp::Awp();

	// 创建三种战士
	FjhApp::Fighter_base* A = new FjhApp::Fighter_A();
	FjhApp::Fighter_base* B = new FjhApp::Fighter_B();
	FjhApp::Fighter_base* C = new FjhApp::Fighter_C();

	// 不同战士搭配不同枪械展示
	C->fight(gun_02);

	delete gun_01;
	delete gun_02;
	delete gun_03;

	delete A;
	delete B;
	delete C;

    return 0;
}
