/**
* string_time
* Keeps track of the time for you.
* To get the current time, call the get_time function with this file included.
* Must be invoked from the time_manager to be of any use.
**/

#include <pebble.h>
#include "data/string_time.h"

static char* buffer_time = "00:00";

// Invoke THIS function with time_manager
void string_time_update_proc() {
  // Updates the string buffer_time, which should hopefully
  // get updated with the right clock time...
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  
  buffer_time = "00:00";
  if(clock_is_24h_style()) {
    strftime(buffer_time, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    strftime(buffer_time, sizeof("00:00"), "%I:%M", tick_time);
  }
  
  // This should have updated buffer_time.
  // printf("Inside string_time it's %s", buffer_time);
}

// Layers should gather data from this function
void get_time(char buffer_input[]) {
  // And now we can just grab from here.
  buffer_input = buffer_time;
  if(!buffer_input) {
    buffer_input = "00:00";
  }
}