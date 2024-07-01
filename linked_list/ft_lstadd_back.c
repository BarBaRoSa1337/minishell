
#include "../minishell.h"

void	ft_lstadd_back(t_minishell **lst, t_minishell *new)
{
	t_minishell	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
