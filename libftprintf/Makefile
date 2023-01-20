# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhop <lhop@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 12:33:37 by lhop          #+#    #+#                  #
#    Updated: 2023/01/10 13:58:49 by lhop          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a


SRCS		= ft_toupper.c ft_tolower.c ft_isalpha.c \
				ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_strnstr.c \
				ft_strlcat.c ft_strlcpy.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_memset.c ft_memcpy.c \
				ft_memmove.c ft_atoi.c ft_bzero.c \
				ft_calloc.c ft_strdup.c ft_putendl_fd.c \
				ft_substr.c ft_strjoin.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_itoa.c ft_putnbr_fd.c \
				ft_striteri.c ft_strmapi.c ft_strtrim.c \
				ft_split.c ft_printf.c ft_write_char.c \
				ft_write_hex.c ft_write_int.c ft_write_pointer.c \
				ft_write_string.c \

OBJS		?= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I ../printf/printf.h

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	AR -rcs $(NAME) $(OBJS)
	$(info --------.)
	$(info -------,O,)
	$(info ------,OOO,)
	$(info 'oooooOOOOOooooo')
	$(info --`OOOOOOOOOOO`)
	$(info ----`OOOOOOO`)
	$(info ----OOOO'OOOO)
	$(info ---OOO'   'OOO)
	$(info --O'         'O)
	$(info Successfully created $(NAME))

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< 
	$(info Successfully compiled $<)

clean:
	$(RM) $(OBJS)
	$(info Successfully removed object files.)

fclean: clean
	$(RM) $(NAME)
	$(info Successfully uninstalled $(NAME).)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re all
.SILENT:

#GENERAL:	A makefiles creates things retroactively. They will attempt 
#			to make the highest target, to then figure out the components
#			needed to create that target. It will then look at what is 
#			needed to create the components of those components, etc.
#			
#			COMPONENTS:
#			|Targets: these are files or actions. Target is a file to be
#			 created, pseudo-target is an action to be executed.
#			|Prerequisites: pre-requisites to the targets being executed.
#			 AKA: the target's dependencies.
#			|Recipe: the set of tabbed lines that hold actions. 
#			
#13: Name of the function library to be created.
#15: List of source files. 
#28: List of object files. I create this list by using ?=, 
#	 which means 'if no previous definition found, then define as:'
#	 and then I define to the value of 'SRCS', except that every .c
#	 turns into .o
#29: I define my utensils. CC, code compiler, CFLAGS, compilation
#    flags like '-Werror', and CPPFLAGS, code pre processor flags. 
#	 The -I creates the possibility of not having to type the entire
#	 address of the include header. I can now just #include "libft.h".
#	 RM creates the command to force remove. 'rm -f'.
#36: 'all' is the default goal, triggered by 'make' command. 
#38: Then, there is the target 'name', with the dependency 'objs'.
#39: I then create the line AR -rcs, followed by libft.a, followed by
#	 all .o files, which will have created the .a file. 
#	 -r replaces the library with new files if it already existed. 
#	 -c creates the library if it did not exist. 
#	 -s creates a sorted index of the library for faster access.
#40: "info" prints text. Here it says the library was created.
#42: This command initiates a pattern rule. The % sign specifies 
# 	 1 instance of 2 matching files, so, the command %.o : %.c executes 
#	 the recipe once for every .c file that matches a .o file.
#43: "gcc -Wall -Werror -Wextra -I -c -o <OBJ>.o <SRC>.c" 
#44: "Successfully created <SRC.c>"
#44: -o specifies the object name.
#44: -c makes the compiler compile only, without linking.