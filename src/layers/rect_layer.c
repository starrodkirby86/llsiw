/**
* layer_rect:
* Generates the rectanglular windows for the watchface.
* That's pretty much the banner behind the watchface's text and stuff.
* 
* TODO:
*   - Make sure to have it grab data for colors or something. (Based on who's the girl)
*   - Also make it friendly for different watchface interfaces.
*
**/

#include <pebble.h>
#include "rect_layer.h"
#include "data/idol_rng.h"

#define RECT_MASTER_HEIGHT 48

static Layer *rect_layer;

static void rect_window_update_proc(Layer *layer, GContext* ctx) {
  // When we render the layer, what do we draw?
  // In this case, we're going to draw the rectangles.
  
  // Grab the bounds for the watchface.
  GRect bounds = layer_get_bounds(layer);
  GRect rect_master = GRect( 0, PBL_IF_ROUND_ELSE( bounds.size.h/2 - RECT_MASTER_HEIGHT/2, bounds.size.h/8), bounds.size.w, RECT_MASTER_HEIGHT);
  //printf("UL Coord is (%d, %d) while size is (%d, %d)", rect_master.origin.x, rect_master.origin.y, rect_master.size.w, rect_master.size.h);
  graphics_context_set_fill_color(ctx, get_idol_main_color());
  graphics_fill_rect(ctx, rect_master, 0, GCornerNone);
}

void rect_layer_load(Window* window) {
  // First, we get the bounds of the window based on the watchface dimensions.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Creates the layer to display the visuals for the window.
  rect_layer = layer_create(bounds);
  layer_add_child(window_layer, rect_layer);
  layer_set_update_proc(rect_layer, rect_window_update_proc);  
  
}

void rect_layer_unload(Window* window) {
  // Destroys the entire window. 
  layer_destroy(rect_layer);
}
