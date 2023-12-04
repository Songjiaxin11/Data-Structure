#include "dlist.h"
#include <iostream>
#include <cstdlib> // For atoi
#include <string>
using namespace std;

// n d p只需要一个operands

int main()
{
    Dlist<int> stack;
    // int *a = NULL;
    // int *b = NULL;
    char operation;
    string input;
    bool isdig = false;
    // bool twice = false;
    int count = 0;

    while (getline(cin, input) && input != "q")
    {
        size_t pos = 0;

        // 如果input中第一个字符不是'-', 且是数字
        if (input[0] != '-' && input[0] >= '0' && input[0] <= '9')
        {
            for (int i = 0; i < static_cast<int>(input.size()); i++)
            {
                if (input[i] < '0' || input[i] > '9')
                {
                    cout << "Bad input\n";
                    isdig = false;
                    break;
                }
                isdig = true;
            }
            if (isdig)
            {
                int num = stoi(input, &pos);
                stack.insertFront(new int(num));
                count++;
            }
        }
        // 如果input中第一个字符是'-', 且是数字
        else if (input[0] == '-')
        {

            if (isdigit(input[pos + 1]))
            {

                for (int i = 1; i < static_cast<int>(input.size()); i++)
                {
                    if (input[i] < '0' || input[i] > '9')
                    {
                        cout << "Bad input\n";
                        isdig = false;
                        break;
                    }
                    isdig = true;
                }
                if (isdig)
                {
                    int num = stoi(input.substr(pos + 1), &pos);
                    stack.insertFront(new int(-num));
                    count++;
                }
            }

            else // case '-':是符号
            {
                if (input.size() != 1)
                {
                    cout << "Bad input\n";
                    break;
                }
                else
                {
                    if (count < 2)
                    {
                        cout << "Not enough operands\n";
                    }
                    else
                    {
                        int *m = stack.removeFront();
                        int *n = stack.removeFront();
                        int *result = new int((*m) - (*n));
                        stack.insertFront(result);
                        delete m;
                        delete n;
                        count--;
                    }
                    // break;
                }
            }
        } //'-' operation ends

        else // case '+', '*', '/', 'r', 'n', 'd', 'p', 'c', 'a'
        {
            if (input.size() != 1)
            {
                cout << "Bad input\n";
                // break;
            }
            else
            {
                while (pos < input.size())
                {
                    operation = input[pos];
                    switch (operation)
                    {

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
                            delete one;
                            delete two;
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
                            int *m = stack.removeFront();
                            int *n = stack.removeFront();
                            int *result = new int((*m) + (*n));
                            stack.insertFront(result);
                            delete m;
                            delete n;
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
                            int *m = stack.removeFront();
                            int *n = stack.removeFront();
                            int *result = new int((*m) * (*n));
                            stack.insertFront(result);
                            delete m;
                            delete n;
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
                            int *m = stack.removeFront();
                            if (*m == 0)
                            {
                                delete m;
                                cout << "Divide by zero\n";
                            }
                            else
                            {

                                int *n = stack.removeFront();
                                int *result = new int(*n / *m);
                                stack.insertFront(result);
                                delete m;
                                delete n;
                                count--;
                            }
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
                            int *aa = stack.removeFront();
                            stack.insertFront(new int(-(*aa)));
                            delete aa;
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
                                stack.insertFront(new int(*item));
                                stack.insertFront(new int(*item));
                                delete item;
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
                                stack.insertFront(new int(*item));
                                delete item;
                            }
                        }
                    }
                    break;

                        //  no operands needed caq
                    case 'c':
                        while (!stack.isEmpty())
                        {
                            int *kk = stack.removeFront();
                            delete kk;
                        }
                        count = 0;
                        break;

                    case 'a':
                    {

                        Dlist<int> cur(stack); // 先复制一份
                        while (!cur.isEmpty())
                        {
                            int *item = cur.removeFront();
                            cout << *item << " " << flush;
                            delete item;
                        }
                        cout << endl;
                    }
                    break;

                    default:
                        cout << "Bad input\n";
                    } // switch ends
                    pos++;
                } // else ends
            }     // operator number else ends
        }         // operator type else ends
                  // bit while ends
    }             // while ends
    return 0;
}
