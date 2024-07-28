#include "../execution.h"

void	env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = env_lstlast(*lst);
	last->next = new;
}
