#include <time.h>
#include <stdbool.h>
#include "temperature.h"
#include "humidity.h"
#include "room.h"
#include "healtHandler.h"

#include <stdio.h>

bool temperature_metricUnits = true; // Definition
healthHandler_t _handler = NULL;

static void _delayMs(int milliseconds)
{
	long _pause;
	clock_t _now, _then;

	_pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	_now = _then = clock();
	while ((_now - _then) < _pause)
		_now = clock();
}

static void _setupApplication(void) {
	// Living Room
	temperature_t sensor_temperature1 = temperature_create(0);
	humidity_t sensor_humidity1 = humidity_create();
	room_t livingRoom = room_create("Living Room", 75);
	room_addTemperature(livingRoom, sensor_temperature1);
	room_addHumidity(livingRoom, sensor_humidity1);

	// Bed Room
	temperature_t sensor_temperature2 = temperature_create(0);
	humidity_t sensor_humidity2 = humidity_create();
	room_t bedRoom = room_create("Bed Room", 40);
	room_addTemperature(bedRoom, sensor_temperature2);
	room_addHumidity(bedRoom, sensor_humidity2);

	_handler = healthHandler_create();
	healthHandler_addRoom(_handler, livingRoom);
	healthHandler_addRoom(_handler, bedRoom);
}

static void _runApplication(void) {
	while (1) {
		healthHandler_showBuildingHealth(_handler);
		_delayMs(1000);
	}
}

int main(void) {
	_setupApplication();
	_runApplication();

	return 0;
}