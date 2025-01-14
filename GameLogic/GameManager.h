#pragma once
#include <deque>

#include "../EventDispatcher/IObserver.h"

class GameManager : public IObserver
{
private:
    bool bInvalidMeal = true;
    int ingredientsAmount = 4;
    
    void OnNotify() override; 
public:
    GameManager() = default;
    void GenerateMeal();

    std::deque<int>* playerInputs;
    std::deque<int> meal;

    void CompareRecipe(std::deque<int>* input);

    bool GetInvalidMeal();
    int* GetIngredientsAmountRef();

    std::deque<int> GetMeal();

   
};
