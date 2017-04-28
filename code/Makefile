LIB       = -lSDL -lSDLmain -lSDL_image
CFLAGS    = -W -Wall -ansi

SRC_PATH  = src
SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.c')

OBJ_PATH  = obj
OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))

GAME 	  = arkanopong

$(GAME): $(OBJ_FILES)
	gcc -o $(GAME) $(OBJ_FILES) $(LIB)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@mkdir -p "$(@D)"
	@gcc -o $@ -c $< $(INCLUDE_PATH) $(CFLAGS)
