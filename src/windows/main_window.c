/**
* main_window
* The meat of the main window.
**/

#include <pebble.h>
#include "main_window.h"
#include "layers/rect_layer.h"
#include "layers/rect_sub_layer.h"

static Window *main_window;

static void window_load(Window* window) {
  // Layers to load inside the watchface.  
  rect_layer_load(window);
  rect_sub_layer_load(window);
}

static void window_unload(Window* window) {
  
  // Destroys the layers.
  rect_layer_unload(window);  
  rect_sub_layer_unload(window);
  
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
      .load = window_load,       // Use rect_window_load for the load function
      .unload = window_unload,   // Use rect_window_unload for the unload function
    });
  }
  window_stack_push(main_window, true);
}