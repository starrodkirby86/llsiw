/**
                        LOVE LIVE: SCHOOL IDOL WATCHFACE
................................................................................
................................................................................
................................................................................
................................................................................
.......................................................~~~~.....................
.....................................................~~~~~......................
.....................................................~~~~.............:~........
....................................................~~~.............~~~~........
..................................................~~~.............~~~...........
........................~~~~~...........~~~~~....~~.............~~~.............
.....................~~~~~~~..........~~~~~...................~~~~~.............
...................~~~~~~~..........~~~~~~..................~~.~~~~.............
.................~~~~~~~~.........~~~~~~:.................~~...~~~..............
...............~:.~~~~~.........~~~~~~~................~~.....~~~~..............
.............~~.~~~~~~........~~~~~~~~.......~...~~~~~.......~~~~~......~~......
............~..~~~~~~.......~~.~~~~~.......~....~~~~~~......~~~~~.....~~........
..............~~~~~.......~:.~~~~~~......~.....~~~~~~......~~~~~....~~..........
............:~~~~~.....~~:..~~~~~~.....~~.....:~~~........~~~~~:..~~............
...........~~~~~~....~~:...~~~~~~....~~.......~~~........~~~~~.~~:..............
..........~~~~~~~:~~~......~~~~~..~~..........~~~......~~~~~~~~.................
.........~~~~~~~~~,........~~~~~~~.............~~~..~~~~~~~.....................
........~~~.......................................~~~...........................
.......~~~......................................................................
......~~~.......................................................................
.....~~~........................................................................
.....~~.........................................................................
....,~~.........................................................................
.....~,.........................................................................
................................................................................
................................................................................
................................................................................
................................................................................
................................................................................
                                                                 GlassGiant.com
* Main file.
* This executes the entire watchface and stuff.
* The good meat is inside other files. Go search there instead!
*
*/

#include <pebble.h>
#include "windows/window_rect.h"

Window *window;
TextLayer *dummy_text;
static GFont s_font;

void text_update_proc(void) {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  
  static char buffer_time[] = "00:00";
  if(clock_is_24h_style()) {
    strftime(buffer_time, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    strftime(buffer_time, sizeof("00:00"), "%I:%M", tick_time);
  }
  text_layer_set_text(dummy_text, buffer_time);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  text_update_proc();
}

static void init() {
  // Nico nico ni.
  
  // Load rectangular windows.
  window_rect_push();
  
  // Load custom font.
  s_font = fonts_load_custom_font(
                          resource_get_handle(RESOURCE_ID_FONT_LEAGUE_BOLD_36));
  
  // Handle window.
  window = window_create();
  
  // Handle text.
  Layer* window_layer = window_get_root_layer(window);
  GRect window_bounds = layer_get_bounds(window_layer);
  
  dummy_text = text_layer_create(window_bounds);
  text_layer_set_text_color(dummy_text, GColorRed);
  text_layer_set_text_alignment(dummy_text, GTextAlignmentCenter);
  text_layer_set_font(dummy_text, s_font);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(dummy_text));
  
  window_stack_push(window, true);
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
}

static void deinit() {
  // Anata no ha-to ni Nico Nico Ni!
  
  // Dehandle window.
  window_destroy(window);
  
  // Dehandle text.
  text_layer_destroy(dummy_text);
}

int main() {
  init();
  app_event_loop();
  deinit();
}