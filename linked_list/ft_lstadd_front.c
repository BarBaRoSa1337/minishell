
#include "../minishell.h"

void	ft_lstadd_front(t_minishell **lst, t_minishell *new)
{
	if (!lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
