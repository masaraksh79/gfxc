#include <stdio.h>
#include <stdlib.h>
#include "gfxc.h"

void gfx_gen_ids_slots(m16 max_cycle)
{
   static m8 once = 0;

   if (!once)
   {
      srand(1567);
   }

   while (tslots < max_cycle)
   {
      
   }
}