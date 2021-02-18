#include <stdio.h>
#include <unistd.h>


void		ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}

int	main()
{
	/*TEST P
	char	*ptr;

	ptr = "56";
	printf("l'addresse de ptr est : %p ", ptr);*/

	int i = 42;
	//printf("hello %*.*s", 15, 6, "hello hey hibou coucourehgekj");
	printf("hi %u", -2);
	return 0;
}

//%0-15.6d