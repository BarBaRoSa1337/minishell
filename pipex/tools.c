#include "../minishell.h"

char	**command_tableau(char *str)
{
	char	**double_path;

	if (ft_strchr(str, '\t') != NULL)
	{
		double_path = ft_split(str, '\t');
		return (double_path);
	}
	double_path = ft_split(str, ' ');
	return (double_path);
}

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