#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

class Call
{
public:
    string name;
    string status;
    int duration;

    Call(string n, string s, int d) : name(n), status(s), duration(d) {}
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

    int tickcnt = 0;
    tickcnt = tick;

    for (int i = 0; i < numEvents; ++i)     
    {
        while (tickcnt <= tick)
        {
            int timestamp, duration;
            string name, status;

            cin >> timestamp >> name >> status >> duration;
            if (tickcnt == tick)
                cout << "Starting tick #" << tick << endl;

            if (status == "platinum")
            {
                platinum.insertBack(new Call(name, status, duration));
                if (tick == timestamp)
                {
                    tickcnt++;
                    cout << "Call from " << name << " a " << status << " member" << endl;
                }
            }
            else if (status == "gold")
            {
                gold.insertBack(new Call(name, status, duration));
                if (tick == timestamp)
                {
                    tickcnt++;
                    cout << "Call from " << name << " a " << status << " member" << endl;
                }
            }
            else if (status == "silver")
            {
                silver.insertBack(new Call(name, status, duration));
                if (tick == timestamp)
                {
                    tickcnt++;
                    cout << "Call from " << name << " a " << status << " member" << endl;
                }
            }
            else if (status == "regular")
            {
                regular.insertBack(new Call(name, status, duration));
                if (tick == timestamp)
                {
                    tickcnt++;
                    cout << "Call from " << name << " a " << status << " member" << endl;
                }
            }
        }

        int currentTime = 0;
        Call *currentCall = nullptr;
        int repeat = 0;
        while (!(platinum.isEmpty() && gold.isEmpty() && silver.isEmpty() && regular.isEmpty()) && repeat == 0)
        {
            // cout << "Starting tick #" << currentTime << endl;

            if (currentCall == nullptr)
            {
                if (!platinum.isEmpty())
                {
                    currentCall = platinum.removeFront();
                }
                else if (!gold.isEmpty())
                {
                    currentCall = gold.removeFront();
                }
                else if (!silver.isEmpty())
                {
                    currentCall = silver.removeFront();
                }
                else if (!regular.isEmpty())
                {
                    currentCall = regular.removeFront();
                }

                if (currentCall != nullptr)
                {
                    cout << "Answering call from " << currentCall->name << endl;
                    repeat = 1;
                }
            }
        } // while answer

        if (currentCall != nullptr)
        {
            currentCall->duration--;

            if (currentCall->duration == 0)
            {
                delete currentCall;
                currentCall = nullptr;
            }
        }

        currentTime++;
        tick++;
    }
}

// cout << "Starting tick #" << currentTime << endl; // Print the last tick
