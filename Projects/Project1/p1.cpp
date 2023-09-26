#include <iostream>
#include "io.h"

int main()
{
    // Get parameters from the user
    double prompt = GetParam("Please enter the monthly payment: ", 1, 1000000);
    double interest_rate = GetParam("Please enter the interest rate: ", 0, 1);
    int years = GetParam("Please enter the duration of the loan, in years: ", 1, 100);
    
    double monthrate = interest_rate / 12;
    double SumAmount = 0;
    PrintHeader();
    for(int i=years*12;i>0;i--)
    {
        double Principal=(prompt-SumAmount*monthrate)/(1+monthrate);
        double Interest=prompt-Principal;
        SumAmount+=Principal;
        PrintMonthlyData(i, Principal, Interest, SumAmount);
    }
    return 0;
}
