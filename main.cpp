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

    const int random = std::rand() % 2; // 0 = yes, 1 = no

    // Textures

    std::srand(std::time(nullptr));
    const int randWidth = expanseWidth + (std::rand() % ((screenWidth / 2) - expanseWidth));
    const int randHeight = (screenHeight / 2) + std::rand() % (screenHeight / 2 - expanseHeight);
    const int randWidth2 = (screenWidth / 2) + (std::rand() % ((screenWidth / 2) - expanseWidth));
    const int randHeight2 = (screenHeight / 2) + std::rand() % (screenHeight / 2 - expanseHeight);

    Image image = LoadImage("cokey.png"); 
    ImageResize(&image, screenWidth, screenHeight);

    Texture2D texture = LoadTextureFromImage(image);

    UnloadImage(image);

    // Audio

    InitAudioDevice();

    Sound bg = LoadSound("roddy_rich_new_beat.wav");
    Sound scream = LoadSound("mosquito.wav");

    // Font

    /*Font font = LoadFont("arial.ttf");*/

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        /*if (!IsSoundPlaying(bg)) PlaySound(bg);*/

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            /*if (GetMouseX() )*/
        }

        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(texture, 0, 0, WHITE);

            DrawRectangle(randWidth - expanseWidth, randHeight - expanseHeight, expanseWidth, expanseHeight, LIME);
            DrawText("Yes", (randWidth - expanseWidth) + (expanseWidth / 2) - (MeasureText("Yes", 40) / 2), (randHeight - expanseHeight) + (expanseHeight / 2.5), 40, BLACK);
            DrawRectangle(randWidth2 - expanseWidth, randHeight2 - expanseHeight, expanseWidth, expanseHeight, RED);
            DrawText("No", (randWidth2 - expanseWidth) + (expanseWidth / 2) - (MeasureText("No", 40) / 2), (randHeight2 - expanseHeight) + (expanseHeight / 2.5), 40, BLACK);

            DrawRectangle(screenWidth / 2 - (expanseWidth * 2), expanseHeight, expanseWidth * 4, expanseHeight * 2, LIGHTGRAY);
            DrawText("Are you still playing?", screenWidth / 2 - (MeasureText("Are you still playing?", 60) / 2), expanseHeight * 2, 60, BLACK);

        EndDrawing();

    }

    UnloadTexture(texture);
    UnloadSound(bg);
    UnloadSound(scream);
    /*UnloadFont(font);*/

    CloseAudioDevice();

    CloseWindow();

    return 0;
}
