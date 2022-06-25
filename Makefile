SERVER = server
CLIENT = client

GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m

UTILS_SRC = ./utils/*.c


CC= gcc
FLAGS = -Wall -Wextra -Werror -g3
MAKE_NOPRINT = $(MAKE) --no-print-directory
INCLUDES = -I ./includes/ -I ./libs/ft_printf/

SERVER_SRC = server.c
CLIENT_SRC = client.c

FT_PRINTF_PATH = libs/ft_printf/
FT_PRINTF = libs/ft_printf/libftprintf.a

all:$(SERVER) $(CLIENT)

$(SERVER):${FT_PRINTF}
	@$(CC) $(INCLUDES) $(SERVER_SRC) $(UTILS_SRC) $(FT_PRINTF) -o $(SERVER)
	@echo "$(GREEN)server compiled 🖧 $(RESET)"

$(CLIENT):
	@$(CC) $(INCLUDES) $(CLIENT_SRC) $(UTILS_SRC) $(FT_PRINTF) -o $(CLIENT)
	@echo "$(GREEN)cliente compiled 🌐 $(RESET)"

$(FT_PRINTF):
	@$(MAKE_NOPRINT) -C $(FT_PRINTF_PATH)

clean:
	@$(MAKE_NOPRINT) clean -C $(FT_PRINTF_PATH)
	@echo "$(RED)compilation files deleted $(RESET)"

fclean:
	@$(MAKE_NOPRINT) fclean -C ${FT_PRINTF_PATH}
	@rm -fr $(SERVER) $(CLIENT)
	@echo "$(RED) [SERVER] and [CLIENT] was deleted $(RESET)"

re: fclean all

.PHONY: all clean fclean re
