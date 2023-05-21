NAME			:=	multilayer-perceptron
NAME_PATH		:=	$(NAME)
MAKEFLAGS		+=	--silent

SDIR			:=	src/
SRC				:=	$(shell find src -name "*.cpp")

ODIR			:=	obj/
OBJ				:=	$(subst $(SDIR),$(ODIR), ${SRC:.cpp=.o})

CC				:=	c++
CFLG			:=	-Wall -Wextra -Werror -std=c++11

$(ODIR)%.o		: $(SDIR)%.cpp
				mkdir -p $(subst $(SDIR),$(ODIR), $(shell dirname $<)/)
				$(CC) $(CFLG) -c $< -o ${addprefix $(ODIR), ${<:$(SDIR)%.cpp=%.o}}

${NAME_PATH}	: $(OBJ)
				$(CC) $(OBJ) -o $(NAME_PATH)
				# mkdir -p $(BIN)

all				: $(NAME_PATH)

clean			:
				rm -rf $(ODIR)

fclean			: clean
				rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re