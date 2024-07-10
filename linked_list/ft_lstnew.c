#include "../minishell.h"

t_ms	*ft_lstnew(void)
{
	t_ms	*new_node;

	new_node = (t_ms *)malloc(sizeof(t_ms));
	if (!new_node)
		return (0);
	new_node->infile = NULL;
	new_node->cmd = NULL;
	new_node->arg = NULL;
	new_node->outfile = NULL;
	new_node->next = NULL;
	return (new_node);
}
