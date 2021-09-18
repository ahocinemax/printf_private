NAME	=	printf.a

CFLAGS	=	-Wall -Werror -Wextra -c

CC		=	gcc

SRCS	=	main.c ft_numbers.c ft_printf.c \
			ft_split_printf.c utils.c \

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

re:		fclean all
