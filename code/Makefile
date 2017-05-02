LIB       = -lSDL -lSDLmain -lSDL_image -lSDL_ttf -lm
CFLAGS    = -W -Wall -ansi

SRC_PATH  = src
SRC_FILES = $(shell find $(SRC_PATH) -type f -name '*.c')

OBJ_PATH  = obj
OBJ_FILES = $(patsubst $(SRC_PATH)/%.c,$(OBJ_PATH)/%.o, $(SRC_FILES))

GAME 	  = arkanopong

$(GAME): $(OBJ_FILES)
	@gcc -o $(GAME) $(OBJ_FILES) $(LIB)
	@echo "> Compilation effectuée"
	@echo "> ./$(GAME)"

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@mkdir -p "$(@D)"
	@gcc -o $@ -c $< $(INCLUDE_PATH) $(CFLAGS)

clean:
	@rm obj/*.o $(GAME)
	@echo "> Objets et exécutable nettoyés"
	@make --no-print-directory