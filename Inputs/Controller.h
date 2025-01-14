#pragma once
#include <queue>

#include "../EventDispatcher/EventDispatcher.h"

class Controller
{
private:
    std::deque<int> inputQueue;
    EventDispatcher eventDispatcher;

    int* ingredientsAmount;

    void AddInputQueue(int inputKey);
    void RemoveLastInput();
public:
    Controller() = default;
    
    void HandleInputs();
    void SetIngredientsAmount(int* amount);
        
    std::deque<int> GetInputQueue();
    std::deque<int>* GetInputQueueRef();    

    void BindEnterEvent(IObserver* gm);
};
