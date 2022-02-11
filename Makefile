
RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

CFLAGS = -Wall -Werror -Wextra

CLIENT = client
SERVER = server
CLIENT_B = client_bonus
SERVER_B = server_bonus

BONUS_HEADER = minitalk_bonus.h
HEADER = minitalk.h

COMMON_FILES = ft_atoi.c ft_printf_utils.c ft_printf.c ft_strchr.c
BONUS_COMMON_FILES = ft_atoi_bonus.c ft_printf_bonus.c ft_printf_utils_bonus.c ft_strchr_bonus.c
SRC_CLIENT = $(COMMON_FILES) client.c
SRC_SERVER = $(COMMON_FILES) server.c
SRC_B_CLIENT = $(BONUS_COMMON_FILES) client_bonus.c
SRC_B_SERVER = $(BONUS_COMMON_FILES) server_bonus.c
COBJ = $(SRC_CLIENT:%.c=%.o)
SOBJ = $(SRC_SERVER:%.c=%.o)
COBJ_B = $(SRC_B_CLIENT:%.c=%.o)
SOBJ_B = $(SRC_B_SERVER:%.c=%.o)

OBJS = $(COBJ) $(SOBJ) $(COBJ_B) $(SOBJ_B)

NAME = minitalk

all : $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SOBJ)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SRC_SERVER) 
	@echo "$(GREEN)" "compiling server"

$(CLIENT) : $(COBJ)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT)
	@echo "$(GREEN)" "compiling client"

bonus : $(SERVER_B) $(CLIENT_B)

$(SERVER_B): $(SOBJ_B)
	@$(CC) $(CFLAGS) -o $(SERVER_B) $(SRC_B_SERVER) 
	@echo "$(GREEN)" "compiling server_bonus"

$(CLIENT_B) : $(COBJ_B)
	@$(CC) $(CFLAGS) -o $(CLIENT_B) $(SRC_B_CLIENT)
	@echo "$(GREEN)" "compiling client_bonus"

%.o : %.c $(HEADER) $(BONUS_HEADER)
	@$(CC) $(CFLAGS) $^ -c
	@echo "$(GREEN)" "compiling $<"

clean:
	@rm -rf $(OBJS) *.gch
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus