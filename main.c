#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>

#include "kuznechik.h"

static void printbuf(char* head, uint8_t* buf, int sz, char* tail);

// Ключ из контрольного примера из ГОСТ Р 34.12-2015.
const uint8_t secret_key[32] = 
{
	0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF,  
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
	0xFE, 0xDC, 0xBA, 0x98, 0x76, 0x54, 0x32, 0x10, 
	0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF  
};

int main( void )
{
kuz_context kuz_cntx;

// Открытый текст из контрольного примера из ГОСТ Р 34.12-2015.
uint8_t msg[16] = { 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x00, 0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88 };

	kuz_set_key( secret_key, &kuz_cntx );

	kuz_encrypt( (const uint8_t *)msg, msg, &kuz_cntx );

		printbuf("CIF: ", msg, 16, "\r\n");

	kuz_decrypt( (const uint8_t *)msg, msg, &kuz_cntx );

		printbuf("MSG: ", msg, 16, "\r\n");

	return 0;
}

static void printbuf(char* head, uint8_t* buf, int sz, char* tail)
{
int i;
	printf(head);
	for(i=0; i<sz; i++) printf("0x%02X, ", buf[i]);
	printf(tail);
}
