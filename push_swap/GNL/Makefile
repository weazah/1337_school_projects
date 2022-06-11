SRC = get_next_line.c get_next_line_utils.c

OBJ = ${SRC:.c=.o}

CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = get_next_line.h
NAME = gnl.a

${NAME} : ${OBJ} ${HEADER}
	@${CC} -c ${FLAGS} ${SRC}
	@ar -rc ${NAME} ${OBJ}
clean:
	@rm -f ${OBJ}
fclean : clean
	@rm -f ${NAME}
re : fclean all
all : ${NAME}
