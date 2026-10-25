# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbohdanc <zbohdanc@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/06 16:38:37 by zbohdanc          #+#    #+#              #
#    Updated: 2026/06/04 17:42:29 by zbohdanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

CC =		cc
CFLAGS = 	-Wall -Wextra -Werror

AR =		ar
ARFLAGS =   -rcs

SRC_DIR =	.
INC_DIR =	.

SRC = 		$(SRC_DIR)/ft_isalpha.c \
			$(SRC_DIR)/ft_isdigit.c \
			$(SRC_DIR)/ft_isalnum.c \
			$(SRC_DIR)/ft_isascii.c \
			$(SRC_DIR)/ft_isprint.c \
			$(SRC_DIR)/ft_strlen.c \
			$(SRC_DIR)/ft_memset.c \
			$(SRC_DIR)/ft_bzero.c \
			$(SRC_DIR)/ft_memcpy.c \
			$(SRC_DIR)/ft_memmove.c \
			$(SRC_DIR)/ft_strlcpy.c \
			$(SRC_DIR)/ft_strlcat.c \
			$(SRC_DIR)/ft_toupper.c \
			$(SRC_DIR)/ft_tolower.c \
			$(SRC_DIR)/ft_strchr.c \
			$(SRC_DIR)/ft_strrchr.c \
			$(SRC_DIR)/ft_strncmp.c \
			$(SRC_DIR)/ft_memchr.c \
			$(SRC_DIR)/ft_memcmp.c \
			$(SRC_DIR)/ft_strnstr.c \
			$(SRC_DIR)/ft_atoi.c \
			$(SRC_DIR)/ft_calloc.c \
			$(SRC_DIR)/ft_strdup.c \
			$(SRC_DIR)/ft_substr.c \
			$(SRC_DIR)/ft_strjoin.c \
			$(SRC_DIR)/ft_strtrim.c \
			$(SRC_DIR)/ft_split.c \
			$(SRC_DIR)/ft_itoa.c \
			$(SRC_DIR)/ft_strmapi.c \
			$(SRC_DIR)/ft_striteri.c \
			$(SRC_DIR)/ft_putchar_fd.c \
			$(SRC_DIR)/ft_putstr_fd.c \
			$(SRC_DIR)/ft_putendl_fd.c \
			$(SRC_DIR)/ft_putnbr_fd.c \
			$(SRC_DIR)/ft_lstnew.c \
			$(SRC_DIR)/ft_lstadd_front.c \
			$(SRC_DIR)/ft_lstsize.c \
			$(SRC_DIR)/ft_lstlast.c \
			$(SRC_DIR)/ft_lstadd_back.c \
			$(SRC_DIR)/ft_lstdelone.c \
			$(SRC_DIR)/ft_lstclear.c \
			$(SRC_DIR)/ft_lstiter.c \
			$(SRC_DIR)/ft_lstmap.c
OBJ =		$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		   $(AR) $(ARFLAGS) $(NAME) $(OBJ)
.c.o:
	 $(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
clean:
	  rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
