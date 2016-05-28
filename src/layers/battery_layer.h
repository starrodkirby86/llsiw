/**
* battery_layer
* The abstraction that other files can only peek! No peeking!
**/

#include <pebble.h>
#pragma once

void battery_layer_load(Window* window);
void battery_layer_unload(Window* window);