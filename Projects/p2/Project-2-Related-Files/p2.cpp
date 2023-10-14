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
        cout << "Size of rest: " << rest_size << endl;
        return 1 + rest_size;
    }
}


list_t append(list_t first, list_t second)
{
    if (list_isEmpty(first))
    {
        // If the first list is empty, simply return the second list
        return second;
    }
    else
    {
        // Get the first element of the first list
        int first_elt = list_first(first);

        // Recursively append the rest of the first list with the second list
        list_t rest_appended = append(list_rest(first), second);

        // Create a new list with the first element and the appended rest
        return list_make(first_elt, rest_appended);
    }
}
static bool list_equal(list_t l1, list_t l2)
// EFFECTS: returns true iff l1 == l2.
{
    if (list_isEmpty(l1) && list_isEmpty(l2))
    {
        return true;
    }
    else if (list_isEmpty(l1) || list_isEmpty(l2))
    {
        return false;
    }
    else if (list_first(l1) != list_first(l2))
    {
        return false;
    }
    else
    {
        return list_equal(list_rest(l1), list_rest(l2));
    }
}

list_t reverse(list_t list)
{
    if (list_isEmpty(list))
    {
        // If the list is empty, return an empty list
        return list_make();
    }
    else
    {
        // Reverse the rest of the list and append the first element at the end
        return append(reverse(list_rest(list)), list_make(list_first(list), list_make()));
    }
}

int main()
{
    int i;
    list_t listA, listA_answer;
    list_t listB, listB_answer;
    listA = list_make();
    listB = list_make();
    listA_answer = list_make();
    listB_answer = list_make();
    for (i = 5; i > 0; i--)
    {
        listA = list_make(i, listA);
        listA_answer = list_make(6 - i, listA_answer);
        listB = list_make(i + 10, listB);
        listB_answer = list_make(i + 10, listB_answer);
    }
    for (i = 5; i > 0; i--)
    {
        listB_answer = list_make(i, listB_answer);
    }
    listB = append(listA, listB);
    listA = reverse(listA);
    if (!list_equal(listA, listA_answer))
        return -1;
    if (!list_equal(listB, listB_answer))
        return -1;
    return 0;
}