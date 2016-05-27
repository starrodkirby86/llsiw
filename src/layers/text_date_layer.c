/**
* text_date_layer
* Records the date. Then it's output on a string here.
* Life is lovely like that.
*
* The main text is going to use the idol's main color.
*
*/

#include <pebble.h>
#include "layers/text_date_layer.h"
#include "data/idol_rng.h"
#include "data/string_time.h"

TextLayer* text_date_layer;
GFont font_league_sm;

void text_date_layer_update_proc() {
  char* buffer_input = "jan 31\nthurs";
  get_time(buffer_input);
  text_layer_set_text_color(text_date_layer, get_idol_main_color());  
  text_layer_set_text(text_date_layer, buffer_input);    
}

void text_date_layer_load(Window* window) {
  
  // Let's go get the bounds of the window first.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Here's the coordinates for the textLayer.
  GRect text_location = GRect( PBL_IF_ROUND_ELSE(bounds.size.w / 2 - bounds.size.w / 12,bounds.size.w / 12), 
                              PBL_IF_ROUND_ELSE( bounds.size.h/2 + bounds.size.h / 5, bounds.size.h/2), 
                              bounds.size.w, 48);
  
  // Load custom font.
  font_league_sm = fonts_load_custom_font(
                          resource_get_handle(RESOURCE_ID_FONT_LEAGUE_BOLD_14));
  
  // We declare the text layer into existence.
  // Settings to make the text layer look pretty.
  text_date_layer = text_layer_create(text_location);
  text_layer_set_text_color(text_date_layer, get_idol_main_color());
  text_layer_set_background_color(text_date_layer, GColorClear);
  text_layer_set_text_alignment(text_date_layer, GTextAlignmentLeft);
  text_layer_set_font(text_date_layer, font_league_sm);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_date_layer));   
}

void text_date_layer_unload(Window* window) {
  text_layer_destroy(text_date_layer);
}