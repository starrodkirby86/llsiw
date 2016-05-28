module.exports = [
  
  {
  "type": "heading",
  "id": "main-heading",
  "defaultValue": "Love Live! SIW",
  "size": 1
  },
  
  {
    "type": "text",
    "defaultValue": "Configure various settings here."
  },
  
{
  "type": "section",
  "items": [
    {
      "type": "heading",
      "defaultValue": "Idol Rates"
    },
    {
    "type": "text",
    "defaultValue": "Change how often a certain idol appears. A relatively higher value implies seeing that idol more often."
    },
    {
      "type": "slider",
      "appKey": "slider_eli",
      "defaultValue": 10,
      "label": "Eli",
      "description": "хорошо...",
      "min": 1,
      "max": 10,
      "step": 1
    },
    {
      "type": "slider",
      "appKey": "slider_honk",
      "defaultValue": 10,
      "label": "Honoka",
      "description": "THIS BREAD IS SO DELICIOUS!",
      "min": 1,
      "max": 10,
      "step": 1
    }, 
    {
      "type": "slider",
      "appKey": "slider_kotori",
      "defaultValue": 10,
      "label": "Kotori",
      "description": "(・８・)(・８・)(・８・)(・８・)(・８・)",
      "min": 1,
      "max": 10,
      "step": 1
    }, 
    {
      "type": "slider",
      "appKey": "slider_maki",
      "defaultValue": 10,
      "label": "Maki",
      "description": "I-It's not like I want you to slide that higher...",
      "min": 1,
      "max": 10,
      "step": 1
    }, 
    {
      "type": "slider",
      "appKey": "slider_nico",
      "defaultValue": 10,
      "label": "Nico",
      "description": "Nico nico nii~",
      "min": 1,
      "max": 10,
      "step": 1
    }, 
    {
      "type": "slider",
      "appKey": "slider_nozo",
      "defaultValue": 10,
      "label": "Nozomi",
      "description": "Also known as the spiritual power gauge.",
      "min": 1,
      "max": 10,
      "step": 1
    }, 
    {
      "type": "slider",
      "appKey": "slider_pana",
      "defaultValue": 10,
      "label": "Hanayo",
      "description": "DAREKA TASUKETEEEEEEEE",
      "min": 1,
      "max": 10,
      "step": 1
    }, 
    {
      "type": "slider",
      "appKey": "slider_rin",
      "defaultValue": 10,
      "label": "Rin",
      "description": "Maracas not included.",
      "min": 1,
      "max": 10,
      "step": 1
    },
    {
      "type": "slider",
      "appKey": "slider_umi",
      "defaultValue": 10,
      "label": "Umi",
      "description": "Just because you want to see more of Umi... HOW SHAMELESS!",
      "min": 1,
      "max": 10,
      "step": 1
    }
  ]
},
  
{
  "type": "section",
  "items": [
    {
      "type": "heading",
      "defaultValue": "Other Settings"
    },
    {
      "type": "slider",
      "appKey": "slider_spawn",
      "defaultValue": 30,
      "label": "Change Rate",
      "description": "How often do you want the idols to swap between each other? Please note that this is in minutes.",
      "min": 1,
      "max": 60,
      "step": 1        
    },
    {
      "type": "toggle",
      "appKey": "toggle_taps",
      "label": "Disable Tapping",
      "description": "Disabling tapping would make the text bubble fully visible instead of appearing only during taps. Use this if you want to save battery life.",
      "defaultValue": false
    },
    {
      "type": "toggle",
      "appKey": "toggle_same",
      "label": "Double Idols",
      "description": "When we reach a changing point, is it OK to pick the same idol twice (or more) in a row? Use this if you love to see your best girl for extended periods of time (if longer than four hours, consult a doctor).",
      "defaultValue": false
    }
  ]
},
  
{
  "type": "submit",
  "defaultValue": "Start Live Show!!"
}  
  
];