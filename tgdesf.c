
#include "crypt/des-crypt.h"
#include "tgdesf.h"

#include <stdarg.h>

#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define _GNU_SOURCE
#include <stdio.h>

// sleep secons interval 
int 
tgsleep (double sleep_time)
{
	struct timespec tv;
	
	tv.tv_sec  = (time_t ) sleep_time;
	tv.tv_nsec = (long) ((sleep_time - tv.tv_sec) * 1e+9);

	while (1)	{
		int rval = nanosleep (&tv, &tv);
		if (rval == 0)	return 0;
		else if (errno == EINTR) continue;
		else return rval;
	}
}



char * 
tgstrdup (const char * fmt, ...)
{
	int n;
	int size = 100;
	char * p, *np;
	va_list ap;
	
	if ((p=malloc (size)) == NULL) return NULL;
	

	while (1)	{
		va_start (ap, fmt);
		n = vsnprintf (p, size, fmt, ap);
		va_end(ap);
		if (n>-1 && n < size) return p;
		/* else is try again with more space */
		if (n > -1) size = n+1;
		else size *= 2;
		if ((np = realloc (p, size)) == NULL)	{
			free (p);
			return NULL;
		} else p = np;
	}
}

void
tgprint_log (const char * fmt, ...)
{

	#if 1
	char * tmp;
	int d;
	char c, *s;
	
	
	va_list ap;
	va_start (ap, fmt);
	/*
	while (*fmt)	{
			switch (*fmt++)	{
			case 's': s = va_arg (ap, char *);
				break;
			case 'd' : d = va_arg (ap, int);
				break;
			case 'c': c = va_arg (ap, int);
				break;
			};
		}
		*/
	//tmp = tgstrdup (fmt, ap);
	
	vasprintf(tmp, fmt, ap);
	va_end (ap);
	fprintf (stderr, "%s\n", tmp);
	free (tmp);
	#endif
}




byte_t 
tgdesf_authenticate (TgdesfCtx_t * ctx, EN_type_auth en)
{
	switch (en)	{
	case DES: 
		break;
	case TDES :
		break;
	case AES :
		break;
	case TDES2KEY : 
		break;
	case TDES3KEY : 
		break;
	default : 
		ctx->retval = AUTHENTHIC_ERROR;
		return AUTHENTHIC_ERROR;
		break;
	
	};
	return OPERATION_OK;
}

void	
tgdesf_print_err (TgdesfCtx_t * ctx)
{
	switch (ctx->retval)	{
	case 0xAE : tgprint_log ("(%X) Authenticate Error! \n", ctx->retval); break;
	case 0x1E : break;
	case 0x00 : break;
	case 0xF0 : break;
	case 0x0C : break;
	case 0xCA : break;
	case 0x40 : break;
	case 0x7E : break;
	case 0xDE : break;
	case 0xBE : break;
	case 0x9E : break;
	case 0x9D : break;
	case 0x1C : break;
	case 0x0E : break;
	case 0xEE : break;
	case 0xA0 : break;
	case 0xF1 : break;
	case 0xCD : break;
	case 0xAF : break;
	default : 
		break;	
	};
}
