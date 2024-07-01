#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void pwd()
{
	char path[PATH_MAX];
	if (getcwd(path, sizeof(path)) == NULL)
		perror("Error\n");
	printf("%s\n", path);
}

int main ()
{
	pwd();
	return (0);
}
