# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: racabrer <racabrer@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 21:16:50 by racabrer          #+#    #+#              #
#    Updated: 2024/10/16 20:18:40 by racabrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
SRC =           ft_isdigit.c\
                ft_isalnum.c\
                ft_isalpha.c\
                ft_isascii.c\
                ft_isprint.c\
                ft_strlen.c\
                ft_memset.c\
                ft_bzero.c\
                ft_memcpy.c\
                ft_memmove.c\
                ft_strlcpy.c\
                ft_strlcat.c\
                ft_toupper.c\
                ft_tolower.c\
                ft_strchr.c\
                ft_strncmp.c\
                ft_memchr.c\
                ft_memcmp.c\
                ft_strnstr.c\
                ft_atoi.c\
                ft_calloc.c\
                ft_strdup.c\
                ft_substr.c\
                ft_strjoin.c\
                ft_strtrim.c\
                ft_putchar_fd.c\
                ft_putstr_fd.c\
                ft_putendl_fd.c\
                ft_putnbr_fd.c\
                ft_itoa.c\
                ft_strrchr.c\
                ft_strmapi.c\
                ft_striteri.c\
                ft_split.c
                
BONUSSRC =      ft_lstadd_back_bonus.c\
                ft_lstadd_front_bonus.c\
                ft_lstclear_bonus.c\
                ft_lstdelone_bonus.c\
                ft_lstiter_bonus.c\
                ft_lstlast_bonus.c\
                ft_lstnew_bonus.c\
                ft_lstsize_bonus.c\
                ft_lstmap_bonus.c
                
OBJECTS = $(SRC:.c=.o)
BONUSOBJECTS = $(BONUSSRC:.c=.o)
INCLUDE = libft.h

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJECTS)

bonus: all .bonus
.bonus: $(BONUSOBJECTS) $(INCLUDE)
	$(LIB) $(NAME) $(BONUSOBJECTS)
	@touch .bonus 

clean:
	rm -f $(OBJECTS) $(BONUSOBJECTS)

fclean: clean
	rm -f $(NAME) .bonus

re: fclean all

.PHONY: all clean fclean re bonus
