/**
* anim_logo_layer
* Compliments the anim_bg_layer.
* Let's test out that APNG fun.
*
**/

#include <pebble.h>
#include "layers/anim_logo_layer.h"


static BitmapLayer *anim_logo_layer;
static GBitmapSequence *anim_seq;
static GBitmap *anim_bitmap;

static void timer_handler(void *context) {
  
  uint32_t next_delay;
  
  // APNG sequences are not supported on Aplite, so we're not going to do that
  // fancy transparent animation.
  #if defined(PBL_BW)
  
  layer_set_hidden( (Layer *) anim_logo_layer, true);
  return;
  
  #endif

  // Advance to the next APNG frame, and get the delay for this frame
  if(gbitmap_sequence_update_bitmap_next_frame(anim_seq, anim_bitmap, &next_delay)) {
    // Set the new frame into the BitmapLayer
    bitmap_layer_set_bitmap(anim_logo_layer, anim_bitmap);
    layer_mark_dirty(bitmap_layer_get_layer(anim_logo_layer));

    // Timer for that frame's delay
    app_timer_register(next_delay, timer_handler, NULL);
  }
  else {
    //anim_logo_layer_unload( layer_get_window( bitmap_layer_get_layer( anim_logo_layer ) ) );
  }
  
}


void anim_logo_layer_load(Window* window) {
  
  // First, we get the bounds of the window based on the watchface dimensions.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // The dimensions are different depending on a round watchface or a rectangular one.
  GRect image_bounds = GRect( PBL_IF_ROUND_ELSE(40, 22),
                              PBL_IF_ROUND_ELSE(40, 34),
                              100,100);
  
  #if defined(PBL_COLOR)
  
  // Create sequence
  anim_seq = gbitmap_sequence_create_with_resource(RESOURCE_ID_IMAGE_LOGO);
  
  // Create blank GBitmap using APNG frame size
  GSize frame_size = gbitmap_sequence_get_bitmap_size(anim_seq);
  anim_bitmap = gbitmap_create_blank(frame_size, GBitmapFormat8Bit);
  
  #elif defined(PBL_BW)
  
  anim_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_LOGO_BW);
  
  #endif
  
  // Creates the layer to display the visuals for the window.
  anim_logo_layer = bitmap_layer_create(image_bounds);
  bitmap_layer_set_compositing_mode(anim_logo_layer, GCompOpSet);
  bitmap_layer_set_bitmap(anim_logo_layer, anim_bitmap);
  layer_add_child(window_get_root_layer(window), 
                                      bitmap_layer_get_layer(anim_logo_layer));    
  
  #if defined(PBL_COLOR)
    uint32_t first_delay_ms = 1;
  #elif defined(PBL_BW)
    uint32_t first_delay_ms = 500;
  #endif
  
  // Schedule a timer to advance the first frame
  app_timer_register(first_delay_ms, timer_handler, NULL);  
  
}

void anim_logo_layer_unload(Window* window) {
  gbitmap_sequence_destroy(anim_seq);
  gbitmap_destroy(anim_bitmap);
  bitmap_layer_destroy(anim_logo_layer);
}