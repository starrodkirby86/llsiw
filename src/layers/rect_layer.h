/**
* rect_layer:
* Generates the main rectanglular window for the watchface.
* That's pretty much the banner behind the watchface's text and stuff.
* The meat is in window_rect.c, go there instead ~
**/

#include <pebble.h>
#pragma once

void rect_layer_load(Window* window);
void rect_layer_unload(Window* window);