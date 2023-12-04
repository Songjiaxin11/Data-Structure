#include <iostream>
#include <string>
#include "dlist.h"
using namespace std;
/*
Steps:
1. Create a class Call
2. 从cin中读取数据, 创建call对象, 并插入到对应的dlist中
每次tick 的开始, 输出Starting tick #<tick>
3. 选择timestamps==tick number的人, 插入到dlist中
输出Call from Jeff a silver member  (按照出现顺序排序)
4. if(agent不忙)
{
    if(有电话)
    从最尊贵的开始回答, 输出Answering call from Jeff
    然后他就一直开始忙了, 忙到duration结束
else
{
    call, 
}
}
if(agent忙)
{
    不管时间, 继续接电话
}


*/
class Call
{
public:
    int timestamps;
    string name;
    string status;
    int duration;

    Call(int t, string n, string s, int d) : timestamps(t), name(n), status(s), duration(d) {}
};

// Function prototypes
void simulateCalls();

int main()
{
    simulateCalls();
    return 0;
}

void simulateCalls()
{
    Dlist<Call> platinum, gold, silver, regular;

    int numEvents;
    int tick = 0;
    cin >> numEvents;

    // int tickcnt = 0;
    // tickcnt = tick;

    // for (int i = 0; i < numEvents; ++i)
    // {
    //     while (tickcnt <= tick)
    //     {
    //         int timestamp, duration;
    //         string name, status;

    //         cin >> timestamp >> name >> status >> duration;
    //         if (tickcnt == tick)
    //             cout << "Starting tick #" << tick << endl;

    //         if (status == "platinum")
    //         {
    //             platinum.insertBack(new Call(name, status, duration));
    //             if (tick == timestamp)
    //             {
    //                 tickcnt++;
    //                 cout << "Call from " << name << " a " << status << " member" << endl;
    //             }
    //         }
    //         else if (status == "gold")
    //         {
    //             gold.insertBack(new Call(name, status, duration));
    //             if (tick == timestamp)
    //             {
    //                 tickcnt++;
    //                 cout << "Call from " << name << " a " << status << " member" << endl;
    //             }
    //         }
    //         else if (status == "silver")
    //         {
    //             silver.insertBack(new Call(name, status, duration));
    //             if (tick == timestamp)
    //             {
    //                 tickcnt++;
    //                 cout << "Call from " << name << " a " << status << " member" << endl;
    //             }
    //         }
    //         else if (status == "regular")
    //         {
    //             regular.insertBack(new Call(name, status, duration));
    //             if (tick == timestamp)
    //             {
    //                 tickcnt++;
    //                 cout << "Call from " << name << " a " << status << " member" << endl;
    //             }
    //         }
    //     }

    //     int currentTime = 0;
    //     Call *currentCall = nullptr;
    //     int repeat = 0;
    //     while (!(platinum.isEmpty() && gold.isEmpty() && silver.isEmpty() && regular.isEmpty()) && repeat == 0)
    //     {
    //         // cout << "Starting tick #" << currentTime << endl;

    //         if (currentCall == nullptr)
    //         {
    //             if (!platinum.isEmpty())
    //             {
    //                 currentCall = platinum.removeFront();
    //             }
    //             else if (!gold.isEmpty())
    //             {
    //                 currentCall = gold.removeFront();
    //             }
    //             else if (!silver.isEmpty())
    //             {
    //                 currentCall = silver.removeFront();
    //             }
    //             else if (!regular.isEmpty())
    //             {
    //                 currentCall = regular.removeFront();
    //             }

    //             if (currentCall != nullptr)
    //             {
    //                 cout << "Answering call from " << currentCall->name << endl;
    //                 repeat = 1;
    //             }
    //         }
    //     } // while answer

    //     if (currentCall != nullptr)
    //     {
    //         currentCall->duration--;

    //         if (currentCall->duration == 0)
    //         {
    //             delete currentCall;
    //             currentCall = nullptr;
    //         }
    //     }

    //     currentTime++;
    //     tick++;
    // }
    return 0;
}

// cout << "Starting tick #" << currentTime << endl; // Print the last tick
