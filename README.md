# UCSC Thread-Ascon Correctness Tests

This repository contains tests which proves that my forks of
[ESP-IDF](https://github.com/UCSC-ThreadAscon/esp-idf) and
[OpenThread](https://github.com/UCSC-ThreadAscon/openthread) are able 
to successfully communicate using both ASCON-128a and ASCON-128.

## Build Instructions

In order to run the tests, first run `make`, then run:
```bash
  make test
```

To remove all the object and binary files, run:
```bash
  make clean
```