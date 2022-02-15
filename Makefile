# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ngerrets <ngerrets@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/07/15 14:47:03 by ngerrets      #+#    #+#                  #
#    Updated: 2022/02/15 19:47:57 by ngerrets      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# For now this is the default Makefile I use for C projects
# Manually edit:
NAME := minirt
COMPILE_FLAGS ?= -Wall -Wextra
LINKING_FLAGS ?= 
LIBRARIES ?=
SOURCE_DIRECTORY ?= src
HEADER_DIRECTORY ?= include
OBJECTS_DIRECTORY ?= objects
BINARIES_DIRECTORY ?= .

MAKE_BONUS = 0

# Don't manually edit:
SOURCES :=
include sources.mk
HEADERS :=
include headers.mk

INCLUDES := $(patsubst %,-I%,$(dir $(HEADERS)))
OBJECTS := $(patsubst %,$(OBJECTS_DIRECTORY)/%,$(SOURCES:.c=.o))
NAME := $(BINARIES_DIRECTORY)/$(NAME)

# Default make-rule. Compile and link files.
all: $(NAME)

# dependencies:
#	@$(MAKE) -C lib/get_next_line

# Link files
# @echo "\nBuilding dependencies..."
# @$(MAKE) dependencies
$(NAME): $(BINARIES_DIRECTORY) $(HEADERS) $(OBJECTS)
	@echo "\nLinking files..."
	@$(CC) $(OBJECTS) -o $(NAME) $(LINKING_FLAGS)
	@echo "Done!"

# Create binaries directory
$(BINARIES_DIRECTORY):
	@mkdir -p $(BINARIES_DIRECTORY)

# Compile files
$(OBJECTS_DIRECTORY)/%.o: %.c $(HEADERS)
	@echo "Compiling: $@"
	@mkdir -p $(@D)
	@$(CC) -DBONUS=$(MAKE_BONUS) $(COMPILE_FLAGS) $(INCLUDES) -c -o $@ $<

# Clean objects
clean:
	@rm -Rf $(OBJECTS_DIRECTORY)
	@echo "Objects cleaned."

# cleandeps:
# 	@$(MAKE) -C lib/get_next_line clean
# 	@echo "Dependencies cleaned."

# Clean objects and binaries
fclean: clean
	@rm -f $(BINARIES_DIRECTORY)/$(NAME)
	@echo "Binaries cleaned."

# Clean, recompile and relink project
re: fclean all

# Compile, link and run project
run: all
	@echo "Running..."
	@./$(NAME)

# Prints header and source files
print:
	@echo "---HEADERS: $(HEADERS)" | xargs -n1
	@echo "---SOURCES: $(SOURCES)" | xargs -n1
	@echo "---OBJECTS: $(OBJECTS)" | xargs -n1

# In case of bonus
bonus: MAKE_BONUS = 1
bonus: re

.PHONY: all clean fclean re run print cleandeps dependencies bonus