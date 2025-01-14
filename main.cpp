#include "raylib.h"
#include <iostream>
#include "GameLogic/GameManager.h"
#include <string>
#include "Inputs/Controller.h"
#include "Debug/Log.h"
#include "Render/Renderer.h"

int main()
{    
    Controller* controller = new Controller();
    GameManager* gameManager = new GameManager();
    Renderer* renderer = new Renderer();

    gameManager->playerInputs = controller->GetInputQueueRef();
    controller->BindEnterEvent(gameManager);
    controller->SetIngredientsAmount(gameManager->GetIngredientsAmountRef());  

    //Generate Recipe
    gameManager->GenerateMeal();

    //GameLoop
    while (!WindowShouldClose()) {                 
        controller->HandleInputs();
        renderer->Update();
        renderer->Render();
    }

    CloseWindow();
    return 0;
}
