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
#include "data/config_manager.h"
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

static enum idol current_idol = Null;
static bool initial_call = true;

// Change the bias rates.
static void update_bias() {
  for(int i = 0; i < 9; i++) {
    bias[i] = persist_read_int(i) ? persist_read_int(i) : 10;
  }
}

// Find the length of bias based on the settings
static int bias_length() {
  int j = 0;
  for(int i = 0; i < 9; i++) {
    j += bias[i];
  }
  return j;
}


static void update_idol() {
  
  update_bias();
  
  int r, i;
  
  do {
    // First, generate a random number from 0 to bias_size.
    r = rand() % bias_length();
    i = 0;
    // Do a while-loop until the random number is < bias[i] or is at the end.
    // Whenever we exit the loop is what our idol girl should be.
    while(r > bias[i] && i < 9) {
      r -= bias[i++];
    }
  } while (i == current_idol && !(persist_read_int(KEY_TOGGLE_SAME))); // If the randomization turns out to yield the same idol, no thanks. Unless the bool config!
  
  // Update the current idol to our new hero.
  current_idol = i;
}

// This should be invoked in the time manager.
// For random's sake, we can have some running counter that,
// once it hits 60, the idol will change. Configuration pages would be cool too.
void idol_rng_update_proc(int min_counter) {
  
  int compare_rate = (persist_read_int(KEY_SLIDER_SPAWN)) ? persist_read_int(KEY_SLIDER_SPAWN) : 1;
  // Only change the idol sprite after a spawn rate.
  
  //printf("%d", min_counter);
  //printf("%d", compare_rate);
  
  if( ( (min_counter % compare_rate) == 0) || initial_call) {
    if(initial_call) {
      initial_call = false;
    }
    update_idol();
  }
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

uint32_t get_idol_sprite() {
  // Who doesn't love switch cases?
  int r = rand() % 2;
  
  switch(current_idol) {
    case Eli:
      //printf("Eli with %d", r);
      return (r ? RESOURCE_ID_IMAGE_ELI : RESOURCE_ID_IMAGE_ELI_2);
    case Honoka:
      //printf("Honoka with %d", r);
      return (r ? RESOURCE_ID_IMAGE_HONK : RESOURCE_ID_IMAGE_HONK_2);
    case Kotori:
      //printf("Kotori with %d", r);
      return (r ? RESOURCE_ID_IMAGE_KOTORI : RESOURCE_ID_IMAGE_KOTORI_2);
    case Maki:
      //printf("Maki with %d", r);    
      return (r ? RESOURCE_ID_IMAGE_MAKI : RESOURCE_ID_IMAGE_MAKI_2);
    case Nico:
      //printf("Nico with %d", r);    
      return (r ? RESOURCE_ID_IMAGE_NICO : RESOURCE_ID_IMAGE_NICO_2);
    case Nozomi:
      //printf("Nozomi with %d", r);    
      return (r ? RESOURCE_ID_IMAGE_NOZO : RESOURCE_ID_IMAGE_NOZO_2);
    case Hanayo:
      //printf("Pana with %d", r);    
      return (r ? RESOURCE_ID_IMAGE_PANA : RESOURCE_ID_IMAGE_PANA_2);
    case Rin:
      //printf("Rin with %d", r);    
      return (r ? RESOURCE_ID_IMAGE_RIN : RESOURCE_ID_IMAGE_RIN_2);
    case Umi:
      //printf("Umi with %d", r);    
      return (r ? RESOURCE_ID_IMAGE_UMI : RESOURCE_ID_IMAGE_UMI_2);
    default:
      return (RESOURCE_ID_IMAGE_LOGO);
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