#include "raylib.h"
#include <iostream>
#include "GameLogic/GameManager.h"
#include <string>
#include "Inputs/Controller.h"
#include "Debug/Log.h"

int main()
{    
    Controller* controller = new Controller();
    GameManager* gameManager = new GameManager();

    gameManager->playerInputs = controller->GetInputQueueRef();
    controller->BindEnterEvent(gameManager);
    controller->SetIngredientsAmount(gameManager->GetIngredientsAmountRef());

    InitWindow(800, 600, "Spooky Restaurant!");
    SetTargetFPS(16);

    //Generate Recipe
    gameManager->GenerateMeal();

    //GameLoop
    while (!WindowShouldClose()) {         
        BeginDrawing();  
        
        //GameSequence
        while (gameManager->GetInvalidMeal())
        {
            BeginDrawing();
            
            controller->HandleInputs();
            
            ClearBackground(BLACK);
        
            EndDrawing();
        }

        ClearBackground(BLACK);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}