MAIN ?= main.c

NAME := minirt
COMPILE_FLAGS ?= -Wall -Wextra -Werror
SRC_DIR ?= src
HDR_DIR ?= include
OBJ_DIR ?= obj
LIBS = lib/MLX42/libmlx42.a lib/libft/libft.a
INCLUDE_DIRS := \
	-I "lib/libft/include/" \
	-I "lib/MLX42/include/"

LINKING_FLAGS ?= \
	-L "lib/libft" -lft \
	-L "lib/MLX42" -lmlx42 \
	-lglfw \
	-lm

# All source and header files are in the .mk files
SOURCES :=
include make/sources.mk
HEADERS :=
include make/headers.mk

OBJECTS := $(patsubst %,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

# Default debug option (0 = no debug)
DEBUG ?= 0

ifeq ($(DEBUG),1)
	COMPILE_FLAGS += -g -fsanitize=address
	LINKING_FLAGS += -g -fsanitize=address
endif

all: $(NAME)

files:
	./make/make_sources.sh

$(LIBS):
	$(MAKE) -C lib/libft/
	$(MAKE) -C lib/MLX42/

$(NAME): $(LIBS) $(HEADERS) $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) -D ENABLE_DEBUG=$(DEBUG) $(COMPILE_FLAGS) $(INCLUDE_DIRS) $(patsubst %,-I%,$(dir $(HEADERS))) -c -o $@ $<

clean: clean_deps
	rm -Rf $(OBJ_DIR)/

clean_deps:
	$(MAKE) -C lib/libft/ clean
	$(MAKE) -C lib/MLX42/ clean

fclean: fclean_deps clean
	rm -f $(NAME)

fclean_deps:
	$(MAKE) -C lib/libft/ fclean
	$(MAKE) -C lib/MLX42/ fclean

re: fclean all

print:
	@echo "---HEADERS: $(HEADERS)" | xargs -n1
	@echo "---SOURCES: $(SOURCES)" | xargs -n1
	@echo "---OBJECTS: $(OBJECTS)" | xargs -n1

run: all
	./$(NAME)

.PHONY: all files clean fclean clean_deps fclean_deps re print run
