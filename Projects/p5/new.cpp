#include <iostream>
#include <string>
#include "dlist.h"
using namespace std;
/*
Steps:
1. Create a class Call ok
2. 从cin中读取数据, 创建call对象, 并插入到对应的dlist中 ok
每次tick 的开始, 输出Starting tick #<tick>
3. 选择timestamps==tick number的人, 插入到dlist中 ok
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
同时间按照顺序, 不同时间, 按照尊贵程度

*/
enum Status
{
    platinum,
    gold,
    silver,
    regular,
};
const char *status_name[] = {"platinum", "gold", "silver", "regular"};
Status Current_Status(string &str)
{
    for (int i = 0; i < 4; i++)
    {
        if (str == status_name[i])
        {
            return Status(i);
        }
    }
    return platinum;
}
class Call
{
public:
    int timestamps = 0;
    string name = "";
    Status status = regular;
    int duration = 0;
    // Call();
    Call(int t, string str, Status s, int d) : timestamps(t), name(str), status(s), duration(d) {}
    // ~Call();
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
    Dlist<Call> *member[4] = {};
    for (int i = 0; i < 4; i++)
    {
        member[i] = new Dlist<Call>; // remind to be delete
    }

    int numEvents;
    bool first_time = true;
    int tick = 0;
    int finish = 0; // 回答完的时间
    cin >> numEvents;

    // while (tick <= numEvents)
    while(true)
    {
        // cout << endl; // delete it
        cout << "Starting tick #" << tick << endl;
        for (int i = 0; i < 4; ++i)
        {

            int next_stamp, duration = 0;
            string name, status;
            Status sat;
            if (numEvents > 0 && first_time)
            {
                first_time = false;
                cin >> next_stamp;
            }
            while (next_stamp == tick && numEvents > 0)
            {
                cin >> name;
                cin >> status;
                sat = Current_Status(status);
                cin >> duration;
                auto now = new Call(next_stamp, name, sat, duration); // remind delete
                member[sat]->insertBack(now);

                cout << "Call from " << now->name << " a " << status << " member" << endl;
                numEvents--;
                if (numEvents > 0)
                {

                    cin >> next_stamp;
                }
             
            } // reading ends
               if (finish > tick)
                {
                    tick++;
                    continue;//?
                }
            Call *currentCall = nullptr;
            for (int i = 0; i < 4; i++)
            {
                if (!member[i]->isEmpty())
                {
                    currentCall = member[i]->removeFront();
                    break;
                }
            }
            if (currentCall)
            {
                cout << "Answering call from " << currentCall->name << endl;
                finish += currentCall->duration;
                delete currentCall;
            }
            if (finish == tick)
            {
                break;
            }
            tick++;
        } // next people end

    } // next round end

}
