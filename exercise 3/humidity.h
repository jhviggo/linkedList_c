#pragma once
#include <stdint.h>

typedef struct humidity* humidity_t;

humidity_t humidity_create(void);
void humidity_meassure(humidity_t sensor);
uint8_t humidity_getHumidity(humidity_t sensor);