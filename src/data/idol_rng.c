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
// For random's sake, we can have some running counter that,
// once it hits 60, the idol will change. Configuration pages would be cool too.
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
      return GColorVividCerulean;
    case Honoka:
      return GColorOrange;
    case Kotori:
      return GColorLightGray;
    case Maki:
      return GColorFolly;
    case Nico:
      return GColorFashionMagenta;
    case Nozomi:
      return GColorIndigo;
    case Hanayo:
      return GColorJaegerGreen;
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
      return GColorLiberty;
    case Honoka:
      return GColorWindsorTan;
    case Kotori:
      return GColorBrass;
    case Maki:
      return GColorPictonBlue;
    case Nico:
      return GColorDarkGray;
    case Nozomi:
      return GColorPurpureus;
    case Hanayo:
      return GColorLimerick;
    case Rin:
      return GColorPastelYellow;
    case Umi:
      return GColorDukeBlue;
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

void get_idol_phrase(char phrase[]) {
  // NOTE: These catchphrases look like garbage due to the usage of
  // the shortmoji font to workaround Pebble's limited mapping of characters.
  // Comments like these really do shine, don't they? :)
  
  switch(current_idol) {
    case Eli:
      strcpy(phrase,PBL_IF_ROUND_ELSE("afYeh","afYeh"));            // Harasho
      break;
    case Honoka:
      strcpy(phrase,PBL_IF_ROUND_ELSE("bVXZIR","bVXZ-IR"));         // Faito dayo
      break;
    case Kotori:
      strcpy(phrase,PBL_IF_ROUND_ELSE("JQUJQU","JQU-JQU"));         // Chun chun
      break;
    case Maki:
      strcpy(phrase,PBL_IF_ROUND_ELSE("AOTBMA","AO-TBMA"));         // Imi Wakanai
      break;
    case Nico:
      strcpy(phrase,PBL_IF_ROUND_ELSE("NKENKENh","NKE-NKENh"));     // Nico nico nii
      break;
    case Nozomi:
      strcpy(phrase,PBL_IF_ROUND_ELSE("TFTFijk","TFTF-ijk"));       // Washi washi MAX
      break;
    case Hanayo:
      strcpy(phrase,PBL_IF_ROUND_ELSE("ISBHGDL","ISB-HGDL"));       // Dareka tasukete
      break;
    case Rin:
      strcpy(phrase,PBL_IF_ROUND_ELSE("ACNPh","ACNPh"));            // Iku nyaa
      break;
    case Umi:
      strcpy(phrase,PBL_IF_ROUND_ELSE("fcWghYdhZ","fcWgh-YdhZ"));   // Rabu Arrow Shoot
    default:
      break;
    
    
  }   
}