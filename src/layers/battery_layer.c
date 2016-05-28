/**
* battery_layer
* A btimap layer that represents how much battery power is left
* using SIF assets from max kizuna.
**/

#include <pebble.h>
#include "layers/battery_layer.h"

#define RECT_SUB_W_OFFSET 4
#define RECT_MASTER_HEIGHT 48


static BitmapLayer* battery_layer;
static GBitmap* battery_bitmap;

static uint32_t battery_gauge[6] = { RESOURCE_ID_IMAGE_BATTERY_0,
                                     RESOURCE_ID_IMAGE_BATTERY_1,
                                     RESOURCE_ID_IMAGE_BATTERY_2,
                                     RESOURCE_ID_IMAGE_BATTERY_3,
                                     RESOURCE_ID_IMAGE_BATTERY_4,
                                     RESOURCE_ID_IMAGE_BATTERY_5};

static int calculate_gauge_state(uint8_t charge) {
  // Calculates given charge which state it falls in:
  // 0: 0 - 10%
  // 1: 11 - 20%
  // 2: 21 - 40%
  // 3: 41 - 60%
  // 4: 61 - 80%
  // 5: > 80%
  
  int candid_state = (charge / 20);
  
  if(candid_state == 0 && charge < 10) {
    return 0;
  }
  else if(charge == 100) {
    return 5;
  }
  
  return candid_state + 1;
}

static void battery_handler(BatteryChargeState charge_state) {
  // Called when the battery level has changed.
  // Now...Draw!
  gbitmap_destroy(battery_bitmap);
  battery_bitmap = gbitmap_create_with_resource(battery_gauge[calculate_gauge_state(charge_state.charge_percent)]);
  bitmap_layer_set_bitmap(battery_layer,battery_bitmap);
}

void battery_layer_load(Window* window) {
  
  // Declare the layer's existence.
  // First, we get the bounds of the window based on the watchface dimensions.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // The dimensions are different depending on a round watchface or a rectangular one.
  GRect image_bounds = GRect( PBL_IF_ROUND_ELSE(bounds.size.w - 24*1.5,RECT_SUB_W_OFFSET),
                              PBL_IF_ROUND_ELSE(bounds.size.h/2+RECT_MASTER_HEIGHT/2, bounds.size.h/8+RECT_MASTER_HEIGHT - 12),
                              24,24);  
  
  // Creates the layer to display the visuals for the window.
  battery_layer = bitmap_layer_create(image_bounds);
  bitmap_layer_set_compositing_mode(battery_layer, GCompOpSet);
  battery_bitmap = gbitmap_create_with_resource(battery_gauge[calculate_gauge_state(battery_state_service_peek().charge_percent)]);
  bitmap_layer_set_bitmap(battery_layer, battery_bitmap);
  layer_add_child(window_get_root_layer(window), 
                                      bitmap_layer_get_layer(battery_layer));    
  
  
  // View the battery life and call battery_handler when
  // a disturbance in the force occurs.
  battery_state_service_subscribe(battery_handler);
}

void battery_layer_unload(Window* window) {
  battery_state_service_unsubscribe();
  gbitmap_destroy(battery_bitmap);
  bitmap_layer_destroy(battery_layer);
}