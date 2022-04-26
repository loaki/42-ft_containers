.PHONY: all clean fclean re

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = containers

INC_PATH = ./inc
SRC_PATH = ./src
OBJ_PATH = ./obj
OBJ_PATH_D = ./obj_d

INC_NAME =

SRC_NAME = main.cpp\

OBJ_NAME = $(SRC_NAME:.cpp=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJ_D = $(addprefix $(OBJ_PATH_D)/, $(OBJ_NAME))

all: ft std
	@./"ft_"$(NAME)
	@./"std_"$(NAME)
	@echo "\e[1;34m### diff ### \e[0m"
	@echo "\e[1;31m"
	@diff ft_out std_out || exit 0
	@echo "\e[0m"

ft: $(OBJ)
	${CC} ${FLAGS} -o "ft_"${NAME} ${OBJ}

std: $(OBJ_D)
	${CC} ${FLAGS} -DSTD -o "std_"${NAME} ${OBJ_D}

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) -o $@ -c $<

$(OBJ_PATH_D)/%.o: $(SRC_PATH)/%.cpp
	@mkdir $(OBJ_PATH_D) 2> /dev/null || true
	$(CC) $(FLAGS) -DSTD -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ_PATH) $(OBJ_PATH_D) "ft_"$(NAME) "std_"$(NAME) ft_out std_out

re: fclean all