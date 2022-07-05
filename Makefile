MAIN ?= main.c

NAME := minirt
COMPILE_FLAGS ?= -Wall -Wextra -Werror
SRC_DIR ?= src
HDR_DIR ?= include
OBJ_DIR ?= obj
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
ENABLE_DEBUG ?= 0

.PHONY: all debug files dependencies
all: dependencies $(NAME)

debug:
	$(MAKE) ENABLE_DEBUG=1 re

files:
	./make/make_sources.sh

dependencies:
	@echo "libft:"
	@$(MAKE) -C lib/libft/
	@echo "libmlx42:"
	@$(MAKE) -C lib/MLX42/

$(NAME): $(HEADERS) $(OBJECTS)
	@echo "\nLinking files..."
	@$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)
	@echo "Done!"

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@echo "Compiling: $@"
	@mkdir -p $(@D)
	@$(CC) -D ENABLE_DEBUG=$(ENABLE_DEBUG) \
		$(COMPILE_FLAGS) \
		$(INCLUDE_DIRS) \
		$(patsubst %,-I%,$(dir $(HEADERS))) \
		-c -o $@ $<

.PHONY: clean fclean re print run
clean:
	@rm -Rf $(OBJ_DIR)/
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Binary cleaned."

re: fclean all

print:
	@echo "---HEADERS: $(HEADERS)" | xargs -n1
	@echo "---SOURCES: $(SOURCES)" | xargs -n1
	@echo "---OBJECTS: $(OBJECTS)" | xargs -n1

run: all
	./$(NAME)
