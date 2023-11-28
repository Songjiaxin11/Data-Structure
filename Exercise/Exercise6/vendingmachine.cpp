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
/*
//Here are some modifications based on the previous exercise:
1. price : An dynamic array of positive integer representing the price of each type of food.
2. empty : True if there is no food exists in the current vending machine.
To avoid the mistakes and bugs that might occur, Kurumi has set the standard regulation of
invariants:
1. The vending machine is empty if and only if all the food has the price of 0.
2. Any type of food that is more delicious than the most delicious food that currently exists
must have the price of 0.
*/
VendingMachine::VendingMachine()
{

    // dynamic array of the price
    price = new int[MAX_TYPE];
    for (int i = 0; i < MAX_TYPE; i++)
    {
        price[i] = 0;
    }
    this->empty = true;
    this->type = Latte;
}

/**
 * @brief Overloaded Constructer. Initialize a vending machine with one type of food.
 * @param type
 * @param price
 * @throw If the given degree is greater or equal to MAX_TYPE, throw an
 * Exception object with error message "Exceed maximum type!".
 */
VendingMachine::VendingMachine(FoodType type, int price)
{
    if (type >= MAX_TYPE)
    {
        throw Exception("Exceed maximum type!");
    }
    this->price = new int[MAX_TYPE];
    this->price[0] = price;
    this->type = type;
    if (price == 0)
        this->empty = true;
    else
        this->empty = false;
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
            cout << "success" << endl;
        }
    }
}

FoodType VendingMachine::getType() const
{
    return this->type;
}

bool VendingMachine::isEmpty() const
{
    return this->empty;
}

bool VendingMachine::repOK()
{
    // 1. price : An dynamic array of positive integer representing the price of each type of food.
    // 2. empty : True if there is no food exists in the current vending machine.
    // Any type of food that is more delicious than the most delicious food that currently exists
    // must have the price of 0.
    if (this->empty)
    {
        for (int i = 0; i < MAX_TYPE; i++)
        {
            if (price[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    if (!this->empty)
    {
        if (price[this->type] == 0)
        {
            return false;
        }
        for (int i = 0; i < MAX_TYPE; i++)
        {
            if (price[i] < 0)
            {
                return false;
            }
            // Any type of food that is more delicious than the most delicious food that currently exists
            // must have the price of 0.
            if (i > type && price[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    return true;
}

VendingMachine::~VendingMachine()
{
    delete[] price;
}

// int main()
// {
//     int test_num;
//     cin >> test_num;
//     try
//     {
//         switch (test_num)
//         {
//         case 1:
//         {
//             VendingMachine p;
//             if (p.repOK())
//                 cout << "success" << endl;
//             p.print();
//         }
//         break;
//         case 2:
//         {
//             VendingMachine p(Milk, 2);
//             if (p.repOK())
//                 cout << "success" << endl;
//             p.print();
//         }
//         break;
//         case 3:
//         {
//             VendingMachine p(Latte, 1);
//             if (p.repOK())
//                 cout << "success";
//         }
//         }
//     }
//     catch (Exception &e)
//     {
//         cout << e.what();
//     }
//     cout << endl;
// }