#include <stdio.h>
#include <stdlib.h>
#include "gfxc.h"

int get_id_length(m16 id)
{
   if (id > 99) return 3;
   else if (id > 9) return 2;
   else return 1;
}

void gfx_set_border(stf_gfx_ids_t *rdios, m8 elms, m8 max_slots, m16* occ_slots, m16* free_slots)
{
   m8 i, j;
   m16 slots = 0;

   // Print the border
   for (i = 0; i < elms; i++)
   {
      for (j = 0; j < rdios[i].slots; j++) 
         putchar(MMX_GFX_BORDER);

      slots += rdios[i].slots;
      putchar(MMX_GFX_BORDER);
   }

   if (max_slots > slots)
   {
      // Print the -'s for rest of unused slots
      for (j = 0; j < max_slots - slots; j++) 
         putchar(MMX_GFX_BORDER);
   }
   
   printf(MMX_GFX_BSUFFIX);

   //for (j = 0; j < MMX_GFX_DELIMS; j++) 
   //   putchar(MMX_GFX_BORDER);

   putchar(MMX_GFX_EOL);

   *occ_slots = slots;
   *free_slots = max_slots - slots;
}

void gfxc__avg_stats(data_ma_t* pma, m16 sample, m8 ma)
{
   pma->d = pma->d_prev + sample - (pma->d_prev >> ma);
   pma->d_prev = pma->d;
}

m32 gfxc__get_avg(data_ma_t* pma, m8 ma)
{
   return (m32)(pma->d >> ma);
}

/* stuff bar graph by IDs */
void gfxc__bar_by_id(stf_gfx_ids_t *rdios, m8 elms, m8 with_ids, m8 with_slots, m8 max_slots)
{
   m8 i, j;
   m16 slots = 0;
   m16 occ_slots, free_slots; 

   gfx_set_border(rdios, elms, max_slots, &occ_slots, &free_slots);

   printf("- Graph ");

   putchar(MMX_GFX_DELIM);
   // Print the stars, for slots
   for (i = 0; i < elms; i++)
   {
      for (j = 0; j < rdios[i].slots; j++) 
      {
         putchar(MMX_GFX_SLOT);
         slots += rdios[i].slots;
      }
      putchar(MMX_GFX_DELIM);
   }

   if (with_ids)
   {
      putchar(MMX_GFX_EOL);
      printf("- R-IDs ");
      putchar(MMX_GFX_DELIM);

      for (i = 0; i < elms; i++)
      {
         m8 idlen = get_id_length(rdios[i].id);
         // hide ID if wider than the slots number
         if (idlen == rdios[i].slots)
         {
            printf("%d", rdios[i].id);
         }
         else if (idlen < rdios[i].slots)
         {
            m8 k, del = rdios[i].slots - idlen;
            printf("%d", rdios[i].id);
            for (k = 0; k < del; k++) 
               putchar(MMX_GFX_SPACE);
         }
         else
         {
            m8 k;
            for (k = 0; k < rdios[i].slots; k++) 
               putchar(MMX_GFX_SPACE);
         }

         putchar(MMX_GFX_DELIM);
      }
   }

   if (with_slots)
   {
      putchar(MMX_GFX_EOL);
      printf("- Slots ");
      putchar(MMX_GFX_DELIM);

      for (i = 0; i < elms; i++)
      {
         m8 idlen = get_id_length(rdios[i].slots);
         // hide ID if wider than the slots number
         if (idlen == rdios[i].slots)
         {
            printf("%d", rdios[i].slots);
         }
         else if (idlen < rdios[i].slots)
         {
            m8 k, del = rdios[i].slots - idlen;
            printf("%d", rdios[i].slots);
            for (k = 0; k < del; k++) 
               putchar(MMX_GFX_SPACE);
         }
         else
         {
            m8 k;
            for (k = 0; k < rdios[i].slots; k++) 
               putchar(MMX_GFX_SPACE);
         }

         putchar(MMX_GFX_DELIM);
      }
   }

   putchar(MMX_GFX_EOL);
   gfx_set_border(rdios, elms, max_slots, &occ_slots, &free_slots);
   printf("- Occupied slots: %d Free slots %d Total slots %d\n", occ_slots, free_slots, max_slots);

   {
      static data_ma_t p_max = {.d = 0, .d_prev = 0}; 
      static data_ma_t p_occ = {.d = 0, .d_prev = 0}; 
      m32 av_max, av_occ;
      
      gfxc__avg_stats(&p_max, max_slots, MAC_AVG_C);
      av_max = gfxc__get_avg(&p_max, MAC_AVG_C);
      gfxc__avg_stats(&p_occ, occ_slots, MAC_AVG_C);
      av_occ = gfxc__get_avg(&p_occ, MAC_AVG_C);

      printf("- Average cycle: %lu Busy %lu Total\n", av_occ, av_max);
   }

   putchar(MMX_GFX_EOL);
}
