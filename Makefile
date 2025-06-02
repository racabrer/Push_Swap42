# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: racabrer <racabrer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 18:04:15 by racabrer          #+#    #+#              #
#    Updated: 2025/06/02 19:28:33 by racabrer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME = push_swap

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Librería libft
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Carpeta para archivos objeto
OBJ_DIR = objs

# Archivos fuente (en el directorio actual)
SRC = errors.c indexes.c listas.c little_numbers.c main.c push.c reverse_rotate.c \
		rotate.c stack_init.c stack_utils.c swap.c k_sort.c

 # Archivos objeto (redirigidos a la carpeta objs/)
OBJ = $(SRC:.c=.o)
OBJ := $(addprefix $(OBJ_DIR)/, $(OBJ))

# Compilación principal
all: $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_DIR) -lft

# Compilar libft si existe
$(LIBFT_LIB):
	@if [ -d "$(LIBFT_DIR)" ]; then make -C $(LIBFT_DIR); fi

# Crear la carpeta objs y compilar los .c en ella
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -rf $(OBJ_DIR)
	@if [ -d "$(LIBFT_DIR)" ]; then make -C $(LIBFT_DIR) clean; fi

# Limpiar binario y objetos
fclean: clean
	rm -f $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then make -C $(LIBFT_DIR) fclean; fi

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re
