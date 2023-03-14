/*******************************************************************************************
 *  Name: Ali Umar
 *  Title: Audio Visualizer
 *  Description: Visualize audio based on some quantity that represents the audio signal
 ********************************************************************************************/

#include <stdio.h>
#include "raylib.h"

int main(void)
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera");

  SetTargetFPS(60); 

  InitAudioDevice();
  if (IsAudioDeviceReady())
  {
    printf("ready\n");
  }

  Wave sample = LoadWave("example.wav");
  if (IsWaveReady(sample))
  {
    printf("ready\n");
  }

  Sound audio = LoadSoundFromWave(sample);
  if (IsSoundReady(audio))
  {
    printf("ready\n");
  }

  PlaySound(audio);

  while (!WindowShouldClose())
  {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Hello World", 20, 20, 10, BLACK);

    EndDrawing();
  }
  CloseWindow(); 

  return 0;
}