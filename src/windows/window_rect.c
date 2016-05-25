/**
* window_rect:
* Generates the rectanglular windows for the watchface.
* That's pretty much the banner behind the watchface's text and stuff.
* 
* TODO:
*   - Make sure to have it grab data for colors or something. (Based on who's the girl)
*   - Also make it friendly for different watchface interfaces.
*
**/

#include <pebble.h>
#include "windows/window_rect.h"

static Window *rect_window;
static Layer *rect_layer;

static void rect_window_update_proc(Layer *layer, GContext* ctx) {
  
  // When we render the layer, what do we draw?
  // In this case, we're going to draw the rectangles.
  
  // Grab the bounds for the watchface.
  GRect bounds = layer_get_bounds(layer);
  
  GRect rect_master = GRect( 0, bounds.size.h/2 - 16, bounds.size.w, 16*2);
  //GRect rect_slave = GRect( 0, bounds.size.h/2 - 16 + 16, bounds.size.w, 16*2);
  
  graphics_context_set_fill_color(ctx, GColorDarkCandyAppleRed);
  graphics_fill_rect(ctx, rect_master, 0, GCornerNone);
    
}

static void rect_window_load(Window* window) {
  
  // First, we get the bounds of the window based on the watchface dimensions.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Creates the layer to display the visuals for the window.
  rect_layer = layer_create(bounds);
  layer_add_child(window_layer, rect_layer);
  layer_set_update_proc(rect_layer, rect_window_update_proc);  
  
}

static void rect_window_unload(Window* window) {
  // Destroys the entire window.
  window_destroy(rect_window);  
  layer_destroy(rect_layer);
}

void rect_window_push() {
  
  // Executes if rect_window is undefined (i.e. it's not
  // initialized, and it must be initalized and added to
  // the window stack.)
  if(!rect_window) {
    rect_window = window_create();
    window_set_window_handlers(rect_window, (WindowHandlers) {
      .load = rect_window_load,       // Use rect_window_load for the load function
      .unload = rect_window_unload,   // Use rect_window_unload for the unload function
    });
  }
  window_stack_push(rect_window, true);
}