#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gfxc.h"

void gfx_gen_ids_slots(m16 max_cycle);

int main(int argc, char** argv)
{
   m16 cycle = 100;
   m16 i, iter = 1;
   int cmd_option;
   m32 seed = 1324234;

	while ((cmd_option = getopt(argc, argv, "s:c:i:")) != -1)
	{
		/* do something with the option */
		switch(cmd_option)
		{
			case 's':
			    seed = atol(optarg);
			    break;
			case 'c':
			    cycle = atol(optarg);
			    break;
			case 'i':
			    iter = atol(optarg);
			    break;
			default:	/* due to incorrect use */
				printf("Error! Bad args!");
				break;
		}
	}


   srand(seed);

   for (i = 0; i < iter; i++)
      gfx_gen_ids_slots(cycle);

   return 0;
}