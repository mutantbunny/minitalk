CC = cc
CC_FLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR = ./lib/libft
BUILD_DIR = ./build
LIBFT_FILE = $(LIBFT_DIR)/libft.a

HEADER_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = $(BUILD_DIR)/obj
CLIENT_HEADER_FILES = $(addprefix $(HEADER_DIR)/, client.h minitalk.h)
CLIENT_SRC_FILES = $(addprefix $(SRC_DIR)/client/, client.c)
CLIENT_OBJ_FILES = $(subst $(SRC_DIR), $(OBJ_DIR), $(CLIENT_SRC_FILES:.c=.o))
SERVER_HEADER_FILES = $(addprefix $(HEADER_DIR)/, server.h minitalk.h)
SERVER_SRC_FILES = $(addprefix $(SRC_DIR)/server/, server.c)
SERVER_OBJ_FILES = $(subst $(SRC_DIR), $(OBJ_DIR), $(SERVER_SRC_FILES:.c=.o))

HEADER_BONUS_DIR = ./include/bonus
SRC_BONUS_DIR = ./src/bonus
OBJ_BONUS_DIR = $(BUILD_DIR)/obj/bonus
CLIENT_HEADER_BONUS_FILES = $(addprefix $(HEADER_BONUS_DIR)/, client.h minitalk.h)
CLIENT_SRC_BONUS_FILES = $(addprefix $(SRC_BONUS_DIR)/client/, client.c)
CLIENT_OBJ_BONUS_FILES = $(subst $(SRC_BONUS_DIR), $(OBJ_BONUS_DIR), $(CLIENT_SRC_BONUS_FILES:.c=.o))
SERVER_HEADER_BONUS_FILES = $(addprefix $(SERVER_HEADER_DIR)/, server.h minitalk.h)
SERVER_SRC_BONUS_FILES = $(addprefix $(SRC_BONUS_DIR)/server, server.c)
SERVER_OBJ_BONUS_FILES = $(subst $(SRC_BONUS_DIR), $(OBJ_BONUS_DIR), $(SERVER_SRC_BONUS_FILES:.c=.o))


INCLUDE_FLAGS = -I$(HEADER_DIR) -I$(LIBFT_DIR)
INCLUDE_BONUS_FLAGS = -I$(HEADER_BONUS_DIR) -I$(LIBFT_DIR)
LIB_FLAGS = -L$(LIBFT_DIR) -lft
LIB_BONUS_FLAGS = $(LIB_FLAGS)

CLIENT_NAME = $(BUILD_DIR)/client
SERVER_NAME = $(BUILD_DIR)/server

all: client server

client: $(CLIENT_NAME)

server: $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT_FILE) $(CLIENT_OBJ_FILES) $(CLIENT_HEADER_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(CLIENT_OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(SERVER_NAME): $(LIBFT_FILE) $(SERVER_OBJ_FILES) $(SERVER_HEADER_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(SERVER_OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(LIBFT_FILE):
	make -C $(LIBFT_DIR)

bonus: client_bonus server_bonus

client_bonus: $(CLIENT_BONUS_NAME)

server_bonus: $(SERVER_BONUS_NAME)

$(CLIENT_BONUS_NAME): $(LIBFT_FILE) $(CLIENT_OBJ_BONUS_FILES) $(CLIENT_HEADER_BONUS_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(CLIENT_OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(SERVER_BONUS_NAME): $(LIBFT_FILE) $(SERVER_OBJ_FILES) $(SERVER_HEADER_FILES)
	mkdir -p $(BUILD_DIR)
	$(CC) $(CC_FLAGS) $(SERVER_OBJ_FILES) $(INCLUDE_FLAGS) $(LIB_FLAGS) -o $@

$(OBJ_BONUS_DIR)/client/%.o: $(CLIENT_SRC_BONUS_DIR)/%.c $(CLIENT_HEADER_BONUS_FILES)
	mkdir -p $(OBJ_BONUS_DIR)/client
	$(CC) $(CC_FLAGS) $< $(INCLUDE_BONUS_FLAGS) -c -o $@

$(OBJ_BONUS_DIR)/server/%.o: $(SERVER_SRC_BONUS_DIR)/%.c $(SERVER_HEADER_BONUS_FILES)
	mkdir -p $(OBJ_BONUS_DIR)/server
	$(CC) $(CC_FLAGS) $< $(INCLUDE_BONUS_FLAGS) -c -o $@

$(OBJ_DIR)/client/%.o: $(CLIENT_SRC_DIR)/%.c $(CLIENT_HEADER_FILES)
	mkdir -p $(OBJ_DIR)/client
	$(CC) $(CC_FLAGS) $< $(INCLUDE_FLAGS) -c -o $@

$(OBJ_DIR)/server/%.o: $(SERVER_SRC_DIR)/%.c $(SERVER_HEADER_FILES)
	mkdir -p $(OBJ_DIR)/server
	$(CC) $(CC_FLAGS) $< $(INCLUDE_FLAGS) -c -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	make -C $(LIBFT_DIR) fclean
	$(RM) $(BUILD_DIR)

norm:
	norminette

re:	fclean all

.PHONY: all bonus clean client client_bonus fclean norm re server server_bonus
