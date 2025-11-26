//This file can decrypt the MLE packet content shown in "aeadTest128.md".
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>

#include "ascon_aead128_ref/aead.c"
//#include "ascon_aead128_ref/api.h"
//#include "ascon_aead128_ref/ascon.h"
//#include "ascon_aead128_ref/constants.h"
//#include "ascon_aead128_ref/permutations.h"
#include "ascon_aead128_ref/printstate.h"
//#include "ascon_aead128_ref/printstate.c"
//#include "ascon_aead128_ref/round.h"
//#include "ascon_aead128_ref/word.h"

#define KAT_SUCCESS 0
#define KAT_FILE_OPEN_ERROR -1
#define KAT_DATA_ERROR -3
#define KAT_CRYPTO_FAILURE -4

#define ASCON_AEAD_VALID(status) status == KAT_SUCCESS ? true : false
// line 35 of openthread/src/core/crypto/thread_ascon.hpp: use  ASCON_AEAD_VALID(status) status == KAT_SUCCESS (true or false)

unsigned long long const_int_to_uns_long_long(int num) {
  return (unsigned long long)num;
}

const unsigned char* uint8_t_to_const_uns_char_ptr(uint8_t* arr) {
  return (const unsigned char*)arr;
}

// Content is from the file "aeadTest128.md"

void test1(void)
{
  uint8_t key[] = { 0x10, 0x0D, 0x80, 0x6E, 0x34, 0x22, 0x35, 0x5D,
                    0xF5, 0x46, 0x1D, 0x7D, 0xEE, 0x27, 0xD2, 0xEE };
  //unsigned char* const_uns_char_ptr_key = uint8_t_to_const_uns_char_ptr(key);

  uint8_t nonce[] = { 0x5E, 0x23, 0xFE, 0x24, 0xCE, 0x91, 0x00, 0xD7, 
                      0xCD, 0xD9, 0xA5, 0x00, 0x00, 0x00, 0x00, 0x00 };
  //const unsigned char* const_uns_char_ptr_nonce = uint8_t_to_const_uns_char_ptr(nonce);

  uint8_t assocData[] = { 0x5E, 0x23, 0xFE, 0x24, 0xCE, 0x91, 0x00, 0xD7,
                          0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };
  //const unsigned char* const_uns_char_ptr_assocData = uint8_t_to_const_uns_char_ptr(assocData);
  //unsigned long long assocData_len = const_int_to_uns_long_long(16);        // adlen                        

  // uint8_t tag[] = { 0xFD, 0x49, 0x8A, 0xC7 };

  // uint8_t payload[] = { 0xCF, 0x17, 0xF2, 0x18, 0x92, 0x53, 0x79, 0xB2,   0x2C, 0x74, 0xF3, 0x6D, 0xD7, 0xCE, 0xDC, 0xC3,  0x8D, 0x9D, 0x2B, 0xBF, 0xAA, 0x99, 0xD3, 0xE0,  0x0A, 0x56, 0xCD, 0x36, 0xFD, 0x49, 0x8A, 0xC7 };

  uint8_t payload_tag[] = { 0xCF, 0x17, 0xF2, 0x18, 0x92, 0x53, 0x79, 0xB2, 
                        0x2C, 0x74, 0xF3, 0x6D, 0xD7, 0xCE, 0xDC, 0xC3,
                        0x8D, 0x9D, 0x2B, 0xBF, 0xAA, 0x99, 0xD3, 0xE0,
                        0x0A, 0x56, 0xCD, 0x36, 0xFD, 0x49, 0x8A, 0xC7,  0xFD, 0x49, 0x8A, 0xC7};
  //const unsigned char* const_uns_char_ptr_payload_tag = uint8_t_to_const_uns_char_ptr(payload_tag);
  //unsigned long long payload_tag_len = const_int_to_uns_long_long(34);    // clen, including tag (30 + 4 = 34)

  unsigned char* nsec = NULL;  // TODO: Probably need to revise this later
  unsigned char* plaintext = NULL;                 // The plaintext and payload are DIFFERENT THINGS
  unsigned long long plaintext_len = sizeof(plaintext); 
  //unsigned long long plaintext_len = const_int_to_uns_long_long(0);
  unsigned long long* plaintext_len_ptr = &(plaintext_len);

  int tag_verified = crypto_aead_decrypt(plaintext, plaintext_len_ptr, nsec, payload_tag, sizeof(payload_tag), assocData, sizeof(assocData), nonce, key);
  //int tag_verified = crypto_aead_decrypt(plaintext, plaintext_len_ptr, nsec, const_uns_char_ptr_payload_tag, payload_tag_len, 
  //                                        const_uns_char_ptr_assocData, assocData_len, const_uns_char_ptr_nonce, const_uns_char_ptr_key);

  if (tag_verified == 0) {
    printf("Test 1 ASCON-128 MLE decryption success!\n");
  } else {
    printf("Test 1 ASCON-128 MLE decryption failure.\n");
  }
  return;
}

int main(void) {
  test1();
  return 0;
}