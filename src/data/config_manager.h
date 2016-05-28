/**
* config_manager
* Keys located here!
**/

#include <pebble.h>
#pragma once

// DEFINE DICT KEYS HERE

// IDOL RATE KEYS
#define KEY_SLIDER_ELI    0
#define KEY_SLIDER_HONK   1
#define KEY_SLIDER_KOTORI 2
#define KEY_SLIDER_MAKI   3
#define KEY_SLIDER_NICO   4
#define KEY_SLIDER_NOZO   5
#define KEY_SLIDER_PANA   6
#define KEY_SLIDER_RIN    7
#define KEY_SLIDER_UMI    8

// MISC KEYS
#define KEY_SLIDER_SPAWN  9
#define KEY_TOGGLE_TAPS   10
#define KEY_TOGGLE_SAME   11

// CURRENT COUNT OF KEYS
#define COUNT_KEYS        12

// There should be 12 total settings based on appkeys
// that corresponds to the keys we defined earlier
// i.e. KEY_SLIDER_ELI should be 0 in the appkey -> int relation
// till KEY_TOGGLE_TAPS being 10.

void config_manager_load();