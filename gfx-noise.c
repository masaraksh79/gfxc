#include <stdio.h>
#include <stdlib.h>
#include "gfxc.h"

#define MAX_RADIOS_NEED_DATA  10
#define MAX_SLOTS_PER_RADIO   20

// Example of how to run the bar function per given cycle
// Randomize ids and slots requested each time called
void gfx_gen_ids_slots(m16 max_cycle)
{
   m8 i, radios_participating = 0;
   int with_ids = 0, with_slots = 1;

   if (0 <= (radios_participating = random() % MAX_RADIOS_NEED_DATA))
   {
      stf_gfx_ids_t radio_slots[radios_participating];
      m16 slots = 0;
      //printf("\nRadios participating: %d\n", radios_participating);

      for (i = 0; i < radios_participating; i++)
      {
         radio_slots[i].slots = 1 + random() % MAX_SLOTS_PER_RADIO;
         radio_slots[i].id    = 1 + random() % MAX_RRU_NUMBER;

         slots += radio_slots[i].slots;
         
         if (slots > max_cycle)
         {
            radio_slots[i].slots = radio_slots[i].slots + max_cycle - slots;
            radios_participating = i;
            //printf("Exceeded %d slots\n", max_cycle);
            break;
         }

         //printf("Radios %d slots %d\n", radio_slots[i].id, radio_slots[i].slots);
      }


      //Example of executing this API function
      gfxc__bar_by_id(radio_slots, radios_participating, with_ids, with_slots, max_cycle);
   }
}