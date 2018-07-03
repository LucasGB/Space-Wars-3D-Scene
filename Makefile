EXE = main
SRC = main.cpp *.cpp
OBJ = $(SRC:.c=.o)
LIBS = -lglut -lGL -lGLU -lm -lSDL -lX11

OPT = -O3
CFLAGS = -c -Wall -Wextra -ansi -pedantic 
LDFLAGS =
CC = gcc

all: $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(LDFLAG) -o $@ $^ $(LIBS)

.cpp.o:
	$(CC) $(OPT) $(CFLAGS) $<

clean:
	rm -f $(EXE) *.o
