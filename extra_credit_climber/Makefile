CCBIN=/usr/bin/gcc
CC=$(CCBIN) -Wall -Wextra -std=c99 -pedantic -g

default: climb

legal_position:  lib/*.h legal_position.c legal_position_main.c
	$(CC) -O3 -o legal_position legal_position.c legal_position_main.c -lm

climb:  lib/*.h climb.c hashtable.c legal_position.c
	$(CC) -O3 -o climb climb.c hashtable.c legal_position.c -lm

.PHONY: clean
clean:
	rm -Rf *.o lib/*.o *.dSYM *.txt climb legal_position 

.PHONY: package
package:
	tar -cvzf climber-handin.tgz *
