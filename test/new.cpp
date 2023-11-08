#include <iostream>
using namespace std;

const int MAXIMUM = 100;
class IntSet
{
private:
    int number;
    int arr[MAXIMUM];

public:
    IntSet();
    int size() const;
};
IntSet::IntSet():number(0)
{
    for (int i=0;i<MAXIMUM;i++)
    {
        arr[i]=i;
        number++;
    }

};
int IntSet::size()
{
    return number;
}
int main()
{
    IntSet set;
    cout << set.size() << endl;
    // IntSet();

    return 0;
}