#include <stdint.h>
#include "humidityDriver.h"
#include "humidity.h"

typedef struct humidity { 
	int8_t latestHumidity;
} humidity;

humidity_t humidity_create(void) {
	humidity_t _newHumidity = calloc(sizeof(humidity), 1);
	_newHumidity->latestHumidity = 0;
	humidityDriver_initDriver();
	return _newHumidity;
}

void humidity_meassure(humidity_t sensor) {
	sensor->latestHumidity = humidityDriver_getHumidity();
}

uint8_t humidity_getHumidity(humidity_t sensor) {
	return sensor->latestHumidity;
}