# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmathe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 17:15:46 by dmathe            #+#    #+#              #
#    Updated: 2015/11/24 17:15:47 by dmathe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRCS = srcs/main.c srcs/check_map.c srcs/utils.c

OBJS =		$(SRCS:.c=.o)

INCLUDES =	-I libft \
			-I incs

LIBS =		-L libft/ -lft \

FLAGS =		-g -Wall -Wextra -Werror


$(NAME):	$(OBJS)
	@make -C libft/ fclean
	@make -C libft/
	@echo "Create binary"
	@gcc -o $(NAME) $(OBJS) $(LIBS)
	@echo "Complitation ok"

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	rm -f	$(OBJS)

fclean: clean
	rm -f	$(NAME)

re: fclean all

.PHONY:	 all clean fclean re
