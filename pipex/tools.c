#include "../minishell.h"

void	ft_free(char **ptr)
{
	int	l;

	l = 0;
	while (ptr[l])
	{
		free(ptr[l]);
		l++;
	}
	free(ptr);
}