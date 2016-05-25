/**
* text_time_layer
* Text for the clock.
* The function should be pretty innocuous...
*
**/

#include <pebble.h>
#pragma once

void text_time_update_proc();
void text_time_layer_load(Window* window);
void text_time_layer_unload(Window* window);