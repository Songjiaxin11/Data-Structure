#include "dlist.h"
#include <iostream>
#include <cstdlib> // For atoi
#include <sstream> // For istringstream
using namespace std;

// n d p只需要一个operands

int main()
{
    Dlist<int> stack;
    int *a = NULL;
    int *b = NULL;
    char operation;
    string input;
    bool once = false;
    bool twice = false;
    int count = 0;

    while (getline(cin, input) && input != "q")
    {
        istringstream iss(input);

        while (iss >> operation)
        {
            if (operation == '-')
            {
                // Handle negative numbers
                int num;
                if (iss >> num)
                {
                    stack.insertFront(new int(-num));
                    count++;
                }
                else // case '-':
                {
                    if (count < 2)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        a = stack.removeFront();
                        b = stack.removeFront();
                        stack.insertFront(new int(*a - *b));
                        count--;
                    }
                    break;
                }
            }

            else if (operation >= '0' && operation <= '9')
            {
                // Convert char to int and push onto stack
                stack.insertFront(new int(operation - '0'));
                count++;
            }
            else
            {
                switch (operation)
                {
                // case '0':
                // case '1':
                // case '2':
                // case '3':
                // case '4':
                // case '5':
                // case '6':
                // case '7':
                // case '8':
                // case '9':
                //     // Convert char to int and push onto stack
                //     stack.insertFront(new int(operation - '0'));
                //     break;

                // two operands needed
                case 'r':
                {
                    if (count < 2)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        int *one = stack.removeFront();
                        int *two = stack.removeFront();
                        stack.insertFront(new int(*one));
                        stack.insertFront(new int(*two));
                    }
                }
                break;

                case '+':
                    // Implement addition
                    if (count < 2)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        a = stack.removeFront();
                        b = stack.removeFront();
                        stack.insertFront(new int(*a + *b));
                        count--;
                    }
                    break;

                case '*':
                    // Implement multiplication
                    if (count < 2)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        a = stack.removeFront();
                        b = stack.removeFront();
                        stack.insertFront(new int(*a * *b));
                        count--;
                    }
                    break;
                case '/':
                    // Implement division
                    if (count < 2)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        a = stack.removeFront();
                        b = stack.removeFront();
                        stack.insertFront(new int(*a / *b));
                        count--;
                    }
                    break;

                    // one operand needed n d p
                case 'n':
                    if (count < 1)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        a = stack.removeFront();
                        stack.insertFront(new int(-(*a)));
                    }
                    break;

                case 'd': // 复制
                    if (count < 1)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        if (!stack.isEmpty())
                        {
                            int *item = stack.removeFront();
                            // cout << *item << endl;
                            stack.insertFront(item);
                            stack.insertFront(item);
                            count++;
                        }
                    }
                    break;

                case 'p':
                {
                    if (count < 1)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        if (!stack.isEmpty())
                        {
                            int *item = stack.removeFront();
                            cout << *item << endl;
                            stack.insertFront(item);
                        }
                    }
                }
                break;

                    //  no operands needed caq
                case 'c':
                    if (!stack.isEmpty())
                        stack.removeFront();
                    count = 0;
                    break;

                case 'a':
                {
                    Dlist<int> cur(stack); // 先复制一份
                    while (!cur.isEmpty())
                    {
                        int *item = cur.removeFront();
                        if (item != nullptr)
                        {
                            cout << *item << " " << flush;
                        }
                    }
                    cout << endl;
                    // remove cur all
                    while (!cur.isEmpty())
                    {
                        cur.removeFront();
                    }
                }
                break;

                default:
                    cout << "Bad input\n";
                } // switch ends
            }     // else ends
        }         // while ends
    }             // bit while ends

    return 0;
}
