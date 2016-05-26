/**
* idol_rng
* Welcome to idol hell.
* This code organizes the randomization of your beloved idol witches.
* At a different tick (probably an hour tick), the idol on the clock
* will change. Correspondingly, other aspects will change too.
*
* IDOL RNG:
* 0: ELI
* 1: HONOKA
* 2: KOTORI
* 3: MAKI
* 4: NICO
* 5: NOZOMI
* 6: HANAYO
* 7: RIN
* 8: UMI
*
* TODO:
*  It would be cool to make a configuration page that has you
*  selecting more bias for certain idols.
*
**/

#include <pebble.h>
#include "data/idol_rng.h"

// The best enum.
enum idol {
  Eli,
  Honoka,
  Kotori,
  Maki,
  Nico,
  Nozomi,
  Hanayo,
  Rin,
  Umi,
  Null
};

// In some future version, we can change this to reflect
// a configurable set of random values.
static int bias[9] = {10,10,10,10,10,10,10,10,10};
static int bias_size = 90;

static enum idol current_idol = Null;

static void update_idol() {
  int r, i;
  
  do {
    // First, generate a random number from 0 to bias_size.
    r = rand() % bias_size;
    i = 0;
    // Do a while-loop until the random number is < bias[i] or is at the end.
    // Whenever we exit the loop is what our idol girl should be.
    while(r > bias[i] && i < 9) {
      r -= bias[i++];
    }
  } while (i == current_idol); // If the randomization turns out to yield the same idol, no thanks, It should change per hour.
                               // TODO: We can create a boolean in the configuration to stop this behavior though. Let's do that.
  
  // Update the current idol to our new hero.
  current_idol = i;
}

// This should be invoked in the time manager.
void idol_rng_update_proc() {
  update_idol();
}

GColor get_idol_main_color() {
  // For the main rectangle and spot text.
  
  // If we're using Aplite, then just return a black-based color. 
  #if defined(PBL_BW)
    return GColorBlack;
  #endif
  
  switch(current_idol) {
    case Eli:
      return GColorPictonBlue;
    case Honoka:
      return GColorOrange;
    case Kotori:
      return GColorLightGray;
    case Maki:
      return GColorRed;
    case Nico:
      return GColorFashionMagenta;
    case Nozomi:
      return GColorImperialPurple;
    case Hanayo:
      return GColorMalachite;
    case Rin:
      return GColorChromeYellow;
    case Umi:
      return GColorBlueMoon;
    default:
      return GColorDarkGray;
  }  
}

GColor get_idol_sub_color() {
  // For the little guy.
  
  // If we're using Aplite, then just return a medium-light based color.
  #if defined(PBL_BW)
    return GColorVeryLightBlue;
  #endif

  switch(current_idol) {
    case Eli:
      return GColorIcterine;
    case Honoka:
      return GColorBabyBlueEyes;
    case Kotori:
      return GColorInchworm;
    case Maki:
      return GColorVividCerulean;
    case Nico:
      return GColorDarkGray;
    case Nozomi:
      return GColorRichBrilliantLavender;
    case Hanayo:
      return GColorBrass;
    case Rin:
      return GColorCadetBlue;
    case Umi:
      return GColorRajah;
    default:
      return GColorLightGray;
  }
}

GBitmap* get_idol_sprite() {
  // Who doesn't love switch cases?
  switch(current_idol) {
    case Eli:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ELI);
    case Honoka:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_HONK);
    case Kotori:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_KOTORI);
    case Maki:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_MAKI);
    case Nico:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_NICO);
    case Nozomi:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_NOZO);
    case Hanayo:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_PANA);
    case Rin:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_RIN);
    case Umi:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_UMI);
    default:
      return gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ELI);
  }    
}