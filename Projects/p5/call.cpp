#include <iostream>
#include <string>
#include "dlist.h"
using namespace std;
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
    bool isEnd = false;
    bool direct = true;
    int numEvents;
    bool first_time = true;
    int tick = 0;
    int finish = 0; // 回答完的时间
    cin >> numEvents;

    // while (tick <= numEvents)
    while (true)
    {

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
            if (next_stamp == tick)
            {
                // direct = true;
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
            }
            else if (next_stamp > tick)
            {
                direct = false;
            }

            if (finish > tick)
            {
                // cout<<"finish > tick"<<endl;
                tick++;
                break;
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
//还在回答时, 不应进入这个if

            if (currentCall)
            {
                
                // finish += currentCall->duration;
                finish=tick+currentCall->duration;
                cout << "Answering call from " << currentCall->name <<endl;
                // cout<<"numEvents: "<<numEvents<<endl;   
                delete currentCall;
            }
            if (finish == tick && numEvents == 0)
            {
                isEnd = true;
                break;
            }
            tick++;
            break;
        } // next people end

        if (numEvents == 0 && isEnd)
        {
            break;
        }
    } // next round end
    // if (!direct)
    // {
    //     cout << "Starting tick #" << tick + 1 << endl;
    // }
    for (int i = 0; i < 4; i++)
        delete member[i];
}
