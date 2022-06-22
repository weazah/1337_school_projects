
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
	@rm -rf $(OBJ) $(BONUS_OBJ)
fclean: clean
	@rm -rf $(NAME) $(BONUS)

re: fclean all

.phony: all clean fclean re
#########################################################
BONUS = philo_bonus
BONUS_HEADER = bonus/philo.h
BONUS_MAIN = bonus/main.c

BONUS_SRC = bonus/arg_eval.c bonus/error.c bonus/routine.c bonus/simulation.c \
	 bonus/start_sim.c  bonus/tools.c bonus/watchers.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ) $(BONUS_HEADER) $(BONUS_MAIN)
	$(CC) $(BONUS_MAIN) $(PFLAGS) -lpthread $(BONUS_OBJ) -o $(BONUS)
