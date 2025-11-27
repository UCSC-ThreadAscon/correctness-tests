// This file can decrypt the MAC packet content shown in "aeadTest128.md" 
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
// #include "ascon_aead128_ref/permutations.h"
#include "ascon_aead128_ref/printstate.h"
// #include "ascon_aead128_ref/printstate.c"
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

// Content is from the MAC output of the test file "asconTest128.md".

int test1(void) {
  uint8_t key[] = { 0x77, 0x3E, 0x93, 0x40, 0x88, 0xC6, 0x58, 0xE0,
                    0x02, 0x91, 0xBB, 0x5A, 0xE6, 0xC7, 0x88, 0x10}; //k
  //unsigned char* const_uns_char_ptr_key = uint8_t_to_const_uns_char_ptr(key);

  uint8_t nonce[] = { 0x5E, 0x23, 0xFE, 0x24, 0xCE, 0x91, 0x00, 0xD7,
                      0x00, 0xA5, 0xD0, 0x05, 0x05, 0x00, 0x00, 0x00 };    // npub
  //const unsigned char* const_uns_char_ptr_nonce = uint8_t_to_const_uns_char_ptr(nonce);

  uint8_t assocData[] = { 0x00, 0x6C, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 
                          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  //const unsigned char* const_uns_char_ptr_assocData = uint8_t_to_const_uns_char_ptr(assocData);
  //unsigned long long assocData_len = const_int_to_uns_long_long(16);        // adlen

  // uint8_t tag[] = { 0x6C, 0xC0, 0xDE, 0x95 };   // keep around the seperate tag and payload, just in case we need them

  // uint8_t payload[] = { 0xB0, 0xB8, 0xD9, 0x70, 0xBC, 0xBF, 0xE7, 0xF3,   0x56, 0x6E, 0xFA, 0xF9, 0xA6, 0x53, 0x4C, 0xDE,  0x01, 0xA5, 0x56, 0x4D, 0x89, 0xB1, 0x34, 0x2E,  0xBC, 0x34, 0x47, 0xCF, 0x54, 0x5B        };    // c (ciphertext)

  uint8_t payload_tag[] = { 0xB0, 0xB8, 0xD9, 0x70, 0xBC, 0xBF, 0xE7, 0xF3,
                            0x56, 0x6E, 0xFA, 0xF9, 0xA6, 0x53, 0x4C, 0xDE,
                            0x01, 0xA5, 0x56, 0x4D, 0x89, 0xB1, 0x34, 0x2E,
                            0xBC, 0x34, 0x47, 0xCF, 0x54, 0x5B,  0x6C, 0xC0, 0xDE, 0x95};    // c (ciphertext)
  //const unsigned char* const_uns_char_ptr_payload_tag = uint8_t_to_const_uns_char_ptr(payload_tag);
  //unsigned long long payload_tag_len = const_int_to_uns_long_long(34);    // clen, including tag (30 + 4 = 34)

  unsigned char* nsec = NULL;  // TODO: Probably need to revise this later
  unsigned char* plaintext = NULL;                 // The plaintext and payload are DIFFERENT THINGS
  unsigned long long plaintext_len = sizeof(plaintext); 
  //unsigned long long plaintext_len = const_int_to_uns_long_long(0);
  unsigned long long* plaintext_len_ptr = &(plaintext_len);
  
  int tag_verified = crypto_aead_decrypt(plaintext, plaintext_len_ptr, nsec, payload_tag, sizeof(payload_tag), assocData, sizeof(assocData), nonce, key);
  //int tag_verified = crypto_aead_decrypt(plaintext, plaintext_len_ptr, nsec, const_uns_char_ptr_payload_tag, payload_tag_len, const_uns_char_ptr_assocData, 
  //                                        assocData_len, const_uns_char_ptr_nonce, const_uns_char_ptr_key);
  
  printf("Test 1: ASCON_AEAD128 decryption ");
  if (tag_verified == 0) {    // Sucess is 0, failure is any other value
    printf("Success!\n");
  } else {
    printf("Failure!\n");
  }
   
  return 0; 
}

int main(void) {    // add tests as nessesary
  test1();
  return 0;
}
