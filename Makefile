# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 14:47:03 by ngerrets          #+#    #+#              #
#    Updated: 2022/06/06 11:31:30 by mjoosten         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN ?= main.c

NAME := minirt
INCLUDE_DIRS := -I "lib/libft/include/" -I "lib/MLX42/include/"
COMPILE_FLAGS ?= -Wall -Wextra -g
LINKING_FLAGS ?= libft.a libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"

SRC_DIR ?= src
HDR_DIR ?= include
OBJ_DIR ?= obj

SOURCES :=
include make/sources.mk
HEADERS :=
include make/headers.mk

SOURCES += main/$(MAIN)
OBJECTS := $(patsubst %,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

.PHONY: all files
all: $(NAME)

files:
	./make/make_sources.sh

$(NAME): $(HEADERS) $(OBJECTS)
	@echo "\nLinking files..."
	@$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)
	@echo "Done!"

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@echo "Compiling: $@"
	@mkdir -p $(@D)
	@$(CC)  $(COMPILE_FLAGS) $(INCLUDE_DIRS) $(patsubst %,-I%,$(dir $(HEADERS))) -c -o $@ $<

.PHONY: clean fclean re
clean:
	@rm -Rf $(OBJ_DIR)/
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Binary cleaned."

re: fclean all

.PHONY: print
print:
	@echo "---HEADERS: $(HEADERS)" | xargs -n1
	@echo "---SOURCES: $(SOURCES)" | xargs -n1
	@echo "---OBJECTS: $(OBJECTS)" | xargs -n1

.PHONY: run
run: all
	./$(NAME)
