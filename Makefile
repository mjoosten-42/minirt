# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ngerrets <ngerrets@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/15 14:47:03 by ngerrets      #+#    #+#                  #
#    Updated: 2022/02/17 11:12:09 by ngerrets      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

MAIN := main/test.c

NAME := minirt
COMPILE_FLAGS ?= -Wall -Wextra
LINKING_FLAGS ?= 

SRC_DIR ?= src
HDR_DIR ?= include
OBJ_DIR ?= objects

SOURCES :=
include make/sources.mk
HEADERS :=
include make/headers.mk

SOURCES += $(MAIN)
OBJECTS := $(patsubst %,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

.PHONY: all files
all: $(NAME)

files:
	./make/make_sources.sh
	$(MAKE) all

$(NAME): $(HEADERS) $(OBJECTS)
	@echo "\nLinking files..."
	@$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)
	@echo "Done!"

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@echo "Compiling: $@"
	@mkdir -p $(@D)
	@$(CC)  $(COMPILE_FLAGS) $(patsubst %,-I%,$(dir $(HEADERS))) -c -o $@ $<

.PHONY: clean fclean re
clean:
	@rm -Rf $(OBJ_DIR)
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
