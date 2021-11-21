#pragma once
#include <stdint.h>
#include <stdlib.h>

void temperatureDriver_initDriver(uint8_t port);
float temperatureDriver_getVoltage();
