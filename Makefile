
RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

CFLAGS = -Wall -Werror -Wextra

CLIENT = client
SERVER = server

COMMON_FILES = ft_atoi.c ft_printf_utils.c ft_printf.c ft_strchr.c
SRC_CLIENT = $(COMMON_FILES) client.c
SRC_SERVER = $(COMMON_FILES) server.c
COBJ = $(SRC_CLIENT:%.c=%.o)
SOBJ = $(SRC_SERVER:%.c=%.o)
OBJS = $(COBJ) $(SOBJ)

all : $(SERVER) $(CLIENT)

$(SERVER): $(SOBJ)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SRC_SERVER) 
	@echo "$(GREEN)" "compiling server"

$(CLIENT) : $(COBJ)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(SRC_CLIENT)
	@echo "$(GREEN)" "compiling client"

%.o : %.c minitalk.h
	@$(CC) $(CFLAGS) $^ -c
	@echo "$(GREEN)" "compiling $<"

clean:
	@rm -rf $(OBJS) *.gch
	@echo "$(RED)" "cleaning..."

fclean : clean
	@rm -rf $(SERVER) $(CLIENT)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"