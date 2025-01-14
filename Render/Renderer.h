#pragma once

#include <raylib.h>

class Renderer
{
private:
    int backgroundFrame = 0;
    unsigned int nextFrameDataOffset = 0;
    Image backgroundImage;
    Texture2D backgroundTexture;
public:
    Renderer();
    void Render();
    void Update();
    void CreateWindow();
};
