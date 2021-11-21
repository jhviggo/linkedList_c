#pragma once
#include <stdint.h>

typedef struct temperature* temperature_t;

temperature_t temperature_create(uint8_t portNo);
void temperature_meassure(temperature_t sensor);
float temperature_getTemperature(temperature_t sensor);