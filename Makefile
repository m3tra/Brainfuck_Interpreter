# Color codes
WHITE	:=	"\033[0m"
RED		:=	"\033[38;5;1m"
GREEN	:=	"\033[38;5;47m"
BLUE	:=	"\033[38;5;14m"
YELLOW	:=	"\033[33m"


MAKEFLAGS += --silent
CC		:= gcc
FLAGS	:= -Wall -Wextra -Werror	# Error flags
FLAGS	+= -g -fsanitize=address #-O3 # Debug flags
FLAGS	+= -lm # Link math

NAME	:=	brainterpreter
INC_DIR	:=	inc
INC		:=	$(addprefix -I, $(INC_DIR))
SRCS	:=	$(wildcard src/*.c)
OBJS	:=	$(SRCS:.c=.o)

all: $(NAME)

# @ executes command without printing to the terminal

%.o : %.c
	@printf $(BLUE)"[OBJ]: "
	@printf $(GREEN)"$@\n"$(WHITE)
	@$(CC) $(FLAGS) -c $^ -o $@ $(INC)

$(NAME) : $(OBJS)
	@printf $(YELLOW)"[CREATING ${@F}]\n"$(WHITE)
	@$(CC) $(FLAGS) $^ -o $@ $(INC)

clean:
	@printf $(RED)"[REMOVING OBJECTS]\n"$(WHITE)
	@rm -f $(OBJS)

fclean: clean
	@printf $(RED)"[REMOVING BINARIES]\n"$(WHITE)
	@rm -f $(NAME)

re: fclean all

r:
	make re && ./$(NAME)

.PHONY: all clean fclean re r
