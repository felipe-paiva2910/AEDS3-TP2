CC=gcc
IDIR=../includes
CFLAGS=-I$(IDIR)

ODIR=obj
LIBS=-lm
DEPS= grid.h pd.h file.h

_DEPS = grid.h pd.h file.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = grid.o pd.o file.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
