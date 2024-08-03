/**
 * This file DECRYPTS can decrypt any packet shown in
 * "ascon128a-mac-decrypt-test.txt".
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>

#include "libascon/ascon.h"
#include "libascon/common.h"

/**
 * From the file "ascon128a-mac-decrypt-test1.txt".
*/
void test1(void) {
  uint8_t key[] = {0x30, 0xB9, 0x7A, 0x04, 0xA0, 0x2B, 0x0E, 0xA0,
                   0x80, 0xDF, 0x63, 0xFC, 0x97, 0xA5, 0x7D, 0x7F};

  uint8_t nonce[] = {0x80, 0x01, 0x00, 0x09, 0x87, 0x3F, 0x00, 0x00,
                     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t assocData[] = {0x00, 0xBC, 0x01, 0xBC, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t tag[] = {
    0xA5, 0x01, 0x7A, 0xB6
  };

  uint8_t payload[] = {
    0xA4, 0x85, 0x09, 0x14, 0x5E, 0xA9, 0x4C, 0xBC, 0x96, 0x34, 0xD7, 0x20, 0xAD
  };

  bool status = ascon_aead128a_decrypt(payload, key, nonce, assocData, payload,
                                       tag, CRYPTO_ABYTES, sizeof(payload),
                                       sizeof(tag));
  if (status == ASCON_TAG_OK) {
    printf("Test 1 ASCON decryption success!\n");
  }
  else {
    printf("Test 1 ASCON decryption failure.\n");
  }
}

int main(void) {
  test1();
  return 0;
}
