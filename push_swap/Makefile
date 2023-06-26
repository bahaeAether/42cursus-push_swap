NAME = ./push_swap
NAME_BONUS = ./checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = 	main.c \
		helpers.c \
		helpers2.c \
		helpers3.c \
		inits.c \
		join.c \
		liss.c \
		linked_list.c \
		linked_list2.c \
		moves.c \
		moves2.c \
		moves3.c \
		moves4.c \
		optimize.c \
		optimize2.c \
		push_swap.c \
		sort.c \
		special_cases.c \
		split.c \
		utils.c \
		utils_cmp.c \
		utils_err.c
OBJ = $(SRC:.c=.o)
SRC_BONUS = 	bonus/checker.c \
				bonus/ft_lst.c \
				bonus/get_next_line.c \
				bonus/get_next_line_utils.c \
				bonus/helper.c \
				bonus/helper2.c \
				bonus/ft_moves.c \
				bonus/ft_moves2.c \
				bonus/ft_moves3.c \
				bonus/ft_moves4.c \
				bonus/ft_utils.c \
				bonus/ft_split.c \
				bonus/ft_join.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)
HEADER = push_swap.h
HEADER_BONUS = bonus/checker.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_BONUS) : $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
