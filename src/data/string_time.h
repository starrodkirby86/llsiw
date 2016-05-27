/**
* string_time
* Keeps track of the time for you.
* To get the current time, call the get_time function with this file included.
* Must be invoked from the time_manager to be of any use.
**/

#pragma once

void string_time_update_proc();
void string_date_update_proc();
void get_time(char buffer_input[]);
void get_date(char buffer_input[]);