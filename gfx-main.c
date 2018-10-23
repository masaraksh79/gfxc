#include <stdio.h>
#include <stdlib.h>

typedef unsigned short m16;
typedef unsigned char m8;

typedef struct
{
   unsigned short id;
   unsigned char slots;
}
stf_gfx_ids_t;

#define MMX_GFX_SLOT '*'
#define MMX_GFX_DELIM '|'
#define MMX_GFX_SPACE ' '
#define MMX_GFX_EOL '\n'
int get_id_length(m16 id)
{
   if (id > 99) return 3;
   else if (id > 9) return 2;
   else return 1;
}

/* stuff bar graph by IDs */
void stf_bar_by_id(stf_gfx_ids_t *rdios, m8 elms)
{
   m8 i, j; 

   putchar(MMX_GFX_DELIM);
   // Print the stars, for slots
   for (i = 0; i < elms; i++)
   {
      for (j = 0; j < rdios[i].slots; j++) 
         putchar(MMX_GFX_SLOT);
      
      putchar(MMX_GFX_DELIM);
   }

   putchar(MMX_GFX_EOL);
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

int main()
{
   stf_gfx_ids_t ids[] = 
   {
      { .id = 3, .slots = 2 },
      { .id = 28, .slots = 6 },
      { .id = 117, .slots = 4 },
      { .id = 16, .slots = 17 },
   };

   stf_bar_by_id(ids, sizeof(ids) / sizeof(stf_gfx_ids_t));
   return 0;
}