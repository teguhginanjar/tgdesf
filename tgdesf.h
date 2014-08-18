
#ifndef __TGDESF_INTERNAL_H___
#define __TGDESF_INTERNAL_H___




// TODO define all error code here from m0571.pdf
#define FILE_NOT_FOUND		0xF0
#define INTEGRATED_DERROR	0x1E
#define OUT_OF_EEPROM_ERROR	0x0E
#define OPERATION_OK		0x00
#define AUTHENTHIC_ERROR	0xAE
#define NO_CHANGES			0x0C
#define COMMAND_ABORTED		0xCA
#define ADDITIONAL_FRAME	0xAF
#define PARAMETER_ERROR		0x9E
#define BOUNDARY_ERROR		0xBE
#define NO_SUCH_KEY			0x40
#define PICC_DISABLED_ERROR	0xCD
#define LENGTH_ERROR		0x7E
#define PERMISSION_DENIED	0x9D
#define ILLEGAL_COMMAND_CODE	0x1C
#define EEPROM_ERROR		0xEE
#define FILE_INTEGRITY_ERROR	0xF1
#define FILE_DUPLICATE_ERROR	0xDE
#define APPLICATION_NOT_FOUND	0xA0


#ifdef __cplusplus 
#define extern "C" { 
#endif 

typedef unsigned char byte_t;



typedef enum {
	DES		= 0, 
	TDES	, 
	AES		, 
	TDES2KEY, 
	TDES3KEY,
}
EN_type_auth;


typedef enum {
	PLAIN 		= 0, 
	MACED		= 0x01, 
	FULLY_ENC	= 0x03
}
EN_comset;


typedef struct {
	int 			keyno;
	byte_t 			sessionkey[16];
	byte_t 			sessionkey24[24];
	byte_t 			retval;
	EN_type_auth 	typeauth;
	EN_comset		comset;	 	
}
TgdesfCtx_t;



byte_t	tgdesf_authenticate (TgdesfCtx_t * ctx,  EN_type_auth en );
void	tgdesf_print_err (TgdesfCtx_t * ctx);
byte_t  (*tgdesf_trancieve) (void * un);




#ifdef __cplusplus 
#define }
#endif 

#endif 
