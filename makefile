CC=clang
CFLAGS=-Wall -std=c17
LDLIBS=-lncurses
OBJ=main.c graphique.c EnsembleMots.c Grille.c Pile.c


boogle: $(OBJ)
	$(CC)  -o  $@  $^ $(LDLIBS)

Grille:  Grille.c Grille.h  EnsembleMots.c Pile.c
	$(CC)  $(CFLAGS) -c  -o  $@  $< 

Pile: Pile.c Pile.h
	$(CC)  $(CFLAGS) -c  -o  $@  $< 


EnsembleMots: EnsembleMots.c EnsembleMots.h
	$(CC) $(CFLAGS)  -c  -o $@  $< 


Test: Test.c Grille.c EnsembleMots.c Pile.c
	$(CC) $(CFLAGS)  -c  -o $@  $<



clean:
	rm -f *.o