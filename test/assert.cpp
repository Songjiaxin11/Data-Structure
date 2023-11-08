// // #include <iostream>
// // #define NDEBUG//它的作用等于g++ -DNDEBUG -o assert assert.cpp
// // #undef NDEBUG
// // #include <cassert>
// // using namespace std;
// // // Define it before including <cassert> to disable assert
// // int smaller(int a, int b)
// // {
// //     return a < b ? a : b;
// // }
// // int main(int argc, char *argv[])
// // {
// //     int a = 5;
// //     int b = 10;
// //     cout<<"input 2 numbers"<<endl;
// //     cin>>a>>b;
// //     assert(a<b);
// //     cout<<"success"<<endl;
// //     // int smaller = min(a, b);
// //     // assert(smaller <= a && smaller <= b && (smaller == a || smaller == b));
// //     // cout << "success" << endl;
// //     return 0;
// // }
// #include <iostream>
// #include <stdexcept>
// #include <string>
// class CustomException : public std::exception
// {
// private:
//     std::string message_;

// public:
//     CustomException(const std::string &message) : message_(message) {}
//     const char *what() const noexcept override
//     {
//         return message_.c_str();
//     }
// };

// int divide(int numerator, int denominator)
// {
//     if (denominator == 0)
//     {
//         throw CustomException("Division by zero is not allowed, written by sjx."); // throw 语句用于引发异常, 你可以使用 throw 来创建异常对象并将控制传递到匹配的 catch 块
//         // 从当前位置开始，沿调用堆栈向上搜索。这个搜索会一直持续，直到找到第一个匹配的 catch 块, 如果没有找到匹配的 catch 块，程序会终止
//     }
//     if (denominator == 2)
//     {
//         throw CustomException("Division by 2 is not allowed, written by sjx.");
//     }
//     std::cout << "Result: " << numerator / denominator << std::endl;
//     return numerator / denominator;
// }

// int factorial(int n)
// {
//     int result;
//     if(n<0) throw n;
//     for (int i = 1; i <= n; i++)
//     {
//         result *= i;
//     }
//     return result;
// }
// int main()
// {
//     try
//     {
//         factorial(-1);
//     }
//     catch(double v)
//     {
//         std::cout<<"error in double"<<v<<"fail1"<<std::endl;
//         throw v;
//     }
//     catch (char v)
//     {
//         std::cout<<"error in char"<<v<<"fail2"<<std::endl;
//         throw v;
//     }
//     catch(int v)
//     {
//         std::cout<<"error in int"<<v<<std::endl;
//     }

//     try
//     {
//         // Try block 1
//         divide(10, 0);
//     } // try 块是用于包裹可能会引发异常的代码的块
//     catch (const std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }
//      catch (const CustomException &e)
//     {
//         std::cerr << "Custom Exception caught: " << e.what() << std::endl;
//     }
//     // try
//     // {
//     //     // Try block 2
//     //     divide(20, 2);
//     // }
    
//     // catch (const std::exception &e) // 捕获std::exception及其派生类的异常, 比如
//     // {
//     //     std::cerr << "Exception caught in Try block 2: " << e.what() << std::endl;
//     // } // catch 块是用于处理异常的代码块。它指定了捕获和处理异常的方式。catch 块可以有多个，每个 catch 块都可以捕获不同类型的异常。

//     catch (...) // 这种调用将捕获任何类型的异常, 但不能直接访问异常对象, 需要调用what()来获取异常的描述信息
//     {
//         std::cerr << "Unknown Exception caught." << std::endl;
//     }
//     std::cout<<"I'm still executing"<<std::endl;
//     // try
//     // {
//     //     // Try block 3
//     //     int result = 5 / 0; // This will throw a different exception
//     //     std::cout << "Result: " << result << std::endl;
//     // }
//     // catch (const std::exception &e)
//     // {
//     //     std::cerr << "Exception caught in Try block 3: " << e.what() << std::endl;
//     // }
//     // catch (const std::runtime_error &e)
//     // {
//     //     std::cerr << "Runtime Error caught in Try block 3: " << e.what() << std::endl;
//     // }

//     return 0;
// }
