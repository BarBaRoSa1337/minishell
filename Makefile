SRCS = ft_split.c main.c shell_utils.c extra_utils.c 9aw9a3a_utils.c process_args.c

OBJ = $(SRCS:.c=.o)

CFLAGS = 
NAME = minishell
RM = rm -f
CC = cc

all:$(NAME)

$(NAME):$(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all