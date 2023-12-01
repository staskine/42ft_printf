# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sataskin <sataskin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 13:14:15 by sataskin          #+#    #+#              #
#    Updated: 2023/11/29 13:28:29 by sataskin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = ft_printf.c ft_print_char.c ft_print_val.c

OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

	
$(NAME): $(OBJECT)
	make -C libft
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJECT)

%.o:%.c
	cc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

clean:
	make clean -C ./libft
	rm -f $(OBJECT)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

.PHONY: clean fclean all re