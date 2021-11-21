#include <stdio.h>
#include <stdlib.h>
#include "healtHandler.h"

typedef struct healthHandler {
	room_t rooms[10];
	int roomCount;
} healthHandler;

static void _printRoomHealth(room_t room) {
	printf("%s: area: %d m2 Health: %s\n", room_getLocation(room), room_getArea(room), room_getRoomHealthText(room_getRoomHealth(room)));
}

healthHandler_t healthHandler_create(void) {
	healthHandler_t _newHandler = calloc(sizeof(healthHandler), 1);
	_newHandler->roomCount = 0;
	return _newHandler;
}

void healthHandler_showBuildingHealth(healthHandler_t handler) {
	int _index = 0;
	int _roomCount = handler->roomCount;
	while (_index < _roomCount) {
		_printRoomHealth(handler->rooms[_index]);
		_index++;
	}
}

void healthHandler_addRoom(healthHandler_t handler, room_t room) {
	int _roomIndex = handler->roomCount;
	if (_roomIndex < 10) {
		handler->rooms[_roomIndex] = room;
		handler->roomCount = _roomIndex + 1;
	}
}