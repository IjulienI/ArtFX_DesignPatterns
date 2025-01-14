#include "EventDispatcher.h"

void EventDispatcher::BindEvent(IObserver* listener)
{
    events.push_back(listener);
}

void EventDispatcher::UnBindEvent(IObserver* listener)
{
    auto it = std::remove(events.begin(), events.end(), listener);
    events.erase(it, events.end());
}

void EventDispatcher::CallEvent()
{
    for(int i = 0; i < events.size(); i++)
    {
        events[i]->OnNotify();
    }
}
