NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c parsing.c stack_utils.c ft_split.c ops_push.c ops_rev_rotate.c ops_rotate.c ops_swap.c parsing_string.c sort_small.c ft_substr.c chunk_sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all