#include <iostream>
#include "triint_recursion.h"
using namespace std;

/**
 * @brief 创建继续递归的RecursionResult类型, 用于将值存储在arr中, 并且将状态设置为Continue
 * 
 * @param value1 分别代表什么?
 * @param value2 
 * @param value3 
 * @return RecursionResult 
 */
RecursionResult continueRecursion(int value1, int value2, int value3)
{
    RecursionResult result;
    result.arr[0] = value1;
    result.arr[1] = value2;
    result.arr[2] = value3;
    result.state = RecursionState::Continue;
    return result;
}
/**
 * @brief 停止递归
 * 
 * @param returnValue 
 * @return RecursionResult 
 */
RecursionResult stopRecursion(int returnValue)
{
    RecursionResult result;
    result.arr[0] = returnValue;
    result.state = RecursionState::Stop;
    return result;
}

/**
 * @brief 
 * 
 * @param f function pointer
 * 状态是Continue, 则继续递归
 * @return int 
 */
int recurse(RecursionFunction f, int initialValue1, int initialValue2, int initialValue3)
{
    RecursionResult result = f(initialValue1, initialValue2, initialValue3);
    if (result.state == RecursionState::Stop)
    {
        return result.arr[0];
    }
    else
    {
        return recurse(f, result.arr[0], result.arr[1], result.arr[2]);
    }
}
RecursionResult factorial(int n, int acc, int _)
    {
        if (n == 0)
        {
            return stopRecursion(acc);
        }
        return continueRecursion(n - 1, acc * n, _);
    
    }
RecursionResult fibonacci(int n, int acc, int _)
{
    if (n == 0)
    {
        return stopRecursion(acc);
    }
    return continueRecursion(n - 1, _, acc + _);
}
int main()
{
    int result = recurse(factorial, 5, 3, 0);   
    cout<<result<<endl;
    return 0;
}