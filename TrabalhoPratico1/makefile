#-*-MakeFile-*-#

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRC = Source.c Funcoes.c	
OBJ = $(SRC:.c=.o)
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# make clean to remove all generated .o files and the executable
clean:
	rm -f $(OBJ) $(TARGET)
