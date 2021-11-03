# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 15:48:31 by ahocine           #+#    #+#              #
#    Updated: 2021/09/27 19:06:09 by ahocine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Werror -Wextra -c

CC		=	gcc

SRCS	=	ft_parse_flags.c ft_numbers.c ft_printf.c \
			ft_split_printf.c ft_strings.c \
			parse_num_flags.c parse_char_flags.c \

INCLUDES	=	ft_printf.h \

OBJS	=	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS) $(INCLUDES)
		@ar crs $@ $(OBJS)

%.o : %.c
		@$(CC) $(CFLAGS) $< -o $@

clean	:
		@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

bonus :         $(NAME)

re:		fclean all
