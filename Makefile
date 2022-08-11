# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 15:48:31 by ahocine           #+#    #+#              #
#    Updated: 2022/08/11 17:39:59 by ahocine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCDIR  =       srcs/
INCDIR  =       includes/

CFLAGS	=	-Wall -Wextra -c

CC		=	gcc

SRCS	=	$(addprefix $(SRCDIR), $(SRC))

SRC	=	ft_char_utils.c ft_display.c ft_display_2.c \
		ft_display_num.c ft_parse_flags.c ft_parse_flags_2.c \
		ft_printf.c ft_split_printf.c

INCLUDES =	$($(INCDIR), $(INC))

INC	=	ft_printf.h

OBJS	=	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS) $(INCLUDES)
		ar crs $@ $(OBJS)

%.o : %.c
		@$(CC) $(CFLAGS) $< -o $@

clean	:
		@rm -rf $(OBJS)

fclean: clean
		@rm -f $(NAME)

bonus :         $(NAME)

re:		fclean all
