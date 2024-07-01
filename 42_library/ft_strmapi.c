/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaidi <csaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:13:40 by csaidi            #+#    #+#             */
/*   Updated: 2023/12/17 13:18:40 by csaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minishell.h"

// char ft_test(unsigned int i, char b)
// {
// 	return b + i;
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	size;
	unsigned int	i;
	char			*ptr;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	ptr = malloc(size + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*int main()
{
    const char *string = "Hello, World!";
    
    char *res = ft_strmapi(string, ft_test);

    printf("first String: %s\n", string);
    printf("nv String: %s\n", res);
	
    free(res);

    return 0;
}*/
// #include<stdio.h>
// int main()
// {
// 	printf("%s",  ft_strmapi(NULL, ft_test));
// }
