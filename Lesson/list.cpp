#include <iostream>
#include <cstdlib> // for atoi
#include <iomanip>
using namespace std;
// int main(int argc, char *argv[])
// {
//     if (argc != 4)
//     {
//         std::cerr << "Usage: " << argv[0] << " <operation> <operand1> <operand2>" << std::endl;
//         return 1;
//     }

//     char operation = argv[1][0];
//     int operand1 = std::atoi(argv[2]); // Convert string to integer
//     int operand2 = std::atoi(argv[3]); // Convert string to integer

//     int result;

//     switch (operation)
//     {
//     case '+':
//         result = operand1 + operand2;
//         break;
//     case '-':
//         result = operand1 - operand2;
//         break;
//     default:
//         std::cerr << "Invalid operation. Use '+' or '-'" << std::endl;
//         return 1;
//     }

//     std::cout << "Result: " << result << std::endl;
//     for (int i = 0; i < argc; i++)
//     {
//         cout<<"argv["<<i<<"]"<<"="<<argv[i]<<endl;
//         for (int j = 0; j < argc+10; j++)
//         {
//             cout << "argv["<<i<<"]"<<"["<<j<<"]"<<setw(2)<<argv[i][j] <<"  ";
//         }
//         cerr<<endl;
//     }
    
//     return 0;
// }
int main()
{
    int foo;
    double bar;
    string baz;
    cin>>foo>>bar>>baz;
    cout<<foo<<endl;
    // cout<<bar<<endl;
    // cout<<baz<<endl;
    return 0;
}