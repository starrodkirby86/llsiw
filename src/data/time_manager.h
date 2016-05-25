/**
* time_manager
* Only one service can be subscribed to the tick handler at one time.
* Because of this, we best should create some master function that handles
* all of the timer services.
*
* Then layers will just update based on get data from other data functions.
*
**/

#pragma once

void time_manager_load();
void time_manager_unload();