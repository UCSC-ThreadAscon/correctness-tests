/**
 * This file DECRYPTS can decrypt any packet shown in
 * "ascon128-mac-decrypt-test1.txt" or
 * "ascon128-mac-decrypt-test2.txt".
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>

#include "ascon.h"
#include "common.h"

/**
 * From the file "ascon128-mac-decrypt-test1.txt".
*/
void test1(void) {
  uint8_t key[] = {0x30, 0xB9, 0x7A, 0x04, 0xA0, 0x2B, 0x0E, 0xA0,
                   0x80, 0xDF, 0x63, 0xFC, 0x97, 0xA5, 0x7D, 0x7F};

  uint8_t nonce[] = {0xCD, 0x01, 0x00, 0x99, 0xA0, 0xC1, 0x00, 0x00,
                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t assocData[] = {0xFF, 0xFF, 0x4E, 0x16, 0x2B, 0xEE, 0xFF, 0x4C,
                         0x03, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t tag[] = { 0xC3, 0x43, 0x71, 0x22 };

  uint8_t payload[] = {
    0xD6, 0x8A, 0xA7, 0xD7, 0xF4, 0x0F, 0x5D, 0xAA,
    0x89, 0x20, 0x06, 0xF0, 0x9C, 0xAA, 0x77, 0xA3,
    0xCC, 0x84, 0x22, 0x1E, 0x6D, 0xC3, 0x19, 0x75,
    0x72, 0x8E, 0x24, 0xC2, 0x79, 0x6A, 0xD3, 0xCF,
    0x31, 0xB1, 0x47, 0xBE, 0x75, 0xC6, 0x3C, 0xE9,
    0x05, 0x10, 0xE6, 0x6F, 0xDD, 0x54, 0x19, 0x41,
    0x9A, 0xD0, 0xC9, 0x19, 0xED, 0xB2, 0xD8, 0x56,
    0x88, 0x6B, 0xD1, 0x53, 0x01, 0xBA, 0x7E, 0x05,
    0xAD, 0xDD, 0xF7, 0xD5, 0x01, 0xAE, 0x78, 0x6C, 
    0x4F, 0x38, 0xE2, 0x4C, 0xBD, 0x8A, 0xBA, 0x13,
    0x3E, 0x55, 0x07, 0x4D, 0x1E, 0x60, 0x0F, 0x20,
    0x56, 0xD4, 0x5E, 0xEC, 0x74, 0x06
  };

  bool status = ascon_aead128_decrypt(payload, key, nonce, assocData, payload,
                                      tag, CRYPTO_ABYTES, sizeof(payload),
                                      sizeof(tag));
  if (status == ASCON_TAG_OK) {
    printf("Test 1 ASCON decryption success!\n");
  }
  else {
    printf("Test 1 ASCON decryption failure.\n");
  }
}

/**
 * From the file "ascon128-mac-decrypt-test2.txt".
*/
void test2(void) {
  uint8_t key[] = {0x30, 0xB9, 0x7A, 0x04, 0xA0, 0x2B, 0x0E, 0xA0,
                   0x80, 0xDF, 0x63, 0xFC, 0x97, 0xA5, 0x7D, 0x7F};

  uint8_t nonce[] = {0xB9, 0x01, 0x00, 0x09, 0x83, 0x5A, 0x00, 0x00,
                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

  uint8_t assocData[] = {0x00, 0xBC, 0x00, 0x7C, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t tag[] = {0x65, 0x2A, 0x15, 0x30};

  uint8_t payload[] = { 0x3A, 0x1D, 0x27, 0x36, 0x9D, 0x8C, 0xC1, 0x7F,
                        0xB0, 0xF9, 0x87, 0x3E, 0x1D, 0x02, 0xB2, 0xB1,
                        0xFF, 0xF4, 0xB2, 0x6B, 0x54, 0xEB, 0xC3, 0xEF,
                        0xEF, 0x17, 0x3E, 0x49, 0x4C, 0xD8, 0x5F, 0x69,
                        0xF6, 0x9E };

  bool status = ascon_aead128_decrypt(payload, key, nonce, assocData, payload,
                                      tag, CRYPTO_ABYTES, sizeof(payload),
                                      sizeof(tag));
  if (status == ASCON_TAG_OK) {
    printf("Test 2 ASCON decryption success!\n");
  }
  else {
    printf("Test 2 ASCON decryption failure.\n");
  }
}

int main(void) {
  test1();
  test2();
  return 0;
}
