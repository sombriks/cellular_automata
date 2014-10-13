CC=gcc
CFLAGS=--std=gnu99 -Wextra -O2
vpath %.c src/
vpath %.h src/

.PHONY: default
default: cellular_automata

cellular_automata: main.c ca.o io.o gui.o
	$(CC) $(CFLAGS) -o $@ $(filter-out %.h, $^) -lSDL2

sdl_gui.o: gui.c gui.h ca.h
	$(CC) $(CFLAGS) -c $<
io.o: io.c io.h ca.h
	$(CC) $(CFLAGS) -c $<
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	-rm *.o
.PHONY: cleaner
cleaner: clean
	-rm cellular_automata
