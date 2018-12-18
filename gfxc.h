#ifndef GFXC_UTILS_
#define GFXC_UTILS_

typedef long unsigned int  m32;
typedef unsigned short m16;
typedef unsigned char m8;

typedef struct
{
   unsigned short id;
   unsigned char slots;
}
stf_gfx_ids_t;

#define MAX_RRU_NUMBER 99

#define MMX_GFX_SLOT '*'
#define MMX_GFX_DELIM '|'
#define MMX_GFX_BORDER '-'
#define MMX_GFX_BSUFFIX "---------"
#define MMX_GFX_DELIMS 20
#define MMX_GFX_SPACE ' '
#define MMX_GFX_EOL '\n'

#define MAC_AVG_C    2

typedef struct 
{
   m32 d;
   m32 d_prev;
}
data_ma_t;

void gfxc__bar_by_id(stf_gfx_ids_t *rdios, m8 elms, m8 with_ids, m8 with_slots, m8 max_slots);

#endif