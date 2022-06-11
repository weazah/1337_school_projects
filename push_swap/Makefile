# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozahir <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 18:12:29 by ozahir            #+#    #+#              #
#    Updated: 2022/05/30 19:55:29 by ozahir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIB = LIB/libft.a
PRINT = PRINT/libftprintf.a
GNL = GNL/gnl.a
HEADER = inc/push_swap.h
B_HEADER = inc/push_swap_bonus.h
SRC_DIR = src
B_SRC_DIR = b_src
OBJ_DIR = obj
B_OBJ_DIR = b_obj
CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = push_swap
MAIN = main.c
NAME_B = checker
MAIN_B = main_bonus.c

sources = arr_qs.c bools_handle.c check_vals.c double_rotate.c \
	get_vals.c indexing_func.c init_stack.c managing_funcs.c \
	moves_1.c moves_2.c moves_3.c moves_helpers.c push_swap.c \
	small_sort.c stacks_rotate.c

b_sources = arr_qs.c bonus_add.c check_vals.c get_vals.c init_stack.c \
	managing_funcs.c moves_1.c moves_2.c moves_3.c moves_helpers.c
SRC = $(addprefix $(SRC_DIR)/, $(sources))

B_SRC = $(addprefix $(B_SRC_DIR)/, $(b_sources))

OBJ = $(addprefix $(OBJ_DIR)/, $(sources:.c=.o))

M_OBJ = $(addprefix $(B_OBJ_DIR)/, $(b_sources:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	${CC} ${FLAGS}  -c $< -o $@

$(B_OBJ_DIR)/%.o: $(B_SRC_DIR)/%.c
	@${CC} ${FLAGS}  -c $< -o $@

$(NAME): $(PRINT) $(LIB) $(MAIN) $(OBJ)
	$(CC) $(FLAGS) $(MAIN) $(OBJ) $(PRINT) $(LIB) -o $(NAME)

all: $(NAME)

$(GNL):
	@make -C GNL/

$(LIB):
	@make -C LIB/

$(PRINT):
	@make -C PRINT/

bonus: ${NAME_B}

${NAME_B}: $(GNL) $(LIB) $(MAIN_B) $(M_OBJ) $(PRINT)
	$(CC) $(FLAGS) $(MAIN_B) $(M_OBJ) $(GNL) $(PRINT) $(LIB) -o $(NAME_B)


clean:
	@rm -rf ${OBJ} ${M_OBJ}
	@make clean -C LIB/
	@make clean -C PRINT/
	@make clean -C GNL/

fclean: clean
	@rm -rf $(LIB) $(PRINT) $(GNL) ${NAME} ${NAME_B}

re: fclean all

.phony: re fclean clean bonus all
