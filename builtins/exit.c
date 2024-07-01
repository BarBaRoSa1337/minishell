#include <stdlib.h>

void build_exit(int status)
{
	exit(status);
}

int main (int ac, char **av)
{
	build_exit(atoi(av[1]));
}
