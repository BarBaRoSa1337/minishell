#include "../minishell.h"

int	ft_putchar(char c, int len)
{
	write(2, &c, 1);
	len += 1;
	return (len);
}
