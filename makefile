SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin


EXE := $(BIN_DIR)/main.exe
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -I$(INC_DIR) -Wall

#-------------------------------------------#

all: $(EXE)

$(EXE): $(OBJ)
        gcc $^ -o $@
        @echo The executable main exe is created.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
        gcc -c $< -o $@ $(CFLAGS)

clean:
	$(RM) -rf $(BIN_DIR)/* $(OBJ_DIR)/*
	@echo All object and executable files are cleaned.
