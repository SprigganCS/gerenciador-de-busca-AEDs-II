DIR_SRC := src
DIR_OBJ := obj
DIR_BIN := bin
DIR_INC := incl

EXE := $(DIR_BIN)/output
SRC := $(wildcard $(DIR_SRC)/*.cc)
OBJ := $(SRC:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

CC := g++
CFLAGS   := -Wall

.PHONY: all run clean

all: $(EXE)

run: $(EXE)
	$(EXE)

$(EXE): $(OBJ) | $(DIR_BIN)
	$(CC) $^ -I$(DIR_INC) -o $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cc | $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_BIN) $(DIR_OBJ):
	mkdir -p $@

clean:
	@$(RM) -rv $(DIR_BIN) $(DIR_OBJ)
