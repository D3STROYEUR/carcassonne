CC=gcc
EXE=exe

CFLAGS= -std=c99 -Wall -pedantic -g  -I$(INC_DIR)

INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./obj
TEST_DIR=./test

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

default : $(EXE)

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

test_gestion : $(SRC_DIR)/preparation.c $(OBJ_DIR)/preparation.o $(SRC_DIR)/affichage.c $(OBJ_DIR)/affichage.o $(SRC_DIR)/gestion.c $(OBJ_DIR)/gestion.o 
	$(CC) $(CFLAGS) $(TEST_DIR)/test_gestion.c $(SRC_DIR)/gestion.c $(SRC_DIR)/affichage.c $(SRC_DIR)/preparation.c -o test_gestion $(LDFLAGS)

test_preparation : $(SRC_DIR)/preparation.c $(OBJ_DIR)/preparation.o  $(SRC_DIR)/gestion.c $(OBJ_DIR)/gestion.o 
	$(CC) $(CFLAGS) $(TEST_DIR)/test_preparation.c $(SRC_DIR)/preparation.c $(SRC_DIR)/gestion.c -o test_preparation $(LDFLAGS)

test_affichage : $(SRC_DIR)/affichage.c $(OBJ_DIR)/affichage.o $(SRC_DIR)/preparation.c $(OBJ_DIR)/preparation.o $(SRC_DIR)/gestion.c $(OBJ_DIR)/gestion.o 
	$(CC) $(CFLAGS) $(TEST_DIR)/test_affichage.c $(SRC_DIR)/affichage.c $(SRC_DIR)/preparation.c $(SRC_DIR)/gestion.c -o test_affichage $(LDFLAGS)

%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ) $(EXE) *~ src/*.o test_*

.PHONY: all clean
