#include "raylib.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void) {

    InitWindow(800, 800, "wise tree 2");
    ToggleBorderlessWindowed();

    const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    const int screenHeight = GetMonitorHeight(GetCurrentMonitor());
      
    const int expanseWidth = screenWidth / 8;
    const int expanseHeight = screenWidth / 15;

    std::srand(std::time(nullptr));
    const int randWidth = expanseWidth + (std::rand() % ((screenWidth / 2) - expanseWidth));
    const int randHeight = (screenHeight / 2) + std::rand() % (screenHeight / 2 - expanseHeight);
    const int randWidth2 = (screenWidth / 2) + (std::rand() % ((screenWidth / 2) - expanseWidth));
    const int randHeight2 = (screenHeight / 2) + std::rand() % (screenHeight / 2 - expanseHeight);

    /*Texture2D texture = LoadTexture("cokey.png");*/
    Image image = LoadImage("cokey.png"); 
    ImageResize(&image, screenWidth, screenHeight);

    Texture2D texture = LoadTextureFromImage(image);

    UnloadImage(image);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, 0, 0, WHITE);

            DrawRectangle(randWidth - expanseWidth, randHeight - expanseHeight, expanseWidth, expanseHeight, LIME);
            DrawRectangle(randWidth2 - expanseWidth, randHeight2 - expanseHeight, expanseWidth, expanseHeight, RED);

            //DrawText("this IS a texture!", 360, 370, 10, GRAY);

        EndDrawing();
    }

    UnloadTexture(texture);

    CloseWindow();

    return 0;
}
