MAIN ?= main.c

NAME := minirt
COMPILE_FLAGS ?= -Wall -Wextra -Werror
SRC_DIR ?= src
HDR_DIR ?= include
OBJ_DIR ?= obj
LIBS = lib/libft/libft.a lib/MLX42/libmlx42.a
INCLUDE_DIRS := \
	-I "lib/libft/include/" \
	-I "lib/MLX42/include/"

LINKING_FLAGS ?= \
	-L "lib/libft" -lft \
	-L "lib/MLX42" -lmlx42 \
	-L "/Users/$(USER)/.brew/opt/glfw/lib/" -lglfw

# All source and header files are in the .mk files
SOURCES :=
include make/sources.mk
HEADERS :=
include make/headers.mk

# Can be used for changing the main easily (testing purposes)
SOURCES += main/$(MAIN)
OBJECTS := $(patsubst %,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

# Default debug option (0 = no debug)
DEBUG ?= 0

all: $(NAME)

files:
	./make/make_sources.sh

$(LIBS):
	@echo "libft:"
	@$(MAKE) -C lib/libft/
	@echo "libmlx42:"
	@$(MAKE) -C lib/MLX42/

$(NAME): $(HEADERS) $(OBJECTS) $(LIBS)
	@echo "\nLinking files..."
	@$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)
	@echo "Done!"

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@echo "Compiling: $@"
	@mkdir -p $(@D)
	@$(CC) -D ENABLE_DEBUG=$(DEBUG) \
		$(COMPILE_FLAGS) \
		$(INCLUDE_DIRS) \
		$(patsubst %,-I%,$(dir $(HEADERS))) \
		-c -o $@ $<

clean: clean_deps
	@echo "Cleaning minirt:"
	@rm -Rf $(OBJ_DIR)/
	@echo "Objects cleaned."

clean_deps:
	@echo "Cleaning libft:"
	@$(MAKE) -C lib/libft/ clean
	@echo "Cleaning libmlx42:"
	@$(MAKE) -C lib/MLX42/ clean

fclean: fclean_deps clean
	@rm -f $(NAME)
	@echo "Binary cleaned."

fclean_deps:
	@$(MAKE) -C lib/libft/ fclean
	@$(MAKE) -C lib/MLX42/ fclean

re: fclean all

print:
	@echo "---HEADERS: $(HEADERS)" | xargs -n1
	@echo "---SOURCES: $(SOURCES)" | xargs -n1
	@echo "---OBJECTS: $(OBJECTS)" | xargs -n1

run: all
	./$(NAME)

.PHONY: all files clean fclean clean_deps fclean_deps re print run