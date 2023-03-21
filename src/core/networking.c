#include "networking.h"

#if (_WIN32_WINNT < 0x0601)
#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif

#define ENET_IMPLEMENTATION
#include <enet/enet.h>

ENetHost* client    = {0};
ENetPeer* target    = {0};
ENetAddress address = {0};

void Connect() {
  enet_initialize();
  client = enet_host_create(NULL, 1, 1, 0, 0);
  enet_address_set_host(&address, "127.0.0.1");
  address.port = 4545;
  target = enet_host_connect(client, &address, 1, 0);
}

void Update() {
  if (target == NULL)
    return;
}
