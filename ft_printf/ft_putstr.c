#include "../minishell.h"

int	ft_putstr(char *s, int len)
{
	int	i;

	if (!s)
		return (len = ft_putstr("(null)", len));
	i = 0;
	while (s[i])
	{
		len = ft_putchar(s[i], len);
		i++;
	}
	return (len);
}
