#include <string.h>
#include <stdlib.h>
#include "room.h"

typedef struct room { 
	char location[30];
	uint16_t squareMeters;
	temperature_t temperaturesSensors[4];
	int sensorCountTemp;
	humidity_t humiditySensors[2];
	int sensorCountHum;
} room;

static const char* _health_text[] = { "PERFECT", "GOOD", "AVERAGE", "BAD", "DISASTER" };

static room_roomHealth_t _calculateHealth(float temp, uint8_t hum) {
	return (uint16_t)(temp * hum) % 5;// dummy calculation; 
}

room_t room_create(char* location, uint16_t sqMeter) {
	room_t _newRoom = calloc(sizeof(room), 1);
	strncpy(_newRoom->location, location, sizeof(_newRoom->location) - 1);
	_newRoom->squareMeters = sqMeter;
	_newRoom->sensorCountTemp = 0;
	_newRoom->sensorCountHum = 0;
	return _newRoom;
}

void room_addTemperature(room_t room, temperature_t sensor) {
	int _sensorTempCount = room->sensorCountTemp;
	if (_sensorTempCount != 2) {
		room->temperaturesSensors[_sensorTempCount] = sensor;
		room->sensorCountTemp = _sensorTempCount + 1;
	}
}

void room_addHumidity(room_t room, humidity_t sensor) {
	int _sensorHumCount = room->sensorCountHum;
	if (_sensorHumCount != 2) {
		room->humiditySensors[_sensorHumCount] = sensor;
		room->sensorCountHum = _sensorHumCount + 1;
	}
}

room_roomHealth_t room_getRoomHealth(room_t room) {
	// Sum temperatures from sensors
	float _sumTemp = 0.0;
	int _indexTemp = 0;
	while (room->temperaturesSensors[_indexTemp] != NULL) {
		temperature_meassure(room->temperaturesSensors[_indexTemp]);
		_sumTemp = temperature_getTemperature(room->temperaturesSensors[_indexTemp]);
		_indexTemp++;
	}

	// Sum humidity from sensors
	float _sumHum = 0.0;
	int _indexHum = 0;
	while (room->humiditySensors[_indexHum] != NULL) {
		humidity_meassure(room->humiditySensors[_indexHum]);
		_sumHum = humidity_getHumidity(room->humiditySensors[_indexHum]);
		_indexHum++;
	}

	// Calculate health based on room averages for temp and humidity
	return _calculateHealth(_sumTemp/_indexTemp, _sumHum/_indexHum);
}

char* room_getRoomHealthText(room_roomHealth_t health) {
	return _health_text[health];
}

char* room_getLocation(room_t room) {
	return room->location;
}

uint16_t room_getArea(room_t room) {
	return room->squareMeters;
}