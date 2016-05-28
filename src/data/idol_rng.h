/**
* idol_rng
* Welcome to idol hell.
* This code organizes the randomization of your beloved idol witches.
* At a different tick (probably an hour tick), the idol on the clock
* will change. Correspondingly, other aspects will change too.
**/

#include <pebble.h>
#pragma once

void idol_rng_update_proc();
GColor get_idol_main_color();
GColor get_idol_sub_color();
uint32_t get_idol_sprite();
void get_idol_phrase(char phrase[]);