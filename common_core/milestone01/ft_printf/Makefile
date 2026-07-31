#   VARIABLES
NAME = libftprintf.a

CC = cc

#   add "-g" flag to use gdb
CFLAGS = -Wall -Wextra -Werror -I includes

#   $(wildcard src/ft_*.c)
#   find . -name "*.c" | sed "s/\.\///" | sed "s/\.c/\.c \\\/"
SRCS = src/ft_print_char.c \
	src/ft_print_conversion.c \
	src/ft_printf.c \
	src/ft_print_memory.c \
	src/ft_print_str.c \
	src/ft_putnbr_base.c \
	src/ft_uputnbr_base.c \

#   Directory where object files will be stored
OBJ_DIR= obj

#   Transforms "src/ft_ft.c" -> "obj/ft_ft.o"
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

AR = ar rcs
RM = rm -f
RMD = rmdir

#   RULES
#   "My goal is to construct the NAME variable"
#   C looks in the folder: "does $(NAME) exist and is it up-to-date?". If it's
#   not, it goes down to look for a rule that teaches how to create $(NAME)
all: $(NAME)

#   rule that creates $(NAME)
#   "to create $(NAME), i first need all the OBJS
#   (files with the .o extension) to exist"

# 	1. Copies $(LIBFT) and renames it to $(NAME)
# 	2. Injects $(OBJS)'s .o files into the copied library
$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS) $(LIBFT)

#   Enters the $(LIBFT_DIR) folder and runs its Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

#   PATTERN RULE
#   it tells the Makefile how to transform
#   any .c file into a .o file
#
#   "obj/%.o" depends on "src/%.c"
#   The "| $(OBJ_DIR)" is an order-only prerequisite:
#   it ensures the directory exists WITHOUT triggering
#   recompilation whenever the directory's timestamp changes.
#
#   -c  =  compile only until the object is generated
#   $<  =  first requirement  =  .c
#   $@  =  target name  =  .o
$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#   Rule that creates the obj/ directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#   1. Delete all .o files
#   2. make enters $(LIBFT_DIR) folder "$(MAKE) -C ..." and executes the "clean"
#   rule of the Makefile for that folder
clean:
	$(RM) $(OBJS) $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) clean

#   after deleting the .o files, it also deletes
#   the final file
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

#   rebuild everything from scratch
re: fclean all



#   it tells the Makefile that these words
#   (all, clean, etc.) are not filenames,
#   they are rule names
.PHONY: all clean fclean re
