SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

UTILS_SRC = ./utils/*.c

CC= gcc
FLAGS = -Wall -Wextra -Werror -g3

INCLUDES = -I ./includes/

GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m

all:$(SERVER) $(CLIENT)

$(SERVER):
	@$(CC) $(INCLUDES) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)
	@echo "$(GREEN)server compiled 🖧 $(RESET)"

$(CLIENT):
	@$(CC) $(INCLUDES) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)
	@echo "$(GREEN)cliente compiled 🌐 $(RESET)"

clean:

fclean:
	@rm -fr $(SERVER) $(CLIENT)
	@echo "$(RED) [SERVER] and [CLIENT] was deleted $(RESET)"

re: fclean all

.PHONY: all clean fclean re
