/**
 * This file DECRYPTS can decrypt any packet shown in
 * "ascon128a-mle-decrypt-test.txt".
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
 * From the file "ascon128a-mle-decrypt-test1.txt".
*/
void test1(void)
{
  uint8_t key[] = {0x89, 0x0F, 0xF9, 0x74, 0x40, 0xEC, 0xF9, 0x66,
                   0x95, 0x87, 0x38, 0xE2, 0x15, 0x28, 0x03, 0x0B};

  uint8_t nonce[] = {0x4E, 0x16, 0x2B, 0xEE, 0xFF, 0x4C, 0x03, 0x16,
                     0x0B, 0x39, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t assocData[] = {0x4E, 0x16, 0x2B, 0xEE, 0xFF, 0x4C, 0x03, 0x16,
                         0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};

  uint8_t tag[] = {
    0xCC, 0x46, 0x22, 0xE4
  };

  uint8_t payload[] = {
    0x26, 0x26, 0xFD, 0xF5, 0xB0, 0xF2, 0x71, 0x18,
    0x56, 0xC1, 0x8C, 0x95, 0x47, 0xCA, 0xAC, 0xF3,
    0x70, 0xA8, 0x11, 0xED, 0xA5, 0x4F, 0xD8, 0xBC,
    0xD7, 0x73, 0x58, 0x3C, 0x63, 0xFC, 0xBD, 0xE5,
    0x98, 0xC0, 0x1A, 0xBB, 0xAE, 0xB9, 0xA9, 0x89,
    0xFC, 0x2C, 0xD8, 0xB6, 0x05, 0x0E, 0xF6, 0x41,
    0xF9, 0xA8, 0x93, 0xEF, 0xB4, 0x3D, 0x81, 0x47,
    0x9E, 0x12, 0x54, 0x34, 0xA8, 0xAA, 0x40, 0xC2,
    0xEC, 0x9E, 0x47, 0x2D, 0x1F, 0x32, 0x11, 0xBB,
    0x91, 0x2D, 0x3B, 0xF5, 0xE4, 0x18, 0x47, 0xB1,
    0x69, 0xEE, 0x07, 0xDF, 0xBD, 0x48, 0xE2, 0x8C,
    0x6F, 0x5F, 0xEC, 0xEA, 0x90, 0x19, 0x28, 0x2F,
    0x1C, 0x8C, 0x25, 0x4D, 0xB9, 0x0E, 0xA7, 0x0F,
    0x4A, 0xD1, 0x93, 0x9F, 0xA0, 0xF2, 0x3A, 0xF9
  };

  bool status = ascon_aead128a_decrypt(payload, key, nonce, assocData, payload,
                                       tag, CRYPTO_ABYTES, sizeof(payload),
                                       sizeof(tag));
  if (status == ASCON_TAG_OK)
  {
    printf("Test 1 ASCON-128a MLE decryption success!\n");
  }
  else
  {
    printf("Test 1 ASCON-128a MLE decryption failure.\n");
  }
  return;
}

/**
 * From the file "ascon128a-mle-decrypt-test2-ftd.txt".
 */
void test2Ftd1(void)
{
  uint8_t key[] = {0x53, 0xC4, 0xE0, 0x19, 0x16, 0xAC, 0xA4, 0xC4,
                   0x5F, 0xD5, 0xCF, 0xFD, 0x76, 0x70, 0x15, 0x53};

  uint8_t nonce[] = {0x42, 0xD5, 0x52, 0x2A, 0x5D, 0xBD, 0xBE, 0x8F,
                     0x2A, 0x91, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t assocData[] = {0x42, 0xD5, 0x52, 0x2A, 0x5D, 0xBD, 0xBE, 0x8F,
                         0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};

  uint8_t tag[] = {0x5C, 0x1E, 0xE1, 0x1C};

  uint8_t payload[] = {0xDA, 0x70, 0xD4, 0x2F, 0x09, 0x88, 0x77, 0xAC,
                       0x89, 0x7B, 0x98, 0xFE, 0x4C, 0xC4, 0x43, 0xDE,
                       0x01, 0xDF, 0x95, 0xBC, 0x4B, 0xB6, 0xEC, 0x9D,
                       0xA5, 0x26, 0x69, 0x96};

  bool status = ascon_aead128a_decrypt(payload, key, nonce, assocData, payload,
                                       tag, CRYPTO_ABYTES, sizeof(payload),
                                       sizeof(tag));
  if (status == ASCON_TAG_OK)
  {
    printf("Test 2 ASCON-128a FTD MLE decryption success!\n");
  }
  else
  {
    printf("Test 2 ASCON-128a FTD MLE decryption failure.\n");
  }
  return;
}

/**
 * From the file "ascon128a-mle-decrypt-test2-br.txt".
 */
void test2Br1(void)
{
  uint8_t key[] = {0x53, 0xC4, 0xE0, 0x19, 0x16, 0xAC, 0xA4, 0xC4,
                   0x5F, 0xD5, 0xCF, 0xFD, 0x76, 0x70, 0x15, 0x53};

  uint8_t nonce[] = {0xE2, 0x4D, 0x0F, 0x6A, 0xD9, 0x1F, 0xFB, 0x06,
                     0x60, 0xDB, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00};

  uint8_t assocData[] = {0xE2, 0x4D, 0x0F, 0x6A, 0xD9, 0x1F, 0xFB, 0x06,
                         0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};

  uint8_t tag[] = {0x7F, 0x33, 0x7D, 0x12};

  uint8_t payload[] = {0xD5, 0x2E, 0x6A, 0x4C, 0x5D, 0x08, 0x97, 0xD5,
                       0xFA, 0xA6, 0x79, 0x59, 0x0C, 0x01, 0x2C, 0x50,
                       0x73, 0x86, 0x2E, 0x07, 0xC5, 0x9C, 0xAB, 0x5F,
                       0xE6, 0xF4, 0xCB, 0x80};

  bool status = ascon_aead128a_decrypt(payload, key, nonce, assocData, payload,
                                       tag, CRYPTO_ABYTES, sizeof(payload),
                                       sizeof(tag));
  if (status == ASCON_TAG_OK)
  {
    printf("Test 2 ASCON-128a Border Router MLE decryption success!\n");
  }
  else
  {
    printf("Test 2 ASCON-128a Border Router MLE decryption failure.\n");
  }
  return;
}

int main(void) {
  test1();
  test2Ftd1();
  test2Br1();
  return 0;
}
