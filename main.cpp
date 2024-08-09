

// Most hideous codebase oat
// lesson: why to plan out something before just doing it


#include "raylib.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

bool opened = true;
int frame = 0;

void draw(int random, int randWidth, int randHeight, int randWidth2, int randHeight2, Texture2D &texture, Sound &bg, Sound &scream) {

    const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    const int screenHeight = GetMonitorHeight(GetCurrentMonitor());
      
    const int expanseWidth = screenWidth / 8;
    const int expanseHeight = screenWidth / 15;

    /*if (!IsSoundPlaying(bg)) PlaySound(bg);*/

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if (
            random == 0 &&
            GetMouseX() > randWidth - expanseWidth &&
            GetMouseX() < randWidth - expanseWidth + expanseWidth &&
            GetMouseY() > randHeight - expanseHeight &&
            GetMouseY() < randHeight - expanseHeight + expanseHeight
        ) {
            opened = false;
            return;
        }
        else if (
            random == 1 &&
            GetMouseX() > randWidth2 - expanseWidth &&
            GetMouseX() < randWidth2 - expanseWidth + expanseWidth &&
            GetMouseY() > randHeight2 - expanseHeight &&
            GetMouseY() < randHeight2 - expanseHeight + expanseHeight
        ) {
            opened = false;
            return;
        }
        else {
            if (frame != 0) {
                PlaySound(scream);
            }
        }
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

    if (WindowShouldClose()) opened = false;

    frame++;

}

int main() {

    /*fuga();*/
    /*#ifdef _WIN32*/
    /*Sleep(3000);*/
    /*#else*/
    /*sleep(3);*/
    /*#endif*/
    /*ClearWindowState(FLAG_WINDOW_HIDDEN);*/

    std::srand(std::time(nullptr));

    InitWindow(800, 800, "wise tree 2");

    const int screenWidth = GetMonitorWidth(GetCurrentMonitor());
    const int screenHeight = GetMonitorHeight(GetCurrentMonitor());
      
    const int expanseWidth = screenWidth / 8;
    const int expanseHeight = screenWidth / 15;

    // Textures

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

    while (!WindowShouldClose()) {

        int randWidth = expanseWidth + (std::rand() % ((screenWidth / 2) - expanseWidth));
        int randHeight = (screenHeight / 2) + std::rand() % (screenHeight / 2 - expanseHeight);
        int randWidth2 = (screenWidth / 2) + (std::rand() % ((screenWidth / 2) - expanseWidth));
        int randHeight2 = (screenHeight / 2) + std::rand() % (screenHeight / 2 - expanseHeight);
        int random = std::rand() % 2; // 0 = yes, 1 = n

        ToggleBorderlessWindowed();
        while (opened) draw(random, randWidth, randHeight, randWidth2, randHeight2, texture, bg, scream);
        ToggleBorderlessWindowed();

        StopSound(bg);
        StopSound(scream);

        if (!IsWindowHidden()) {
            ClearWindowState(FLAG_WINDOW_TOPMOST);
            SetWindowState(FLAG_WINDOW_HIDDEN);
        }

        #ifdef _WIN32
        Sleep(3000);
        #else
        sleep(3);
        #endif

        ClearWindowState(FLAG_WINDOW_HIDDEN);
        SetWindowState(FLAG_WINDOW_TOPMOST);
        opened = true;
        frame = 0;

    }

    UnloadTexture(texture);
    UnloadSound(bg);
    UnloadSound(scream);
    /*UnloadFont(font);*/

    CloseAudioDevice();

    CloseWindow();

    return 0;

}
