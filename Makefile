NAME	=	printf.a

CFLAGS	=	-Wall -Werror -Wextra -c

CC		=	gcc

SRCS	=	ft_numbers ft_printf.c main.c \
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
