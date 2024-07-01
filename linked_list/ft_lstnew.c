#include "../minishell.h"

t_minishell	*ft_lstnew(void)
{
	t_minishell	*new_node;

	new_node = (t_minishell *)malloc(sizeof(t_minishell));
	if (!new_node)
		return (0);
	new_node->infile = NULL;
	new_node->cmd = NULL;
	new_node->arg = NULL;
	new_node->outfile = NULL;
	new_node->next = NULL;
	return (new_node);
}
