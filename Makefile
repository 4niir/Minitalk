CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.c ft_atoi.c ft_printf_utils.c ft_printf.c ft_strchr.c ft_strlen.c ft_strdup.c minitalk.h
	$(CC) $(CFLAGS) server.c ft_atoi.c ft_printf_utils.c ft_printf.c ft_strchr.c ft_strlen.c ft_strdup.c -o server 

client: client.c ft_atoi.c ft_printf_utils.c ft_printf.c ft_strchr.c ft_strlen.c ft_strdup.c minitalk.h
	$(CC) $(CFLAGS) client.c ft_atoi.c ft_printf_utils.c ft_printf.c ft_strchr.c ft_strlen.c ft_strdup.c -o client 

bonus: libft ./bonus/client_bonus.c ./bonus/server_bonus.c ./bonus/minitalk_bonus.h
	$(CC) $(CFLAGS) ./bonus/server_bonus.c ./libft/libft.a -o ./bonus/server_bonus
	$(CC) $(CFLAGS) ./bonus/client_bonus.c ./libft/libft.a -o ./bonus/client_bonus


clean:
	make -C libft clean
	
fclean: clean
	rm -f server client 

re: fclean all

.PHONY: all bonus libft clean fclean re