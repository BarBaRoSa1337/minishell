
#include "../minishell.h"

t_ms	*ft_lstlast(t_ms *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
