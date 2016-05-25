/**
* time_manager
* Only one service can be subscribed to the tick handler at one time.
* Because of this, we best should create some master function that handles
* all of the timer services.
*
* Then layers will just update based on get data from other data functions.
* The actual meat goes here.
*
**/

#include <pebble.h>

// Data include
#include "time_manager.h"
#include "idol_rng.h"
#include "string_time.h"

// Layer include
#include "layers/text_time_layer.h"

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  idol_rng_update_proc();
  string_time_update_proc();
  text_time_update_proc();
}

void time_manager_load() {
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

void time_manager_unload() { 
  tick_timer_service_unsubscribe();
}