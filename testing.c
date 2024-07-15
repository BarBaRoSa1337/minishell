#include "minishell.h"

t_shell	*new_node(void)
{
	t_shell	*new_node;

	new_node = (t_shell *)malloc(sizeof(t_shell));
	if (!new_node)
		return (0);
	new_node->in = 0;
	new_node->cmd = NULL;
	new_node->argument = NULL;
	new_node->out = 1;
	new_node->next = NULL;
	return (new_node);
}

void    node_1(t_shell **e)
{
    int fd_out = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    (*e)->cmd = ft_strdup("ls");
    (*e)->in;
    (*e)->out = fd_out;
    (*e)->argument = NULL;
}

void    node_2(t_shell **e)
{

    int fd_in = open("Makefile", O_RDONLY);
    int fd_out = open("outfile_2", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    (*e)->cmd = ft_strdup("cat");
    (*e)->in = fd_in;
    (*e)->out =  fd_out;
    (*e)->argument = NULL;
}

void    node_3(t_shell **e)
{
    int fd_in = open("Makefile", O_RDONLY);
    int fd_out = open("outfile_3", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    (*e)->cmd = ft_strdup("wc");
    (*e)->in = fd_in;
    (*e)->out =  fd_out;
    (*e)->argument = NULL;
}