/**
* Let's try this rectangle animation crap again, except
* as an overlay on top.
* Two animations should go here:
* --> An entry animation (maybe used?)
* --> An exit animation (should be used)
*
**/

#include <pebble.h>
#include "layers/anim_bg_layer.h"

static Layer *anim_bg_layer;


/*
static void anim_bg_layer_finish_handler(Animation *animation, bool finished, void *context) {
  anim_bg_layer_unload( layer_get_window(  anim_bg_layer ) );
}
*/

/*
void anim_bg_layer_entry_anim(Window* window) {

  // Let's go get the bounds of the window first.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Set start and end rects
  GRect start  = GRect(0, 0, bounds.size.w, bounds.size.h);
  GRect finish = GRect(bounds.size.w / 2, bounds.size.h / 2, 0, 0);
  
  // Animate the layer
  PropertyAnimation *prop_anim = property_animation_create_layer_frame(anim_bg_layer, 
                                                               &finish, &start);  
  
  // Get the animation for property changes
  Animation *anim = property_animation_get_animation(prop_anim);
  
  // Parameters
  const int delay_ms = 500; // change me later
  const int duration_ms = 500;
  
  // Configure curve, delay, duration
  animation_set_curve(anim, AnimationCurveEaseOut);
  animation_set_delay(anim, delay_ms);
  animation_set_duration(anim, duration_ms);
  
  // OK, ready and fire.
  animation_schedule(anim);
  
}
*/

void anim_bg_layer_exit_anim(Window* window) {

  // Let's go get the bounds of the window first.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Set start and end rects
  GRect start  = GRect(0, 0, bounds.size.w, bounds.size.h);
  GRect finish = GRect(bounds.size.w / 2, bounds.size.h / 2, 0, 0);
  
  // Animate the layer
  PropertyAnimation *prop_anim = property_animation_create_layer_frame(anim_bg_layer, 
                                                               &start, &finish);  
  
  // Get the animation for property changes
  Animation *anim = property_animation_get_animation(prop_anim);
  
  // Parameters
  const int delay_ms = PBL_IF_COLOR_ELSE(750, 500); // change me later
  const int duration_ms = PBL_IF_COLOR_ELSE(750, 750);
  
  // Configure curve, delay, duration
  animation_set_curve(anim, AnimationCurveEaseOut);
  animation_set_delay(anim, delay_ms);
  animation_set_duration(anim, duration_ms);
  
  /*
  animation_set_handlers(anim, 
                        (AnimationHandlers) { .stopped = anim_bg_layer_finish_handler },
                        NULL);
  */
  
  // OK, ready and fire.
  animation_schedule(anim);
  
}

static void anim_bg_layer_update_proc(Layer *layer, GContext* ctx) {
  // When we render the layer, what do we draw?
  // In this case, we're going to draw the rectangles.
  
  // Grab the bounds for the watchface.
  GRect bounds = layer_get_bounds(layer);
  GRect rect_master = GRect( 0, 0, bounds.size.w, bounds.size.h);
  //printf("UL Coord is (%d, %d) while size is (%d, %d)", rect_master.origin.x, rect_master.origin.y, rect_master.size.w, rect_master.size.h);
  graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, rect_master, 0, GCornerNone);
}

void anim_bg_layer_load(Window* window) {
  // Let's go get the bounds of the window first.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);  
  
  anim_bg_layer = layer_create(bounds);
  
 // Creates the layer to display the visuals for the window.
  layer_add_child(window_layer, anim_bg_layer);
  layer_set_update_proc(anim_bg_layer, anim_bg_layer_update_proc); 
  
  // Add a snazzy exit animation to boot.
  anim_bg_layer_exit_anim(window);
  
}

void anim_bg_layer_unload(Window* window) {
  layer_destroy(anim_bg_layer);
}