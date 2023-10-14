#include <iostream>
#include <cstdlib>
#include "recursive.h"
#include "p2.h"
// no other libraries
using namespace std;
// no global variables

int size(list_t list)
{
    if (list_isEmpty(list))
    {
        return 0;
    }
    else
    {
        int rest_size = size(list_rest(list));
        return 1 + rest_size;
    }
}

list_t append(list_t list1, list_t list2)
{
    if (list_isEmpty(list1))
    {
        // If the list1 is empty, simply return the list2
        return list2;
    }
    else
    {
        // Get the first element of the list1
        int first_elt = list_first(list1);

        // Recursively append the rest of the list1 with the list2
        list_t rest_appended = append(list_rest(list1), list2);

        // Create a new list with the first element and the appended rest
        return list_make(first_elt, rest_appended);
    }
}

list_t reverse(list_t list)
{
    if (list_isEmpty(list))
    {
        return list_make(); // 递归结束, 即创造的开始, 新建一个list
    }
    else
    {
        // Reverse the rest of the list and append the first element at the end
        list_t list_back = list_make(list_first(list), list_make()); // 在每次添加元素后加一个新位置
        list_t list_front = reverse(list_rest(list));
        return append(list_front, list_back);
    }
}

int sum(list_t list)
{
    if (list_isEmpty(list))
    {
        return 0;
    }
    else
    {
        return list_first(list) + sum(list_rest(list));
    }
}

int product(list_t list)
{
    if (list_isEmpty(list))
    {
        return 1;
    }
    else
    {
        return list_first(list) * product(list_rest(list));
    }
}

list_t filter_odd(list_t list)
{
    if (list_isEmpty(list))
    {
        return list_make();
    }
    else
    {
        if (list_first(list) % 2 != 0)
        {
            return list_make(list_first(list), filter_odd(list_rest(list)));
        }
        else
        {
            return filter_odd(list_rest(list));
        }
    }
}

list_t filter_even(list_t list)
{
    if (list_isEmpty(list))
    {
        return list_make();
    }
    else
    {
        if (list_first(list) % 2 == 0)
        {
            return list_make(list_first(list), filter_even(list_rest(list)));
        }
        else
        {
            return filter_even(list_rest(list));
        }
    }
}

bool odd(int a)
{
    return a % 2 != 0;
}
bool even(int a)
{
    return a % 2 == 0;
}

list_t filter(list_t list, bool (*fn)(int))
{
    if (list_isEmpty(list))
    {
        return list_make();
    }
    else
    {
        if (fn(list_first(list)))
        {
            return list_make(list_first(list), filter(list_rest(list), fn));
        }
        else
        {
            return filter(list_rest(list), fn);
        }
    }
}

list_t insert_list(list_t first, list_t second, unsigned int n)
{
    if (list_isEmpty(first)) // 第一个条件
    {
        return second;
    }
    else if (n == 0) // 第二个条件n=0时, 直接把second接在first前面
    {
        return append(second, first);
    }
    else
    {
        return list_make(list_first(first), insert_list(list_rest(first), second, n - 1));
    }
}

list_t chop(list_t list, unsigned int n)
{
    if (size(list) <= n)
    {
        return list_make();
    }
    else
    {
        return list_make(list_first(list), chop(list_rest(list), n));
    }
}

// int main()
// {
//     int i;
//     list_t listA;
//     list_t listB;
//     list_t listE;
//     listA = list_make();
//     listB = list_make();
//     listE = list_make(); // An empty list
//     for (i = 5; i > 0; i--)
//     {
//         listA = list_make(i, listA);
//         listB = list_make(i + 10, listB);
//     }

//     cout << "listA";
//     list_print(listA);
//     cout << endl;
//     cout << "product of A " << product(listA) << endl;
//     cout << "product of E " << product(listE) << endl; // 空的难道是1吗?

//     cout << "listB";
//     list_print(listB);
//     cout << endl;
//     cout << "listE";
//     list_print(listE);
//     cout << endl;

//     listA = append(reverse(listA), listB);
//     cout << endl;
//     cout << "new listA";
//     list_print(listA);
//     cout << endl;
//     cout << "size_of A: " << size(listA) << endl;
//     cout << "size_of E: " << size(listE) << endl;
//     cout << "sum_of A: " << sum(listA) << endl;
//     // cout << "filter_odd of A: ";
//     // list_print(filter_odd(listA));
//     // cout << endl;
//     // cout << "filter_even of A: ";
//     // list_print(filter_even(listA));
//     // cout << endl;
//     // cout << "filter_even of E: ";
//     // list_print(filter_even(listE));
//     // cout << endl;
//     cout << "filter of A odd: ";
//     list_print(filter(listA, odd));
//     cout << endl;
//     cout << "filter of A even: ";
//     list_print(filter(listA, even));
//     cout << endl;
//     cout << "insert_list(listA, listB,3):";
//     list_print(insert_list(listA, listB, 3));
//     cout << endl;
//     cout << "chop(listB,3):";
//     list_print(chop(listB, 3));
//     cout << endl;
// }