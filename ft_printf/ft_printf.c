#include "../execution.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			len = ft_putchar(str[i++], len);
		else if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (len);
			i++;
			len = ft_check(str[i], args, len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
