#include "../minishell.h"

char *searsh_env(t_env *v)
{
	char *env;

	while(v)
	{
		if (ft_strncmp(v->key, "PATH", ft_strlen(v->key)) == 0)
		{
			env = ft_strdup(v->value);
			return (env);
		}
		v = v->next;
	}
	return (NULL);
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