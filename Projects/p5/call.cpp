#include <iostream>
#include <cstdlib> // For atoi
// #include "dlist_impl.h"
#include "dlist.h"
using namespace std;

enum Status
{
    platinum,
    gold,
    silver,
    regular,
};
const char *status_name[] = {"platinum", "gold", "silver", "regular"};
struct Customer
{
    int timeStamp;
    string name;
    Status status;
    int duration;
};

Status getStatus(const string &status)
{
    if (status == "platinum")
    {
        return platinum;
    }
    else if (status == "gold")
    {
        return gold;
    }
    else if (status == "silver")
    {
        return silver;
    }
    else
    {
        return regular;
    }
}

int main()
{
    // int numCustomers;
    // string status_input;
    // cin >> numCustomers;
    // for (int i = 0; i < numCustomers; i++)
    // {
    //     Customer *c = new Customer;
    //     cin >> c->timeStamp;
    //     cin >> c->name;
    //     cin >> status_input;
    //     c->status = getStatus(status_input);    
    //     cin >> c->duration;
    // }
    return 0;
}