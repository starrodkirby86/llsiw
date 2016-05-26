/**
* idol_layer
* Using idol_rng we can display a GBitmap of the girl.
*/

#include <pebble.h>
#pragma once

void idol_layer_update_proc();
void idol_layer_load(Window* window);
void idol_layer_unload(Window* window);