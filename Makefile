CC = clang 
CFLAGS = -Wall -Werror -Wextra -Wpedantic
HEADERS = ascon.h ascon_internal.h
OBJECTS = ascon_permutations.o ascon_hash.o ascon_buffering.o ascon_aead128a.o ascon_aead128.o ascon_aead80pq.o ascon_aead_common.o
BINARIES = example test-encrypt decrypt-mac-ascon128

all: example decrypt-mac-ascon128 decrypt-mac-ascon128a decrypt-mle-ascon128a decrypt-mle-ascon128

test:
	./decrypt-mac-ascon128
	./decrypt-mac-ascon128a
	./decrypt-mle-ascon128a
	./decrypt-mle-ascon128

decrypt-mle-ascon128: decrypt-mle-ascon128.o
	$(CC) $(OBJECTS) decrypt-mle-ascon128.o -o decrypt-mle-ascon128 -g

decrypt-mle-ascon128.o: $(HEADERS) $(OBJECTS) decrypt-mle-ascon128.c
	$(CC) $(CFLAGS) -c decrypt-mle-ascon128.c -g

decrypt-mle-ascon128a: decrypt-mle-ascon128a.o
	$(CC) $(OBJECTS) decrypt-mle-ascon128a.o -o decrypt-mle-ascon128a -g

decrypt-mle-ascon128a.o: $(HEADERS) $(OBJECTS) decrypt-mle-ascon128a.c
	$(CC) $(CFLAGS) -c decrypt-mle-ascon128a.c -g
decrypt-mac-ascon128a: decrypt-mac-ascon128a.o
	$(CC) $(OBJECTS) decrypt-mac-ascon128a.o -o decrypt-mac-ascon128a -g

decrypt-mac-ascon128a.o: $(HEADERS) $(OBJECTS) decrypt-mac-ascon128a.c
	$(CC) $(CFLAGS) -c decrypt-mac-ascon128a.c -g

decrypt-mac-ascon128: decrypt-mac-ascon128.o
	$(CC) $(OBJECTS) decrypt-mac-ascon128.o -o decrypt-mac-ascon128 -g

decrypt-mac-ascon128.o: $(HEADERS) $(OBJECTS) decrypt-mac-ascon128.c
	$(CC) $(CFLAGS) -c decrypt-mac-ascon128.c -g

example: $(HEADERS) $(OBJECTS) example.o
	$(CC) $(OBJECTS) example.o -o example -g

example.o: $(HEADERS) $(OBJECTS) example.c
	$(CC) $(CFLAGS) -c example.c -g

ascon_aead_common.o: $(HEADERS) ascon_aead_common.c
	$(CC) $(CFLAGS) -c ascon_aead_common.c

ascon_aead80pq.o: $(HEADERS) ascon_aead80pq.c
	$(CC) $(CFLAGS) -c ascon_aead80pq.c

ascon_aead128.o: $(HEADERS) ascon_aead128.c
	$(CC) $(CFLAGS) -c ascon_aead128.c

ascon_aead128a.o: $(HEADERS) ascon_aead128a.c
	$(CC) $(CFLAGS) -c ascon_aead128a.c

ascon_buffering.o: $(HEADERS) ascon_buffering.c
	$(CC) $(CFLAGS) -c ascon_buffering.c

ascon_hash.o: $(HEADERS) ascon_hash.c
	$(CC) $(CFLAGS) -c ascon_hash.c

ascon_permutations.o: $(HEADERS) ascon_permutations.c
	$(CC) $(CFLAGS) -c ascon_permutations.c

clean:
	rm -r -f $(wildcard *.o) $(BINARIES) test-decrypt decrypt-mac-ascon128a decrypt-mac-ascon128 decrypt-mle-ascon128a decrypt-mle-ascon128

check-decrypt:
	leaks --atExit -- ./decrypt-mac-ascon128
