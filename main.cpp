#include <iostream>
#include "Src/product_register_template_and_singleton_factory_template.h"

using namespace std;

int main(int argc, char **argv)
{
    std::cout << "设计模式测试用例" << std::endl;


    // ========================== 生产耐克球鞋过程 ===========================//
   // 注册产品种类为Shoes（基类），产品为NiKe（子类）到工厂，产品名为nike
   FjhApp::ProductRegistrar<FjhApp::Shoes, FjhApp::NiKeShoes> nikeShoes("nike");
   // 从工厂获取产品种类为Shoes，名称为nike的产品对象
   FjhApp::Shoes *pNiKeShoes = FjhApp::ProductFactory<FjhApp::Shoes>::Instance().GetProduct("nike");
   // 显示产品的广告语
   pNiKeShoes->Show();
   // 释放资源
   if (pNiKeShoes)
   {
      delete pNiKeShoes;
   }

   // ========================== 生产优衣库衣服过程 ===========================//
   // 注册产品种类为Clothe（基类），产品为UniqloClothe（子类）到工厂，产品名为uniqlo
   FjhApp::ProductRegistrar<FjhApp::Clothe, FjhApp::UniqloClothe> adidasShoes("uniqlo");
   // 从工厂获取产品种类为Shoes，名称为adidas的产品对象
   FjhApp::Clothe *pUniqloClothe = FjhApp::ProductFactory<FjhApp::Clothe>::Instance().GetProduct("uniqlo");
   // 显示产品的广告语
   pUniqloClothe->Show();
   // 释放资源
   if (pUniqloClothe)
   {
      delete pUniqloClothe;
   }

    return 0;
}