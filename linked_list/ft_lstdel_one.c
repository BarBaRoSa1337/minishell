#include "../minishell.h"

void	ft_lstdelone(t_ms *list, void (*del)(int))
{
	if (!list || !del)
		return ;
	del(list->data);
	free(list);
}
