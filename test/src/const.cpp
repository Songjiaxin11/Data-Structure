// #include <iostream>
// using namespace std;

// int lvel = 10;
// const int &rvel; // 为什么这里的 &rvel的地址被改变了?
// // const int a;

// int main()
// {
//     cout << &rvel << endl;
//     lvel = 20;
//     cout << &rvel << endl;
//     cout << rvel << endl;
//     const int *ptr;
//     ptr = &lvel;
//     // int *const c;
//     // cout<<ptr<<endl;
//     // cout<<rvel<<endl;
//     //     cout<<&rvel<<endl;
//     //    const int &rvel=lvel+10;
//     // //    cout<<rvel<<endl;
//     //     cout<<&rvel<<endl;
//     cout << ptr << endl;
//     // cout << c << endl;
//     // cout << a << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int x = 0;
int *p = &x;
int y = 1;
p = &y;
*p = 2;
    return 0;
}
