#include "GameManager.h"

#include <iostream>

#include "../Debug/Log.h"

void GameManager::GenerateMeal()
{
    std::deque<int> result;
    for(int i = 0 ; i < ingredientsAmount ; i++)
    {
        result.push_back(rand() % 4);
    }
    Log::PrintLog(LOG_Game, std::format("Order : {}",Log::ToString(result)));
    
    meal = result;
}

void GameManager::CompareRecipe(std::deque<int>* input)
{
    if(input->size() < 4)
    {
        Log::PrintLog(LogType::LOG_Game,std::format("Dirty Meal"));
        input->clear();
        GenerateMeal();
        return;
    }
    int result = 0;
    while (!meal.empty())
    {
        if(meal.front() == input->front()) result ++;

        meal.pop_front();
        input->pop_front();
    }    
    Log::PrintLog(LogType::LOG_Game,std::format("Good Ingredients : {}/{}",result, ingredientsAmount));
    if(result == ingredientsAmount) ingredientsAmount++;
    GenerateMeal();
}

bool GameManager::GetInvalidMeal()
{
    return bInvalidMeal;
}

int* GameManager::GetIngredientsAmountRef()
{
    return &ingredientsAmount;
}

std::deque<int> GameManager::GetMeal()
{
    return meal;
}

void GameManager::OnNotify()
{
    Log::PrintLog(LogType::LOG_Default,std::format("OnReceiveNotify"));
    CompareRecipe( playerInputs);
}
