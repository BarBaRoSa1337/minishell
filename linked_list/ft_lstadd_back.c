
#include "../execution.h"

void	ft_lstadd_back(t_ms **lst, t_ms *new)
{
	t_ms	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
