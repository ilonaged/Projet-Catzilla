CC=g++
CCFLAGS= -Wall -std=c++11 -g
LIBFLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC= $(wildcard *.cc)
OBJ= $(SRC:.cc=.o)
EXEC= Catzilla

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ $(LIBFLAGS) -o $@  

%.o: %.cc
	$(CC) $(CCFLAGS) -o $@ -c $<

.depends: $(SRC)
	@$(CC) -MM $(CCFLAGS) $(SRC) > .depends

-include .depends

clean:
	rm -f $(OBJ) $(EXEC) .depends *.*~
