/**
* config_manager
* If I was a variable that relied on a key from
* the clay config page, I would include this code.
* And stuff like that.
*
**/

#include <pebble.h>
#include "data/config_manager.h"


// In order to utilize the config values, you'll have to call the app_message
// function that has an inbox_received_handler attached to it.

static void inbox_received_handler(DictionaryIterator *iter, void *context) {
  // Function is called to map all the configuration values to
  // the appropriate values.
  
  // This code makes an assumption that the first set of keys
  // are going to be assigned to the idol girls, so that's kind of dangerous.
  // But it'll work for us.
  for(int i = 0; i < 9; i++) {
    Tuple *bias_tuple = dict_find(iter, i);
    if(bias_tuple) {
      persist_write_int(i, bias_tuple->value->int32); // Store this into memory
    }
    else {
      persist_write_int(i, 10); // Default value to prevent null problems
    }
  }
  
  // Now it's time to do spawn rate
  Tuple *spawn_tuple = dict_find(iter, KEY_SLIDER_SPAWN);
  if(spawn_tuple) {
    persist_write_int(KEY_SLIDER_SPAWN, spawn_tuple->value->int8);
  }
  else {
    persist_write_int(KEY_SLIDER_SPAWN, 30);
  }
  
  // Finally, we're going to update the toggle.
  Tuple *tap_toggle = dict_find(iter, KEY_TOGGLE_TAPS);
  if(tap_toggle) {
    persist_write_int(KEY_TOGGLE_TAPS, tap_toggle->value->int8);
  }
  else {
    persist_write_int(KEY_TOGGLE_TAPS, 0);
  }
  
  // And now, we gotta consider the double idol trouble.
  Tuple *same_toggle = dict_find(iter, KEY_TOGGLE_SAME);
  if(same_toggle) {
    persist_write_int(KEY_TOGGLE_SAME, same_toggle->value->int8);
  }
  else {
    persist_write_int(KEY_TOGGLE_SAME, 0);
  }
  
}

void config_manager_load() {
  app_message_register_inbox_received(inbox_received_handler);
  //printf("%d", (int) dict_calc_buffer_size(COUNT_KEYS, sizeof(int8_t)));
  app_message_open(256,0); // It was a good effort using dict_calc_buffer_size, but using sizeof(int8_t) wasn't going to yield a very good output...
                           // The 256 size is dangerous since it's not very generalized but it will work for now.
}