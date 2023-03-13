CC=gcc
CFLAGS=-lm -lTableauNoir -Wall -g -pthread
LDFLAGS=
EXEC=exec
SRC=$(wildcard *.c)

#
#Règles implicites
#
.SUFFIXES: .c
.c.o:
	$(CC) -c $< $(CFLAGS)

$(EXEC): $(patsubst %.c,%.o,$(SRC))
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	rm -Rf *.o $(EXEC)

run: $(EXEC)
	./$(EXEC)

debug: $(EXEC)
	gdb -tui ./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)


## Commandes à ajouter : 
# gnuplot -p -e "plot 'resultats.dat' with lines
# gnuplot -e "set ter png size 1920, 1080; set out 'resultats.png'; plot 'resultats.dat' with line"

