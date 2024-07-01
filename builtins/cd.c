#include <unistd.h>
#include <stdio.h>

void cd(const char *direction)
{
	if (direction)
	{
		if (chdir(direction) == -1)
			perror(direction);
	}
}

int main(int ac, char **av)
{
	cd(av[1]);
	return(0);
}
