/**
* text_time_layer
* Definition of the text layer for the clock's time.
*
* TODO:
* Apparently, the tick handler is only good for ONE service.
* In that case, everyone must share. So we'll have to utilize some time manager or something.
*
**/

#include <pebble.h>
#include "layers/text_time_layer.h"
#include "data/string_time.h"

#define RECT_MASTER_HEIGHT 48

TextLayer *text_time;
GFont      font_league_main;

void text_time_update_proc() {
  char* buffer_input = "00:00";
  get_time(buffer_input);
  text_layer_set_text(text_time, buffer_input);  
}

void text_time_layer_load(Window* window) {
  
  // Let's go get the bounds of the window first.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Here's the coordinates for the textLayer.
  GRect text_location = GRect( 0, PBL_IF_ROUND_ELSE( bounds.size.h/2 - RECT_MASTER_HEIGHT/2, bounds.size.h/8), bounds.size.w, RECT_MASTER_HEIGHT);
  
  // Load custom font.
  font_league_main = fonts_load_custom_font(
                          resource_get_handle(RESOURCE_ID_FONT_LEAGUE_BOLD_36));
  // Load custom font.
  //font_moji = fonts_load_custom_font(
  //                        resource_get_handle(RESOURCE_ID_FONT_AHAHAMOJIMOJI_14));
  
  
  // We declare the text layer into existence.
  // Settings to make the text layer look pretty.
  text_time = text_layer_create(text_location);
  text_layer_set_text_color(text_time, GColorWhite);
  text_layer_set_background_color(text_time, GColorClear);
  text_layer_set_text_alignment(text_time, GTextAlignmentCenter);
  text_layer_set_font(text_time, font_league_main);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_time)); 
  
}

void text_time_layer_unload(Window* window) {
  text_layer_destroy(text_time);
}