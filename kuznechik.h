#ifndef KUZNECHIK_H

#define KUZNECHIK_H

typedef struct
{   
	uint8_t round_key_X[10][16];
} kuz_context;

void kuz_set_key( const uint8_t key[32], kuz_context* cntx );
void kuz_encrypt( const uint8_t in[16], uint8_t out[16], kuz_context * cntx );
void kuz_decrypt( const uint8_t in[16], uint8_t out[16], kuz_context * cntx );

void kuz_encrypt_fast( const uint8_t in[16], uint8_t out[16], kuz_context * cntx );

#endif // KUZNECHIK_H