#include "minishell.h"

char	*returnline(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	line[i] = '\0';
	i--;
	while (i >= 0)
	{
		line[i] = buffer[i];
		i--;
	}
	return (line);
}

char	*ft_readfile(int fd, char *buffer)
{
	char		*readline;
	ssize_t		l;

	readline = malloc((size_t)BUFFER_SIZE +1);
	if (!readline)
		return (NULL);
	while (ft_strchr(buffer, '\n') == NULL)
	{
		l = read(fd, readline, BUFFER_SIZE);
		if (l == -1)
		{
			free(buffer);
			buffer = NULL;
			break ;
		}
		if (l == 0)
			break ;
		readline[l] = '\0';
		buffer = ft_strjoin(buffer, readline);
	}
	free(readline);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*swap;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readfile(fd, buffer);
	if (!buffer || !buffer[0])
	{
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = returnline(buffer);
	swap = buffer;
	buffer = ft_strdup(swap + ft_strlen(line));
	return (free (swap), line);
}
