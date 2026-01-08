NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = parsing.c stack_utils.c ft_split.c ops_push.c ops_rev_rotate.c ops_rotate.c ops_swap.c parsing_string.c sort_small.c ft_substr.c chunk_sort.c 
OBJS = $(SRCS:.c=.o)
SRCS_B = get_next_line.c get_next_line_utils.c checker.c ft_strncmp.c
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) main.c $(OBJS) -o $(NAME)

bonus: $(OBJS) $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_B) -o checker

clean: 
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME) checker

re: fclean all bonus