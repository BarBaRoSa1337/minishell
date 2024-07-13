#include "minishell.h"

void    node_1(t_ms **e)
{
    char **a;

    a = malloc (3 * sizeof(char *));
    a[0] = ft_strdup("ls");
    a[1] = ft_strdup("-la");
    a[2] = NULL;

    
    int fd_out = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    (*e)->pid = 0;
    (*e)->cmd = ft_strdup("pwd");
    (*e)->infile;
    (*e)->outfile = fd_out;
    (*e)->arg = NULL;
}

void    node_2(t_ms **e)
{
    char **b = NULL;
    
    b = malloc (2 * sizeof(char *));

    b[0] = ft_strdup("..");
    // b[1] = ft_strdup("a");
    b[1] = NULL;

    int fd_in = open("Makefile", O_RDONLY);
    int fd_out = open("out", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    (*e)->pid = 1;
    (*e)->cmd = ft_strdup("cd");
    (*e)->infile = fd_in;
    (*e)->outfile =  fd_out;
    (*e)->arg = b;
}

void    node_3(t_ms **e)
{
    char **b = NULL;
    
    b = malloc (2 * sizeof(char *));

    b[0] = ft_strdup("..");
    // b[1] = ft_strdup("a");
    b[1] = NULL;

    int fd_in = open("Makefile", O_RDONLY);
    int fd_out = open("out", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    (*e)->pid = 1;
    (*e)->cmd = ft_strdup("pwd");
    (*e)->infile = fd_in;
    (*e)->outfile =  fd_out;
    (*e)->arg = NULL;
}