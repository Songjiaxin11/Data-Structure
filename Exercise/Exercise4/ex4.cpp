#include <iostream>
#include <string>
using namespace std;

string deleteWeird()
{
    string myInput;
    string filter_myInput = "";
    getline(cin, myInput);
    for (char temp : myInput)
    {
        if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9'))
        {
            filter_myInput += temp;
        }
    }
    return filter_myInput;
}

string selectLine(int *p)
{
    // int cnt = 0;
    string myInput;
    string filter_myInput = "";
    bool enter = true;          // 跟踪单次连续特殊符号
    bool another_Enter = false; // 跟踪下一次特殊符号
    getline(cin, myInput);
    for (char temp : myInput)
    {
        if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9'))
        {
            filter_myInput += temp;
            enter = true;
            another_Enter = false;
        }
        else
        {
            if (enter && !another_Enter)
            {
                if (temp != myInput[myInput.length() - 1])
                {
                    filter_myInput += '\n';
                    enter = true;
                    (*p)++;
                }
            }
            another_Enter = true;
        }
        // 处理边界条件, 当最后是特殊符号时, 不要换行, 不要计数
    }
    return filter_myInput;
}

int main(int argc, char *argv[])
{
    int cnt = 1;
    if (argc < 2)
    {
        cout << "No option!"<<endl;
        return 0;
    }
    if (argc > 2)
    {
        cout << "Too many options!"<<endl;
        return 0;
    }
    string option = argv[1]; // option的作用是用来判断是否有--help的参数
    if (argc == 2)
    {
        if (option == "--help" || option == "-h")
        {
            cout << "Delete weird characters in the message." << endl;
        }

        else if (option == "-s" || option == "--single")
        {
            cout << deleteWeird() << endl;
        }

        else if (option == "-m" || option == "--multiple")
        {
            string result = selectLine(&cnt);
            cout << result << endl;
            cout << cnt << endl;
        }
        else
        {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}