#include <iostream>
#include "dlist.h"

using namespace std;



int main(int argc, char *argv[])
{
    Dlist<int> ilist;
    int *ip = new int(1);
    int *ip2 = new int(2);
    ilist.insertFront(ip);
    ilist.insertBack(ip2);
    if (ilist.isEmpty())
        cout << "Error: ilist is empty" << endl;

    // Test copy constructor
    Dlist<int> ilist2(ilist);
    if (ilist2.isEmpty())
        cout << "Error: ilist2 is empty" << endl;
    int *temp = ilist2.removeFront();
    if (*temp != *ip)
        cout << "Error: ilist2 removeFront" << endl;
    delete temp;
    delete ilist2.removeBack();
    if (!ilist2.isEmpty())
        cout << "Error: ilist2 is not empty" << endl;

    // Test assignment operator
    Dlist<int> ilist3;
    ilist3 = ilist;
    if (ilist3.isEmpty())
        cout << "Error: ilist3 is empty" << endl;
    temp = ilist3.removeBack();
    if (*temp != *ip2)
        cout << "Error: ilist3 removeBack" << endl;
    delete temp;
    delete ilist3.removeFront();
    if (!ilist3.isEmpty())
        cout << "Error: ilist3 is not empty" << endl;

    return 0;
}
