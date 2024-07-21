SRCS = main.c shell_utils.c extra_utils.c 9aw9a3a_utils.c process_args.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -lcurses -lreadline
NAME = minishell
RM = rm -f
CC = cc

all:$(NAME)

$(NAME):$(OBJ)

%.o: %.c
	@$(CC) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all