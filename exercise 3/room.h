#pragma once
#include <stdint.h>
#include "temperature.h"
#include "humidity.h"

typedef enum {
	PERFECT
	,GOOD
	,AVERAGE
	,BAD
	,DISASTER
}room_roomHealth_t;

typedef struct room* room_t;

room_t room_create(char* location, uint16_t sqMeter);
room_roomHealth_t room_getRoomHealth(room_t room);
void room_addTemperature(room_t room, temperature_t sensor);
void room_addHumidity(room_t room, humidity_t sensor);
char* room_getRoomHealthText(room_roomHealth_t health);
char* room_getLocation(room_t room);
uint16_t room_getArea(room_t room);