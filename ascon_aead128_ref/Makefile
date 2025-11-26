CC = clang 
CFLAGS = -Wall -Werror -Wextra -Wpedantic

AEAD_HEADERS = ./ascon_aead128_ref/api.h  \
				./ascon_aead128_ref/ascon.h  \
				./ascon_aead128_ref/constants.h    \
				./ascon_aead128_ref/permutations.h \
				./ascon_aead128_ref/printstate.h  \
				./ascon_aead128_ref/round.h  \
				./ascon_aead128_ref/word.h  \

AEAD_OBJECTS = ./ascon_aead128_ref/aead.o \
				./ascon_aead128_ref/printstate.o \

all: $(OBJECTS)

aead.o: $(HEADERS) aead.c
	$(CC) $(CFLAGS) -c aead.c

printstate.o: $(HEADERS) printstate.c
	$(CC) $(CFLAGS) -c printstate.c

clean:
	rm -r -f $(wildcard *.o)