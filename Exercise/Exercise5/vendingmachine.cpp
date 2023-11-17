#include <iostream>
#include <string>
#include "vendingmachine.h"
using namespace std;

string foodTypeToString(FoodType foodType)
{
    switch (foodType)
    {
    case Latte:
        return "Latte";
    case Cappuccino:
        return "Cappuccino";
    case Americano:
        return "Americano";
    case Milk:
        return "Milk";
    case Chocolate:
        return "Chocolate";
    case Bread:
        return "Bread";
    case Chips:
        return "Chips";
    case InstantNoodle:
        return "InstantNoodle";
    case Biscuit:
        return "Biscuit";
    case Sandwich:
        return "Sandwich";
    default:
        return "Unknown";
    }
}

VendingMachine::VendingMachine()
{
    for (int i = 0; i < MAX_TYPE; i++)
    {
        price[i] = 0;
    }
    this->type = Latte;
}

void VendingMachine::setPrice(FoodType newtype, int newprice)
{
    if (newtype >= MAX_TYPE)
    {
        throw Exception("Exceed maximum type!");
    }
    price[newtype] = newprice;
    if (newprice > 0 && newtype > type)
        this->type = newtype;
}

int VendingMachine::getPrice(FoodType myType) const
{
    if (myType > this->type)
    {
        throw Exception("No food of such type!");
    }
    return price[myType];
}

void VendingMachine::print() const
{
    for (int j = Sandwich; j >= 0; j--)
    {
        if (price[j] > 0)
        {
            cout << foodTypeToString(static_cast<FoodType>(j)) << " $" << price[j] << endl;
        }
    }
}

FoodType VendingMachine::getType() const
{
    return type;
}

CoffeeVendor::CoffeeVendor()
{
    setPrice(Americano, 1);
    setPrice(Latte, 0);
    setPrice(Cappuccino, 0);
    this->type = Americano;
}

void CoffeeVendor::setPrice(FoodType coffeeType, int coffeePrice)
{
    if (coffeeType != Americano && coffeeType != Latte && coffeeType != Cappuccino)
    {
        throw Exception("Exceed maximum type!");
    }
    if (coffeeType == Americano && coffeePrice == 0)
    {
        throw Exception("No Americano!");
    }
    VendingMachine::setPrice(coffeeType, coffeePrice);
}

void CoffeeVendor::print() const
{
    for (int k = getType(); k >=Latte; k--)
    {
        if (getPrice(static_cast<FoodType>(k)) > 0)
        {
            cout << foodTypeToString(static_cast<FoodType>(k)) << " $" << getPrice(static_cast<FoodType>(k)) << endl;
        }
    }
}

int main()
{
    CoffeeVendor coffeeVendor;
    VendingMachine vendingmachine;
    // 设置咖啡价格
    coffeeVendor.setPrice(Latte, 3);
    coffeeVendor.setPrice(Cappuccino, 4);
    coffeeVendor.setPrice(Americano, 2);
    vendingmachine.setPrice(Sandwich,5);
    vendingmachine.setPrice(Chocolate,0);
    vendingmachine.setPrice(Latte,1);

    // 打印咖啡菜单
    // vendingmachine.print();
    coffeeVendor.print();
    return 0;
}