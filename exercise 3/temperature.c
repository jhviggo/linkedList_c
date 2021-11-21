#include <stdbool.h>
#include "tempDriver.h"
#include "temperature.h"

typedef struct temperature {
	float latestTemp;
	uint8_t driverPort;
} temperature;

extern bool temperature_metricUnits;

static float _calculateTemp(float voltage) {
	return 15.0+(voltage * 5.0); // dummy calc
}

temperature_t temperature_create(uint8_t portNo) {
	temperature_t _newTemp = calloc(sizeof(temperature), 1);
	_newTemp->driverPort = portNo;
	_newTemp->latestTemp = 0.0;
	temperatureDriver_initDriver(portNo);
	return _newTemp;
}

void temperature_meassure(temperature_t sensor) {
	sensor->latestTemp = _calculateTemp(temperatureDriver_getVoltage());
}

float temperature_getTemperature(temperature_t sensor){
	float _tmp = sensor->latestTemp;
	if (temperature_metricUnits) {
		_tmp *= 0.2; // dummy conversion
	}

	return _tmp;
}
