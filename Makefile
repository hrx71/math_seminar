SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
TARGET = main
#Test
EXE := $(BIN_DIR)/main # executable in bin directory
SRC := $(wildcard $(SRC_DIR)/*.cpp) # list all source-files
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o) #list alle appr. obj to src files

CC := g++
#Preprocessor settings
#MP: adds a phony target for each dependency other than the main file, causing each to depend on nothing. This rule gives error if you remove the header files without updating the Makefile to match.
#MMD: -only user header files not system header files
CPPFLAGS := -Iinclude -MMD -MP
CFLAGS   := -Wall -g 
#Linker Flags
LDFLAGS  := -Llib
LDLIBS   := -lm
GMPFLAG  := -lgmp #GNU-GMP Multiprecision Library
#make whants to create a file named all, so therefore we create the phony target
.PHONY: all clean
	
all: $(EXE)

#Check if BINDIR exists else create it with mkdir
# $@: target
# $^ all pre-x 
# $< pre-1 like target: pre-1
$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@ $(GMPFLAG)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@	$(GMPFLAG)


$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

.PHONY: run 
run: $(BIN_DIR)/$(TARGET)
	$(BIN_DIR)/$(TARGET)

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)
