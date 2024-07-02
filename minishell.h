#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

// 1= infile
// 2= cmd
// 3= arg
// 4= outfile
// 5= pipe

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;

typedef struct s_shell
{
    char *arg;
    int type;
    struct s_shell *next;
} t_shell;

typedef struct s_minishell
{
    char *infile;
    char *cmd;
    char *arg;
    char *outfile;
    struct s_minishell *next;
} t_minishell;

/*********************    Linked_list    *********************/

void				ft_lstadd_front(t_minishell **lst, t_minishell *new);
void				ft_lstadd_back(t_minishell **lst, t_minishell *new);
t_minishell			*ft_lstnew(void);
t_minishell			*ft_lstlast(t_minishell *lst);

/**********************     LIBFT    **********************/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit( int c );
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove( void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/**************** get_next_line  *******************/

char		*get_next_line(int fd);
char		*ft_readfile(int fd, char *buffer);
char		*returnline(char *buffer);

/**************** builtins  *******************/

void build_cd(char *direction);
void build_echo(char *str, int nl, int fd);
void build_env(t_env *v);
void build_exit(int status);
void build_export(char *str, t_env **v);
void build_pwd(void);
void build_unset(char *str, t_env **v);

/************** env_linked_list  ****************/

void env_lstadd_back(t_env **lst, t_env *new);
void env_lstadd_front(t_env **lst, t_env *new);
t_env *env_lstlast(t_env *lst);
t_env *env_lstnew(void);
void get_envp(char **envp, t_env **head);
t_env *split_env(char *str);

/******************* execution ********************/

void forming_list(t_minishell **my_struct, t_shell *shell);
void execute(t_minishell *s_execution);

#endif
