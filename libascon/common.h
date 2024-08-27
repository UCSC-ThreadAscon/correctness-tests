/**
 * These macros are not from LibAscon.
 *
 * The macro `CRYPTO_ABYTES` come from the ASCON-C Reference Implementation:
 * https://github.com/ascon/ascon-c/blob/main/crypto_aead/ascon128av12/ref/api.h
 *
 * The macro `OT_NETWORK_KEY_SIZE` come from the OpenThread source code:
 * https://openthread.io/reference/group/api-operational-dataset#group__api-operational-dataset_1ga170e591eb644a6f9282c295c434bedc2
 *
 * Both macros are used to do ASCON AEAD in OpenThread.
 */
#define CRYPTO_ABYTES 16
#define OT_NETWORK_KEY_SIZE 16
