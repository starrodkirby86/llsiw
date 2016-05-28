/**
* text_phrase_layer
* You know the drill by now. Nico Nico ni!
**/

#include <pebble.h>

#pragma once

void text_phrase_layer_update_proc();
void text_phrase_layer_load(Window* window);
void text_phrase_layer_unload(Window* window);
void set_text_phrase_layer_hidden(bool flag);