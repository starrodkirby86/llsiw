/**
* layer_rect_sub:
* Generates the rectanglular windows for the watchface.
* That's pretty much the banner behind the watchface's text and stuff.
* 
* TODO:
*   - Also make it friendly for different watchface interfaces.
*   - Animation makes the layer hidden for some reason. Take a look into that.
*
**/

#include <pebble.h>
#include "rect_sub_layer.h"
#include "data/idol_rng.h"

#define RECT_SUB_W_OFFSET 8
#define RECT_MASTER_HEIGHT 48
#define RECT_SUB_HEIGHT 12

static Layer *rect_sub_layer;

static void rect_sub_layer_anim_entry() {
  // Rectangle entry animation
  
  // Grab the bounds for the watchface.
  GRect bounds = layer_get_bounds(rect_sub_layer);
  
  GRect start_point = GRect( 0, PBL_IF_ROUND_ELSE( bounds.size.h/2+RECT_MASTER_HEIGHT/2, bounds.size.h/8+RECT_MASTER_HEIGHT), bounds.size.w, RECT_SUB_HEIGHT); 
  GRect end_point = GRect( RECT_SUB_W_OFFSET, PBL_IF_ROUND_ELSE( bounds.size.h/2+RECT_MASTER_HEIGHT/2, bounds.size.h/8+RECT_MASTER_HEIGHT), bounds.size.w, RECT_SUB_HEIGHT);
  //const int delay_ms = 250;
  const int duration_ms = 500;
  PropertyAnimation *prop_anim = property_animation_create_layer_frame(rect_sub_layer, 
                                                               &start_point, &end_point);
  Animation *anim = property_animation_get_animation(prop_anim);
  animation_set_curve(anim, AnimationCurveEaseOut);
  //animation_set_delay(anim, delay_ms);
  animation_set_duration(anim, duration_ms);
  
  animation_schedule(anim);
}


static void rect_sub_layer_update_proc(Layer *layer, GContext* ctx) {
  // When we render the layer, what do we draw?
  // In this case, we're going to draw the rectangles.
  
  // Grab the bounds for the watchface.
  GRect bounds = layer_get_bounds(layer);
  GRect rect_sub_master = GRect( RECT_SUB_W_OFFSET, PBL_IF_ROUND_ELSE( bounds.size.h/2+RECT_MASTER_HEIGHT/2, bounds.size.h/8+RECT_MASTER_HEIGHT), bounds.size.w, RECT_SUB_HEIGHT);
  //printf("UL Coord is (%d, %d) while size is (%d, %d)", rect_sub_master.origin.x, rect_sub_master.origin.y, rect_sub_master.size.w, rect_sub_master.size.h);
  graphics_context_set_fill_color(ctx, get_idol_sub_color());
  graphics_fill_rect(ctx, rect_sub_master, 0, GCornerNone);
}

void rect_sub_layer_load(Window* window) {
  // First, we get the bounds of the window based on the watchface dimensions.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Creates the layer to display the visuals for the window.
  rect_sub_layer = layer_create(bounds);
  layer_add_child(window_layer, rect_sub_layer);
  layer_set_update_proc(rect_sub_layer, rect_sub_layer_update_proc);  
  
  //rect_sub_layer_anim_entry(); 
}

void rect_sub_layer_unload(Window* window) {
  // Destroys the entire layer.  
  layer_destroy(rect_sub_layer);
}