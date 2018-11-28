#ifndef GFXC_UTILS_
#define GFXC_UTILS_

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

#endif