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
                }
                else // case '-':
                {
                    a = stack.removeFront();
                    b = stack.removeFront();
                    stack.insertFront(new int(*a - *b));
                    break;
                }
            }

            else if (operation >= '0' && operation <= '9')
            {
                // Convert char to int and push onto stack
                stack.insertFront(new int(operation - '0'));
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
                    int *one = stack.removeFront();
                    int *two = stack.removeFront();
                    stack.insertFront(new int(*one));
                    stack.insertFront(new int(*two));
                }
                    break;

                case '+':
                    // Implement addition
                    a = stack.removeFront();
                    b = stack.removeFront();
                    stack.insertFront(new int(*a + *b));
                    break;
                // case '-':
                //     // Implement subtraction
                //     a = stack.removeFront();
                //     b = stack.removeFront();
                //     stack.insertFront(new int(*a - *b));
                //     break;
                case '*':
                    // Implement multiplication
                    a = stack.removeFront();
                    b = stack.removeFront();
                    stack.insertFront(new int(*a * *b));
                    break;
                case '/':
                    // Implement division
                    a = stack.removeFront();
                    b = stack.removeFront();
                    stack.insertFront(new int(*a / *b));
                    break;

                    // one operand needed
                case 'n':
                    a = stack.removeFront();
                    stack.insertFront(new int(-(*a)));
                    break;

                case 'd':
                    if (!stack.isEmpty())
                    {
                        int *item = stack.removeFront();
                        // cout << *item << endl;
                        stack.insertFront(item);
                        stack.insertFront(item);
                    }
                    break;
                    //  no operands needed
                case 'c':
                    if (!stack.isEmpty())
                        stack.removeFront();
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

                case 'p':
                {
                    if (!stack.isEmpty())
                    {
                        int *item = stack.removeFront();
                        cout << *item << endl;
                        stack.insertFront(item);
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
