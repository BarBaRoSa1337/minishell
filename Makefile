
SRCS = linked_list/ft_lstadd_back.c linked_list/ft_lstnew.c linked_list/ft_lstlast.c linked_list/ft_lstadd_front.c \
env_linked_list/env_lstadd_back.c env_linked_list/env_lstadd_front.c env_linked_list/env_lstnew.c \
env_linked_list/env_lstlast.c env_linked_list/get_envp.c env_linked_list/split_env.c get_next_line.c \
builtins/build_cd.c builtins/build_echo.c builtins/build_env.c builtins/build_exit.c builtins/build_export.c \
builtins/build_pwd.c builtins/build_unset.c forming_list.c main.c execution/execute_cmd.c \
execution/simple_execute.c execution/execute_builtins.c tools.c

SRCS_LIBFT = 42_library/ft_atoi.c 42_library/ft_isdigit.c 42_library/ft_memset.c 42_library/ft_strlen.c \
	42_library/ft_bzero.c 42_library/ft_isprint.c 42_library/ft_strchr.c 42_library/ft_strncmp.c 	\
	42_library/ft_calloc.c 42_library/ft_memchr.c 42_library/ft_strdup.c 42_library/ft_strnstr.c 	\
	42_library/ft_isalnum.c 42_library/ft_memcmp.c 42_library/ft_strjoin.c 42_library/ft_strrchr.c  \
	42_library/ft_isalpha.c 42_library/ft_memcpy.c 42_library/ft_strlcat.c 42_library/ft_tolower.c  \
	42_library/ft_isascii.c 42_library/ft_memmove.c 42_library/ft_strlcpy.c 42_library/ft_toupper.c \
	42_library/ft_substr.c 42_library/ft_strtrim.c 42_library/ft_split.c 42_library/ft_itoa.c \
	42_library/ft_strmapi.c 42_library/ft_striteri.c 42_library/ft_putchar_fd.c 42_library/ft_putstr_fd.c \
	42_library/ft_putendl_fd.c 42_library/ft_putnbr_fd.c

SRCS_PRINTF = ft_printf/ft_printf.c ft_printf/ft_decimal_to_hex.c ft_printf/ft_check.c \
	ft_printf/ft_decimal_to_hexa.c ft_printf/ft_put_positive.c ft_printf/ft_putnbr.c  \
	ft_printf/ft_putstr.c ft_printf/ft_put_adress.c ft_printf/ft_putchar.c

SRCS_PIPEX = pipex/ft_pipe.c pipex/if_accessible.c pipex/check_cmd.c 

OBJS = $(SRCS:.c=.o) $(SRCS_LIBFT:.c=.o) $(SRCS_PRINTF:.c=.o) $(SRCS_PIPEX:.c=.o)

NAME = minishell

CFLAGS = #-fsanitize=address #-Wall -Werror -Wextra 
CC = gcc

all : $(NAME) 

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean :
	-rm -f $(OBJS)
		
fclean : clean
	-rm -f $(NAME)

re : fclean	all
