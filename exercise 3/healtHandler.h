#pragma once

#include "room.h"

typedef struct healthHandler* healthHandler_t;

healthHandler_t healthHandler_create(void);
void healthHandler_showBuildingHealth(healthHandler_t handler);
void healthHandler_addRoom(healthHandler_t handler, room_t room);