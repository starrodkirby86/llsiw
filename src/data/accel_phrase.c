/**
* accel_phrase
* Let's hope this strategy pays off.
* Changes the visibility of the layers text_phrase_bg_layer and
* text_phrase_layer to visible (for a short moment) when a tap
* event is registered.
*
* Also should have some boolean that suppresses this and keeps
* the talking bubble layers always visible depending on a configuration.
*/

#include <pebble.h>
#include "data/config_manager.h"
#include "data/accel_phrase.h"
#include "layers/text_phrase_bg_layer.h"
#include "layers/text_phrase_layer.h"

static void accel_phrase_callback(void *context) {
  // Hide the text bubbles after a specified period of time.
  // (That time should be given in the accel_tap_handler).
  set_text_phrase_layer_hidden(true);
  set_text_phrase_bg_layer_hidden(true);
}

static void accel_tap_handler(AccelAxisType axis, int32_t direction) {
  // A tap event occured
  set_text_phrase_layer_hidden(false);
  set_text_phrase_bg_layer_hidden(false);
  
  // Display the event for 3sec
  const int delay_ms = 3000;
  
  // After that time, hide the text bubbles again.
  app_timer_register(delay_ms, accel_phrase_callback, NULL);
  
}

// lol
bool is_tapping_disabled() {
  return persist_read_bool(KEY_TOGGLE_TAPS);
}

void accel_phrase_load() {
  // Subscribe to the accelerometer to check if any tapping has occurred.
  // MUST BE CALLED, otherwise accel_data_handler can never be hit.
  // Subscribe to batched data events
  
  // If the bool for tapping_disabled is, well, true, then we aren't going
  // to bother checking for this stuff.
  if(!is_tapping_disabled()) {
    accel_tap_service_subscribe(accel_tap_handler);
  }
}

void accel_phrase_unload() {
  // Stop subscribing to the service.
  accel_tap_service_unsubscribe();
}