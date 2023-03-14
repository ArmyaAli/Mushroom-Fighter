#include <stdio.h>
#include "map_loader.h"

const char *path = "assets/maps/background.png";

Texture2D load_map()
{
  Texture2D background = LoadTexture(path);

  if(IsTextureReady(background)) {
    printf("Ready");
  }
  
  return background;
}