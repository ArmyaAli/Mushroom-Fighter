#include "asset_loader.h"
#include <stdio.h>

// NOTE - TODO
// Convert all assets into embeddable data into the EXE.
// This class will be depreciated

const char* path = "assets/maps/background.png";

Texture2D load_map() {
  Texture2D background = LoadTexture(path);

  if (IsTextureReady(background)) {
    printf("Ready");
  }

  return background;
}

Texture2D load_menu_graphic() {
  Texture2D asset = LoadTexture("assets/menu/menu.png");

  if (IsTextureReady(asset)) {
    printf("Ready");
  }

  return asset;
}