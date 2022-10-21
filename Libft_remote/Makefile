# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhop <lhop@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 12:33:37 by lhop          #+#    #+#                  #
#    Updated: 2022/10/21 13:53:11 by lhop          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a


SRCS		= ft_toupper.c ft_tolower.c ft_isalpha.c \
				ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_strnstr.c \
				ft_strlcat.c ft_strlcpy.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c memchr.c \
				ft_memcmp.c ft_memset.c ft_memcpy.c \
				ft_memmove.c ft_atoi.c ft_bzero.c \

OBJS		?= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -I ../libft/libft.h

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	AR -rcs $(NAME) $(OBJS)
	$(info $(NAME) successfully created)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< 
	$(info successfully created $@)
#The % sign specifies 1 instance of a .o file. 
#The command %.o : %.c creates pairs of the same name.
#"with each .c file, a matching .o file will be made"
#-o means to not remake the file, or any changes because of it.
#"info" is a command to print text. Here it says a file was created.


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
# Must include rules $(NAME), all, clean, fclean, and re.
# compile with flags -Wall, -Wextra and -Werror
# makefile can't relink
# must use cc.