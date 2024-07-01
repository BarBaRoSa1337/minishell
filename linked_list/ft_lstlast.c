
#include "../minishell.h"

t_minishell	*ft_lstlast(t_minishell *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
