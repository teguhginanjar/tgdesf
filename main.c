#include "tgdesf.h"
#include <stdio.h>


int 
main (int argc, char ** argv)
{
	TgdesfCtx_t ctx;
	ctx.typeauth = TDES;
	ctx.comset = PLAIN;
	
	printf ("%X \n", tgdesf_authenticate (&ctx, 10));
	tgdesf_print_err (&ctx);
	return 0;
}
