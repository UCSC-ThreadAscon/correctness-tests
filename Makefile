CC = clang 
CFLAGS = -Wall -Werror -Wextra -Wpedantic
HEADERS = ./libascon/ascon.h 							\
					./libascon/ascon_internal.h
OBJECTS = ./libascon/ascon_permutations.o \
					./libascon/ascon_hash.o 				\
					./libascon/ascon_buffering.o 		\
					./libascon/ascon_aead128a.o 		\
					./libascon/ascon_aead128.o 			\
					./libascon/ascon_aead80pq.o 		\
					./libascon/ascon_aead_common.o
BINARIES = example test-encrypt decrypt-mac-ascon128

.PHONY: libascon

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

libascon:
	$(MAKE) -C libascon

clean:
	rm -r -f $(wildcard *.o) $(BINARIES) test-decrypt decrypt-mac-ascon128a decrypt-mac-ascon128 decrypt-mle-ascon128a decrypt-mle-ascon128
	cd libascon && $(MAKE) clean

check:
	leaks --atExit -- ./decrypt-mac-ascon128
	leaks --atExit -- ./decrypt-mac-ascon128a
	leaks --atExit -- ./decrypt-mle-ascon128a
	leaks --atExit -- ./decrypt-mle-ascon128

parse-ascon128a:
	# Commissioning MAC
	python3 ./parse.py --path testdata/commissioning/ascon128a/border-router.txt --start 1803 --end 1821
	python3 ./parse.py --path testdata/commissioning/ascon128a/border-router.txt --start 1825 --end 1844
	python3 ./parse.py --path testdata/commissioning/ascon128a/border-router.txt --start 1845 --end 1861
	python3 ./parse.py --path testdata/commissioning/ascon128a/border-router.txt --start 1923 --end 1937

	# MLE Commisioning Packets
	python3 ./parse.py --path testdata/mle-commissioning/ascon128a/border-router.txt --start 826 --end 855
	python3 ./parse.py --path testdata/mle-commissioning/ascon128a/border-router.txt --start 873 --end 895

	# Time Sync (MLE)
	python3 ./parse.py --path testdata/time-sync/ascon128a/delay-server.txt --start 964 --end 978

	# SED Encrypt
	python3 ./parse.py --path testdata/sed-encrypt-mac/ascon128a/sed.txt --start 578 --end 595

	# SED Decrypt
	python3 ./parse.py --path testdata/sed-decrypt-mac/ascon128a/border-router.txt --start 1543 --end 1558