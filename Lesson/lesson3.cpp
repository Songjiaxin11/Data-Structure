/*
const与指针
指针和它指向的值都可以是const, 
1.指针是const, 一旦得到了某个变量的地址, 则不能再指向其他变量, 即 p 是只读的, 不可以做左值, *p(它指向的东西的值)是可以改变的
int* const p = &i;//p是const
*p=22;//ok
i=26;//ok
p++;  //No, p cannot be an lvalue
p = &j;//No
2. 所指是const, 表示不能通过指针去改变那个变量(变量本身不是const)
const int* q = &i; //即*q 是const 
*q = 22;//No, *q can't be an rvalue
i=26;//ok
q = &j;//ok q可以指向其他的东西
*/
// int i;
// const int* p1 = &i;//通过指针不可修改
// int const* p2 = &i;//通过指针不可修改
// //以上两行没有区别
// int *const p3 = &i;//指针不可修改
// // 看const在*的前面还是后面, 如果const在* 的前面, 则通过指针不可修改变量的值; const在* 后面, 则指针不可修改

// //可以把非const的值转换为const的, 当传递的参数类型比地址大的时候, 可以避免函数对外面的变量的意外修改
// void f(const int *x)//是一个guarantee, 函数保证不会通过 *x 修改外面的变量
// {
//     // *x = 100; //No
//     int y = *x;
//     y = 100; 
// }
// //可以类比为数组, 数组的名字就是一个指针, 但是数组的名字是const的, 不能修改, 但是数组里面的值是可以修改的
// int a[10];
// int *p = a;//ok
// int *const p = a;//ok
// int const *p = a;//ok
// int const *const p = a;//ok
// a = &i;//No a 不可以做左值
// //但是a[0], a[1]是变量, 是可以修改的
// int sum(const int a[], int lengh);//保证不会对a[]里面的值进行修改
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int cnt=0;
    void* p=0;
    while((p=malloc(0)))
    {
        cout<<p<<endl;
        cnt++;
    }
    // free(p);
    cout<<"分配了"<<cnt<<"MB空间"<<endl;
    return 0;
}