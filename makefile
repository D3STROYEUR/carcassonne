CC=gcc
EXE=exe

CFLAGS= -std=c99 -Wall -pedantic -g  -I$(INC_DIR)

INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

default : $(EXE)

all: $(EXE)


$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ) $(EXE) *~ src/*.o

.PHONY: all clean












