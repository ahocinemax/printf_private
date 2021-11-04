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

SRCS	=	ft_char_utils.c ft_display.c ft_display_2.c \
			ft_display_num.c ft_parse_flags.c ft_parse_flags_2.c \
			ft_printf.c ft_split_printf.c \

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
