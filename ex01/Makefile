TARGET = RPN
NAME = $(TARGET)

CC = c++

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = includes

SRC_FILES = main.cpp RPN.cpp

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)

DEPS = $(wildcard $(INC_DIR)/*.h)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) -o $@ $^
	@echo "--- $(NAME) was built successfully ---"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	@echo "Building $<..."
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@ $(CPPFLAGS)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned build cache"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned build"

re: fclean all
	@echo "--- recompile done ---"

.PHONY: all clean fclean re
.NOTPARALLEL: clean fclean all re
