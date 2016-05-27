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
#include "layers/idol_layer.h"
#include "layers/text_time_layer.h"
#include "layers/text_date_layer.h"
#include "layers/text_phrase_layer.h"

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  idol_rng_update_proc();
  idol_layer_update_proc();
  string_time_update_proc();
  string_date_update_proc();
  text_time_update_proc();
  text_date_layer_update_proc();
  text_phrase_layer_update_proc();
}

void time_manager_load() {
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

void time_manager_unload() { 
  tick_timer_service_unsubscribe();
}