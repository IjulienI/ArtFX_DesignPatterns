#include "Renderer.h"

Renderer::Renderer()
{
    CreateWindow();
    
    backgroundImage = LoadImageAnim("Textures/Background/bar.gif", &backgroundFrame);
    backgroundTexture = LoadTextureFromImage(backgroundImage);
}

void Renderer::Render()
{    
    BeginDrawing();  

    ClearBackground(BLACK);

    DrawTexture(backgroundTexture, 0, 0, WHITE);
        
    EndDrawing();
}

void Renderer::Update()
{
    backgroundFrame++;
    nextFrameDataOffset = backgroundImage.width*backgroundImage.height*4*backgroundFrame;

    if (backgroundFrame >= animFrames) currentAnimFrame = 0;

    UpdateTexture(backgroundTexture,((unsigned char *)backgroundImage.data) + nextFrameDataOffset);
}   

void Renderer::CreateWindow()
{    
    InitWindow(960, 540, "The Restaurant!");
    SetTargetFPS(16);
}
