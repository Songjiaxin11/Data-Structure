#ifndef TRIINT_RECURSION_H
#define TRIINT_RECURSION_H
//递归状态类型
enum class RecursionState
{
    Continue,
    Stop
};
/**
 * @brief 结构体存放递归结果
 * 
 */
struct  RecursionResult
{
    int arr[3];//存储计算结果
    RecursionState state;//存储计算状态
};//存放递归的结果

RecursionResult continueRecursion(int value1, int value2, int value3);
RecursionResult stopRecursion(int returnValue);

typedef RecursionResult (*RecursionFunction)(int, int, int);//function pointer
int recurse(RecursionFunction f, int initialValue1, int initialValue2, int initialValue3);

#endif