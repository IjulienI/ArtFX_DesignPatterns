#include "Controller.h"

#include <raylib.h>
#include "../Debug/Log.h"
#include <iostream>

void Controller::AddInputQueue(int inputKey)
{
        if(inputQueue.size() < *ingredientsAmount)
        {
                inputQueue.push_back(inputKey);
                Log::PrintLog(LogType::LOG_Game,std::format("{}", Log::ToString(inputQueue)));
                return;
        }
        Log::PrintLog(LogType::LOG_Game,std::format("Too many ingredients"));
}

void Controller::RemoveLastInput()
{
        inputQueue.pop_back();
        Log::PrintLog(LogType::LOG_Game,std::format("{}", Log::ToString(inputQueue)));
}

void Controller::HandleInputs()
{
        if (IsKeyPressed(KEY_UP)) AddInputQueue(0);
        if (IsKeyPressed(KEY_DOWN)) AddInputQueue(2);
        if (IsKeyPressed(KEY_LEFT)) AddInputQueue(1);
        if (IsKeyPressed(KEY_RIGHT)) AddInputQueue(3);
        if(IsKeyPressed(KEY_BACKSPACE) & !inputQueue.empty()) RemoveLastInput();
        if(IsKeyPressed(KEY_ENTER)) eventDispatcher.CallEvent();
}

void Controller::SetIngredientsAmount(int* amount)
{
        ingredientsAmount = amount;
}

std::deque<int> Controller::GetInputQueue()
{
        return inputQueue;
}

std::deque<int>* Controller::GetInputQueueRef()
{
        return &inputQueue;
}

void Controller::BindEnterEvent(IObserver* gm)
{
        eventDispatcher.BindEvent(gm);
}
