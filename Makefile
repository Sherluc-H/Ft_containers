# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 14:56:25 by lhuang            #+#    #+#              #
#    Updated: 2020/10/06 22:04:50 by lhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_containers
CC= clang++
CFLAGS= -Wall -Wextra -Werror
RM= rm -f
SRCS=	main.cpp
HEADERS=	list.hpp vector.hpp map.hpp stack.hpp queue.hpp reverse_iterator.hpp\
			ft_check_utils.hpp\
			ft_check_list.hpp\
			ft_check_vector.hpp\
			ft_check_map.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
