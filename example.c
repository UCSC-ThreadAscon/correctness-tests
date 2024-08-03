#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libascon/ascon.h"

int main(void)
{
  // We need the key and the nonce, both 128 bits.
  // Note: Ascon80pq uses longer keys
  const uint8_t secret_key[ASCON_AEAD128_KEY_LEN] = {
      1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6};
  const uint8_t unique_nonce[ASCON_AEAD_NONCE_LEN] = {
      1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6};

  // For the "offline" operation, we need all data to be already contiguous
  // in memory. The operation is just one Ascon function call for the user.
  const char associated_data[] = "1 contiguous message will follow.";
  const char plaintext[] = "Hello, I'm a secret message and I should be encrypted!";

  uint8_t buffer[100];
  uint8_t tag[42];
  // To showcase the LibAscon extensions, we will generate an arbitrary-length
  // tag. Here is 42 bytes, but shorter-than-default (16) tags are also
  // possible e.g. 12 bytes for systems with heavy limitations.
  ascon_aead128_encrypt(buffer,
                        tag,
                        secret_key,
                        unique_nonce,
                        (uint8_t *)associated_data,
                        (uint8_t *)plaintext,
                        strlen(associated_data),
                        strlen(plaintext),
                        sizeof(tag));
  // The function zeroes out the context automatically.

  // The decryption looks almost the same. Just for fun, we will again
  // reuse the same buffer where the ciphertext is to write the plaintext into.
  bool is_tag_valid = ascon_aead128_decrypt(buffer, // Output plaintext
                                            secret_key,
                                            unique_nonce,
                                            (uint8_t *)associated_data,
                                            (uint8_t *)buffer, // Input ciphertext,
                                            tag,               // Expected tag the ciphertext comes with
                                            strlen(associated_data),
                                            strlen(plaintext),
                                            sizeof(tag));
  // This time we get a boolean as a return value, which is true when
  // the tag is OK. To avoid confusion, it can also be compared to
  // two handy macros
  if (is_tag_valid == ASCON_TAG_OK)
  {
    puts("Correct decryption!");
  }
  else
  { // ASCON_TAG_INVALID
    puts("Something went wrong!");
  }
  // The function zeroes out the context automatically.
  return 0;
}
