#include "../minishell.h"

void	env_lstadd_front(t_env **lst, t_env *new)
{
	if (!lst)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
