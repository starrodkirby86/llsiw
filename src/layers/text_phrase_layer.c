/**
* text_phrase_layer
* Using the shortmoji font (which is a combination of AhahaMojimoji
* and Sanfon Maru) we can basically make our kana characters in a compact
* way that works with Pebble's limitations of only reading alphanumeric
* characters (and a bit more).
*
* Used for catchphrases to give the idol girls some more life.
*
* TODO:
*  - Friendly for rectangular and roundface watchfaces.
*  - Add a speech bubble when you can.
*
**/

#include <pebble.h>
#include "layers/text_phrase_layer.h"
#include "data/idol_rng.h"

#define PHRASE_TEXT_FONT_SIZE   14
#define PHRASE_TEXT_FONT_SIZE_R 18
#define RECT_MASTER_SIZE 48

TextLayer *text_phrase_layer;
GFont      font_moji;

void text_phrase_layer_update_proc() {
  char* buffer_input = "AAAAAAAA";
  text_layer_set_text_color(text_phrase_layer, get_idol_main_color()); 
  get_idol_phrase(buffer_input);
  text_layer_set_text(text_phrase_layer, buffer_input);  
}

void text_phrase_layer_load(Window* window) {
  
  // Let's go get the bounds of the window first.
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  // Here's the coordinates for the textLayer.
  GRect text_location = GRect( 0,
                              PBL_IF_ROUND_ELSE(bounds.size.h / 2 - RECT_MASTER_SIZE,0),
                              bounds.size.w, PBL_IF_ROUND_ELSE(PHRASE_TEXT_FONT_SIZE_R,PHRASE_TEXT_FONT_SIZE));
  
  // Load custom font.
  font_moji = fonts_load_custom_font(
              resource_get_handle(PBL_IF_ROUND_ELSE(RESOURCE_ID_FONT_SHORTMOJI_18,RESOURCE_ID_FONT_SHORTMOJI_14)));
  
  
  // We declare the text layer into existence.
  // Settings to make the text layer look pretty.
  text_phrase_layer = text_layer_create(text_location);
  text_layer_set_text_color(text_phrase_layer, get_idol_main_color());
  text_layer_set_background_color(text_phrase_layer, GColorClear);
  text_layer_set_text_alignment(text_phrase_layer, GTextAlignmentCenter);
  text_layer_set_font(text_phrase_layer, font_moji);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_phrase_layer)); 
  
}

void text_phrase_layer_unload(Window* window) {
  text_layer_destroy(text_phrase_layer);
}