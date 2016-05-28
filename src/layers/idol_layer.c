/**
* idol_layer
* I repent for every sin that I have committed when straying away
* from the one and only true god, Nico Yazawa.
*
* NICO NICO NIIIIIIIIIIIIII
*
* One thing to probably keep aware of would be that I don't need
* to create the bitmap every time, but rather only when the new girl updates.
*
* So the bitmap should update only during tick processing and upon first load.
*
**/

#include <pebble.h>
#include "data/idol_rng.h"
#include "layers/idol_layer.h"

static BitmapLayer* idol_layer;
static GBitmap* idol_bitmap;

// Called upon tick invocation.
void idol_layer_update_proc() {
  gbitmap_destroy(idol_bitmap);
  idol_bitmap = gbitmap_create_with_resource(get_idol_sprite());
  bitmap_layer_set_bitmap(idol_layer, idol_bitmap);
  //gbitmap_destroy(idol_bitmap);
}

void idol_layer_load(Window* window) {
  // First, we get the bounds of the window based on the watchface dimensions.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // The dimensions are different depending on a round watchface or a rectangular one.
  GRect image_bounds = GRect( PBL_IF_ROUND_ELSE(-10, bounds.size.w / 2 - bounds.size.w / 12),
                              PBL_IF_ROUND_ELSE(bounds.size.h / 3, bounds.size.h / 2 - bounds.size.h / 8),
                              100,105);
  
  // OK get idol sprite
  idol_bitmap = gbitmap_create_with_resource(get_idol_sprite());
  
  // Creates the layer to display the visuals for the window.
  idol_layer = bitmap_layer_create(image_bounds);
  bitmap_layer_set_compositing_mode(idol_layer, GCompOpSet);
  bitmap_layer_set_bitmap(idol_layer, idol_bitmap);
  //gbitmap_destroy(idol_bitmap);
  layer_add_child(window_get_root_layer(window), 
                                      bitmap_layer_get_layer(idol_layer));  
  
}

void idol_layer_unload(Window* window) {
  // Destroys the entire window. 
  gbitmap_destroy(idol_bitmap);
  bitmap_layer_destroy(idol_layer);
}