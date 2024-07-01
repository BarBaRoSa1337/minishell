
#include "../minishell.h"

void	env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
