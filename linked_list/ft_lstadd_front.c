
#include "../minishell.h"

void	ft_lstadd_front(t_ms **lst, t_ms *new)
{
	if (!lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
