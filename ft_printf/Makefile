NAME = libftprintf.a
SRCS= ft_printf.c ft_printf_func.c
OBJS= $(SRCS:.c=.o)
HEADER = ft_printf.h
CC=gcc
RM= rm -rf
CFLAGS= -Wall -Werror -Wextra
all: $(NAME)
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
clean:
	@$(RM) $(OBJS) 
fclean: clean
	@$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re 