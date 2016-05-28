/**
* Bitmap layer for the text bubble.
* > > ON THE IMAGE MOCKUPS:
*  ROUND: 4, 44
*  RECT: 3, 117
*  RECT_TEXT: 4, 120
*
**/

#define RECT_MASTER_SIZE 48

#include <pebble.h>
#include "layers/text_phrase_bg_layer.h"

static BitmapLayer* text_phrase_bg_layer;
GBitmap* bitmap_bubble;

void text_phrase_bg_layer_update_proc() {
  // Maybe this will be used another day.
}

void text_phrase_bg_layer_load(Window* window) {
  // First, we get the bounds of the window based on the watchface dimensions.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // The dimensions are different depending on a round watchface or a rectangular one.
  GRect image_bounds = GRect( PBL_IF_ROUND_ELSE(bounds.size.w / 45, 0),
                              PBL_IF_ROUND_ELSE(bounds.size.h / 4,bounds.size.h - RECT_MASTER_SIZE),
                              PBL_IF_ROUND_ELSE(170,90),
                              PBL_IF_ROUND_ELSE(30,40));
  
  // OK, let's get the text bubble.
  bitmap_bubble = gbitmap_create_with_resource( RESOURCE_ID_IMAGE_BUBBLE );
  
  // Creates the layer to display the visuals for the window.
  text_phrase_bg_layer = bitmap_layer_create(image_bounds);
  bitmap_layer_set_compositing_mode(text_phrase_bg_layer, GCompOpSet);
  bitmap_layer_set_bitmap(text_phrase_bg_layer, bitmap_bubble);
  layer_add_child(window_get_root_layer(window), 
                                      bitmap_layer_get_layer(text_phrase_bg_layer));    
}

void text_phrase_bg_layer_unload(Window* window) {
  gbitmap_destroy(bitmap_bubble);
  bitmap_layer_destroy(text_phrase_bg_layer);
}