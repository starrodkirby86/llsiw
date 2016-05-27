/**
* text_date_layer
* Records the date. Then it's output on a string here.
* Life is lovely like that.
*/

#include <pebble.h>

#pragma once

void text_date_layer_update_proc();
void text_date_layer_load(Window* window);
void text_date_layer_unload(Window* window);