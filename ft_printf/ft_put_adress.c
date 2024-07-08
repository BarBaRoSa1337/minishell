#include "../minishell.h"

int	ft_put_adress(unsigned long decimal, int len)
{
	if (!decimal)
		return (len = ft_putstr("0x0", len));
	len = ft_putstr("0x", len);
	len = ft_decimal_to_hex(decimal, len);
	return (len);
}
