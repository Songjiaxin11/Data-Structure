#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

// record a call as an event
struct Event
{
    int timeStamp;
    string name;
    string status;
    int duration;
};

/**
 * @brief Check if there is a call at this tick
 *
 * @param eventList
 * @param tick
 * @return true
 * @return false
 */
bool checkCall(Dlist<Event> &eventList, int tick)
{
    if (eventList.isEmpty())
        return false;

    // Read events at this tick
    Event *tempEvent = eventList.removeFront();
    if (tempEvent->timeStamp > tick)
    {
        eventList.insertFront(tempEvent);
        return false;
    }

    // insert back to eventList
    eventList.insertFront(tempEvent);
    return true;
}

int main()
{
    // construct four lists of events and one for printing
    Dlist<Event> regularList;
    Dlist<Event> silverList;
    Dlist<Event> goldList;
    Dlist<Event> platinumList;
    Dlist<Event> printList;

    // read in the events
    int numEvents;
    cin >> numEvents;
    if (numEvents == 0) // no events, print tick #0 and exit
    {
        cout << "Starting tick #0" << endl;
        return 0;
    }
    for (int i = 0; i < numEvents; i++)
    {
        Event *event = new Event;
        for (int j = 0; j < 4; j++)
        {
            switch (j)
            {
            case 0:
                cin >> event->timeStamp;
                break;
            case 1:
                cin >> event->name;
                break;
            case 2:
                cin >> event->status;
                break;
            case 3:
                cin >> event->duration;
                break;
            default:
                break;
            }
        }
        if (event->status == "regular")
            regularList.insertBack(event);
        else if (event->status == "silver")
            silverList.insertBack(event);
        else if (event->status == "gold")
            goldList.insertBack(event);
        else if (event->status == "platinum")
            platinumList.insertBack(event);

        // event for print
        Event *event_Print = new Event(*event);
        printList.insertBack(event_Print);
    }

    // simulate the events
    int tick = 0;
    int inQueue = 0;
    Event *currentEvent = NULL;
    bool busy = false;
    while (true)
    {
        if (printList.isEmpty() && inQueue == 0 && currentEvent == NULL)
            break;
        cout << "Starting tick #" << tick << endl;

        // check whether busy
        if (currentEvent == NULL)
            busy = false;
        else if (currentEvent->duration == 0)
        {
            busy = false;
            delete currentEvent;
            currentEvent = NULL;
            if (inQueue > 0)
                inQueue--;
        }
        else if (currentEvent->duration > 0)
            busy = true;

        // print call and add to Queue
        while (checkCall(printList, tick))
        {
            Event *tempEvent = printList.removeFront();
            cout << "Call from " << tempEvent->name << " a " << tempEvent->status << " member" << endl;
            delete tempEvent;
            inQueue++;
        }

        // if not busy, get the next event
        if (!busy)
        {
            if (checkCall(platinumList, tick))
                currentEvent = platinumList.removeFront();
            else if (checkCall(goldList, tick))
                currentEvent = goldList.removeFront();
            else if (checkCall(silverList, tick))
                currentEvent = silverList.removeFront();
            else if (checkCall(regularList, tick))
                currentEvent = regularList.removeFront();
            if (currentEvent != NULL)
            {
                cout << "Answering call from " << currentEvent->name << endl;
                currentEvent->duration--;
            }
        }
        else
        {
            if (currentEvent != NULL)
                currentEvent->duration--;
        }
        tick++;
    }
    return 0;
}