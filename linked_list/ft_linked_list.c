
#include "../minishell.h"

void	ft_linked_list(char **ptr, t_list **head)
{
	t_list	*new;
	int		l;

	l = 0;
	while (ptr[l])
	{
		new = ft_lstnew(ft_atoi(ptr[l]));
		ft_lstadd_back(head, new);
		l++;
	}
	return ;
}
