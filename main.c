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
	printf("hello %-6c", 'i');
	return 0;
}

//%0-15.6d