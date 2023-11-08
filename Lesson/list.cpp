#include <iostream>
#include <cstdlib> // for atoi
#include <iomanip>
#include <fstream>
#include <sstream>
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
// int main()
// {
//     int foo;
//     double bar;
//     string baz;
//     cin>>foo>>bar>>baz;
//     cout<<foo<<endl;
//     // cout<<bar<<endl;
//     // cout<<baz<<endl;
//     return 0;
// }
ifstream iFile;
ofstream oFile;
int main()
{
    iFile.open("input.txt");
    oFile.open("output.txt");
    // int bar;
    // iFile >> bar;
    // oFile << bar << endl;
    // string baz;
    // while (getline(iFile, baz))
    // {
    //     oFile << baz << endl;
    // }
    // while(iFile)
    // {
    //     getline(iFile, baz);
    //     if(iFile)
    //     {
    //     oFile << baz << endl;
    //     cout<<baz<<endl;
    //     }
    // }
    // cout << "The output answer is " << bar << baz << endl;
    // iFile.close();
    // oFile.close();
    istringstream iStream;
    ostringstream oStream;
    int foo;
    double bar;
    char a;
    string baz;
    iStream.str("42 3.14 m this");
    iStream >> foo >> bar>>a>>baz;
    oStream << foo << " " << bar<<" "<<a<<" "<<baz<<endl;
    string result;
    result = oStream.str();
    cout<<result;
    return 0;
}