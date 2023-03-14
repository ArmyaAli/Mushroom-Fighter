/*******************************************************************************************
 *  Name: Ali Umar
 *  Title: Mushroom Fighter 
 *  Description: A small fighting game arund the theme of mushrooms 
 ********************************************************************************************/

#include <stdio.h>
#include "raylib.h"

int main(void)
{
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Mushroom Fighter");

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