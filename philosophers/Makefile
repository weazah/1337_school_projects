CC = gcc
PFLAGS = -Wall -Wextra -Werror
NAME = philo
HEADER = mandatory/philosophers.h
MAIN = mandatory/main.c

SRC = mandatory/utils.c mandatory/evals.c mandatory/exit_func.c mandatory/philosophers.c mandatory/routine.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	${CC} ${PFLAGS}  -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(MAIN)
	$(CC) $(MAIN) $(PFLAGS) -lpthread  $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)

re: fclean all

.phony: all clean fclean re
