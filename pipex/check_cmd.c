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

char	*check_cmd(t_ms *e, t_env *v)
{
	char *env;

	env = searsh_env(v);
	if (env)
	{
		if (e->cmd != NULL)
			e->cmd = if_accessible(e->cmd, env);

		if (!e->cmd)
			ft_printf("%s: command not found\n", e->cmd);
	}
	return(e->cmd);
}
