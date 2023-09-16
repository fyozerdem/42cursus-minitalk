SERVER_SRCS = server.c 
CLIENT_SRCS = client.c
SERVER_BONUS_SRCS = server_bonus.c 
CLIENT_BONUS_SRCS = client_bonus.c
FT_PRINTF = ft_printf/libftprintf.a
CFLAGS = -Werror -Wall -Wextra
NAME = server
NAME2 = client
NAMEBONUS = server_bonus
NAME2BONUS = client_bonus

all: ${NAME} ${NAME2}


${NAME}: $(SERVER_SRCS) $(FT_PRINTF) 
	gcc $(CFLAGS) $(SERVER_SRCS) $(FT_PRINTF) -o ${NAME}

${NAME2}: $(CLIENT_SRCS) $(FT_PRINTF) 
	gcc $(CFLAGS) $(CLIENT_SRCS) $(FT_PRINTF) -o ${NAME2}

$(FT_PRINTF):
	make -C ft_printf

bonus: ${NAMEBONUS} ${NAME2BONUS}

${NAMEBONUS}: $(SERVER_BONUS_SRCS) $(FT_PRINTF) 
	gcc $(CFLAGS) $(SERVER_BONUS_SRCS) $(FT_PRINTF) -o ${NAMEBONUS} 

${NAME2BONUS}: $(CLIENT_BONUS_SRCS) $(FT_PRINTF) 
	gcc $(CFLAGS) $(CLIENT_BONUS_SRCS) $(FT_PRINTF) -o ${NAME2BONUS}

clean:
	rm -fr server server_bonus client client_bonus
	make -C ft_printf clean

fclean: clean
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re bonus