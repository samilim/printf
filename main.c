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
	printf("Conversion c :\n");
	printf("c est compatible avec les flags - et width\n");
	printf("width 5 minus : --------------'%-5c'\n", 'X');
	printf("width 5 sans minus : ---------'%5c'\n", 'X');
	printf("width *3 minus : -------------'%-*c'\n", 3, 'X');
	printf("width *3 sans minus : --------'%*c'\n", 3, 'X');
	printf("%c",'\n');

	/*printf("Conversion s :\n");
	printf("width 5 minus : --------------'%-5s'\n", "Hello world");
	printf("width 5 sans minus : ---------'%5s'\n", "Hello world");
	printf("width *3 minus : -------------'%-*s'\n", 3, "Hello world");
	printf("width *3 sans minus : --------'%*s'\n", 3, "Hello world");
	printf("width 25 minus : -------------'%-25s'\n", "Hello world");
	printf("width 25 sans minus : --------'%25s'\n", "Hello world");
	printf("width *30 minus : ------------'%-*s'\n", 30, "Hello world");
	printf("width *30 sans minus : -------'%*s'\n", 30, "Hello world");
	printf("precision 3 : ----------------'%.3s'\n", "Hello world");
	printf("precision 33 : ---------------'%.33s'\n", "Hello world");
	printf("%c",'\n');*/

	/*printf("Conversion i et d :\n");*/
	return 0;
}

//%0-15.6d