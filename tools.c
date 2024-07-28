#include "execution.h"

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

int multiple_arg(char **ptr)
{
        int l;
        
        l = 0;
        while(ptr[l])
                l++;
        if (l > 1)
                return (1);
        return (-1);
}