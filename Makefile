# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huahmad <huahmad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 12:20:00 by huahmad           #+#    #+#              #
#    Updated: 2025/02/10 14:56:58 by huahmad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a
CFLAGS = -Wextra -Wall -Werror  
OBJS = ${SRCS:.c=.o}
SRCS = \
		pushswap.c \
		srcs/analysis.c \
		srcs/errors.c \
		srcs/finding.c \
		srcs/init.c \
		srcs/pushing.c \
		srcs/rotating.c \
		srcs/rotating2.c \
		srcs/rotating3.c \
		srcs/swaps.c \

all: $(LIBFT) $(NAME)
$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

$(LIBFT):
	$(MAKE) -s -C libft
	

clean:
	rm -f *.o
	rm -f $(NAME)
	rm -f *.txt
	rm -f *:Zone.Identifier

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: clean all