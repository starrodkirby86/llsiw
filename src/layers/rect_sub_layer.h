/**
* window_rect_sub:
* Generates the smaller rectanglular window for the watchface.
* So that's the one behind the main rectangular window.
* The meat is in window_rect.c, go there instead ~
**/

#include <pebble.h>

#pragma once

void rect_sub_layer_load(Window* window);
void rect_sub_layer_unload(Window* window);