// #include <iostream>
// using namespace std;
// //数组作为函数参数时, 不可以在[]中指定数组的大小, 因为数组作为函数参数时, 传递的是数组的首地址, 而不是整个数组, 所以函数内部无法得知数组的大小.
// //如果要在函数内部得知数组的大小, 可以在函数参数中传递数组的大小, 或者在数组中使用特殊值作为数组的结束标志. 不可以再利用sizeof()函数来计算数组的大小, 因为sizeof()函数计算的是数组的总大小, 而不是数组的元素个数.
// void f()
// {
//     int x;
//     int cnt[10];
//     for (int i=0;i<10;i++)
//     {
//         cnt[i]=0;
//     }//初始化数组 很重要
//     //向数组中输入数据
//     while(x!=-1)
//     {
//         if (x>=0&&x<=9)
//         {
//             cnt[x]++;
//         }
//         cin>>x;//循环时要记得下一个输入
//     }
//     //输出数组中的数据
//     for (int i=0;i<10;i++)
//     {
//         cout<<i<<":"<<cnt[i]<<endl;
//     }
//     cout<<sizeof(cnt[0])<<endl;
//     cout<<sizeof(cnt)<<endl;
// }
// int main()
// {
//     f();
//     return 0;
// }
// 素数的参数表 方法一
// #include <iostream>
// #include <cmath>
// using namespace std;
// int isPrime(int x, int KnownPrime[], int numberOfPrime)
// {
//     int ret = 1;
//     for (int i = 0; i < numberOfPrime; i++)
//     {
//         if (x % KnownPrime[i] == 0)
//         {
//             ret = 0;
//             break;
//         }
//     }
//     return ret; // return 1 为素数, 0为非素数
// }
// int main()
// {
// int number=1000;
// int prime[1000]={2};//素数表
// int numberOfPrime=1;//素数个数
// for (int i=3;i<=number;i++)
// {
//     if (isPrime(i,prime,numberOfPrime))
//     {
//         prime[numberOfPrime++]=i;
//     }
// }
// for(int i=0;i<numberOfPrime;i++)
// {
//     if (i%10==0)
//     {
//         cout<<endl;
//     }
//     cout<<prime[i]<<'\t';
// }
//     return 0;
// }
// 方法二
// #include <iostream>
// using namespace std;
// int main()
// {
//     int cnt=0;
//     int number = 100;
//     int prime[number];
//     for (int i = 0; i < number; i++)
//     {
//         prime[i] = {1};
//     } // 初始化数组, 素数为1, 非素数为0
//     int x = 2;
//     while (x < number)
//     {
//         for (int i = 2; x * i < number; i++)
//         {
//             prime[x * i] = 0;
//         }
//         x++;
//     }
//     for (int i=2;i<number;i++)
//     {
//         if(prime[i]==1)
//         {
//             cnt++;
//             cout<<i<<'\t';
//         }
//         if (cnt%5==0)
//         {
//             cout<<endl;
//         }
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
void swap(int a, int b)
{
    cout<<"function a="<<a<<'\t'<<"function b="<<b<<endl;
    int tempt;
    tempt=a;
    a=b;
    b=tempt;
    cout<<"function a="<<a<<'\t'<<"function b="<<b<<endl;
}//只是在函数的独立存储空间中发生了改变, 在main的独立空间中不变


void swap(int* a, int* b)
{
    cout<<"function a="<<*a<<'\t'<<"function b="<<*b<<endl;
    int tempt= *a;
    *a = *b;
    *b=tempt;
    cout<<"function a="<<*a<<'\t'<<"function b="<<*b<<endl;
}//传递地址, 地址指向的值发生改变, 在main的独立空间中也发生改变, 地址是从外部访问内部的一种方式
int main()
{
    int a = 1;
    int b = 2;
    swap(&a,&b);
    cout<<"main a="<<a<<'\t'<<"main b="<<b<<endl;
    return 0;
}
/*指针的运用场景
带回多个结果 因为函数只能返回一个结果
需要改变某个其他函数中的变量的值
*/
// 指针必须要初始化, 否则会指向一个随机的地址