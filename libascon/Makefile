CC = clang 
CFLAGS = -Wall -Werror -Wextra -Wpedantic
HEADERS = ascon.h ascon_internal.h
OBJECTS = ascon_permutations.o \
					ascon_hash.o				 \
					ascon_buffering.o 	 \
					ascon_aead128a.o 		 \
					ascon_aead128.o 		 \
					ascon_aead80pq.o 		 \
					ascon_aead_common.o

all: $(OBJECTS)

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
	rm -r -f $(wildcard *.o)