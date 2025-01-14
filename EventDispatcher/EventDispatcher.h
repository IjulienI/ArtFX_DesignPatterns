#pragma once
#include <vector>

#include "IObserver.h"

class EventDispatcher
{
private:
    std::vector<IObserver*> events; 
public:
    EventDispatcher() = default;
    
    void BindEvent(IObserver* listener);
    void UnBindEvent(IObserver* listener);
    void CallEvent();
};
