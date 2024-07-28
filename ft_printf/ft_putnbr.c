#include "../execution.h"

int	ft_putnbr(int c, int len)
{
	if (c == -2147483648)
		len = ft_putstr("-2147483648", len);
	else if (c < 0)
	{
		len = ft_putchar('-', len);
		len = ft_putnbr(c * (-1), len);
	}
	else if (c >= 10)
	{
		len = ft_putnbr(c / 10, len);
		len = ft_putchar(c % 10 + 48, len);
	}
	else
		len = ft_putchar(c + 48, len);
	return (len);
}
