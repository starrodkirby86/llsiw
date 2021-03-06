/**
* main_window
* The meat of the main window.
**/

#include <pebble.h>
#include "main_window.h"
#include "data/accel_phrase.h"
#include "data/config_manager.h"
#include "data/time_manager.h"
#include "layers/anim_bg_layer.h"
#include "layers/anim_logo_layer.h"
#include "layers/battery_layer.h"
#include "layers/idol_layer.h"
#include "layers/text_date_layer.h"
#include "layers/text_time_layer.h"
#include "layers/text_phrase_bg_layer.h"
#include "layers/text_phrase_layer.h"
#include "layers/rect_layer.h"
#include "layers/rect_sub_layer.h"

static Window *main_window;

static void window_load(Window* window) {
  // Layers to load inside the watchface.  
  rect_layer_load(window);
  rect_sub_layer_load(window);
  battery_layer_load(window);
  text_time_layer_load(window);
  text_date_layer_load(window);
  text_phrase_bg_layer_load(window);
  text_phrase_layer_load(window);
  idol_layer_load(window);
  anim_bg_layer_load(window);
  anim_logo_layer_load(window);
  
  // Load the config_manager
  config_manager_load();
  
  // Also load time_manager
  time_manager_load();
  
  // Also the accel_phrase manager
  accel_phrase_load();
  
}

static void window_unload(Window* window) {
  
  // Destroys the layers.
  rect_layer_unload(window);  
  rect_sub_layer_unload(window);
  battery_layer_unload(window);  
  text_time_layer_unload(window);
  text_date_layer_unload(window);
  text_phrase_bg_layer_unload(window);
  text_phrase_layer_unload(window);
  idol_layer_unload(window);
  //anim_bg_layer_unload(window);  
  //anim_logo_layer_unload(window);
  accel_phrase_unload();
  
  // Destroys the entire window.
  window_destroy(main_window);
}

void main_window_push() {
  // Executes if main_window is undefined (i.e. it's not
  // initialized, and it must be initalized and added to
  // the window stack.)
  if(!main_window) {
    main_window = window_create();
    window_set_window_handlers(main_window, (WindowHandlers) {
      .load = window_load,       // Use window_load for the load function
      .unload = window_unload,   // Use window_unload for the unload function
    });
  }
  window_stack_push(main_window, true);
}