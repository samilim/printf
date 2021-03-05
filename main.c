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

	int i = 42567;
	int *ptr;
/*	printf("hello %*.*s", 15, 6, "hello hey hibou coucourehgekj");
	printf("Conversion c :\n");
	printf("c est compatible avec les flags - et width\n");
	printf("width 5 minus : --------------'%-5c'\n", 'X');
	printf("width 5 sans minus : ---------'%5c'\n", 'X');
	printf("width *3 minus : -------------'%-*c'\n", 3, 'X');
	printf("%d",printf("width *3 sans minus : --------'%*c'\n", 3, 'X'));
	printf("width *neg : -----------------'%*c'\n", -5, 'X');
	printf("%c",'\n');
*/
/*
	printf("Conversion s :\n");
	printf("s est compatible avec les flags -, width et .\n");
	printf("width 5 minus : -----------------'%-5s'\n", "Hello world");
	printf("width 5 sans minus : ------------'%5s'\n", "Hello world");
	printf("width *3 minus : ----------------'%-*s'\n", 3, "Hello world");
	printf("width *3 sans minus : -----------'%*s'\n", 3, "Hello world");
	printf("width 25 minus : ----------------'%-25s'\n", "Hello world");
	printf("width 25 sans minus : -----------'%25s'\n", "Hello world");
	printf("width *30 minus : ---------------'%-*s'\n", 30, "Hello world");
	printf("width *30 sans minus : ----------'%*s'\n", 30, "Hello world");
	printf("precision 3 : -------------------'%.3s'\n", "Hello world");
	printf("precision 33 : ------------------'%.33s'\n", "Hello world");
	printf("precision 5 width 2 : -----------'%2.5s'\n", "Hello world");
	printf("precision 5 width 20 : ----------'%20.5s'\n", "Hello world");
	printf("%d",printf("minus precision 5 width 20 : ----'%-20.5s'\n", "Hello world"));
	printf("width 12 precision vide : -------'%*.s'\n", 12, "Hello world");
	printf("width 12 precision 0 : ----------'%*.0s'\n", 12, "Hello world");
	printf("width 10 precision 3 : ----------'%10.3s'\n", "Hello world");
	printf("precision 3 : -------------------'%.3s'\n", "Hello world");
	printf("width 10 prec vide : ------------'%10.s'\n", "Hello world");
	printf("%c",'\n');
	

	printf("Conversion p :\n");
	printf("p est compatible avec les flags - et width\n");
	printf("width 5 minus : -----------------'%-5p'\n", "Hello world");
	printf("width 5 sans minus : ------------'%5p'\n", "Hello world");
	printf("width *3 minus : ----------------'%-*p'\n", 3, "Hello world");
	printf("width *3 sans minus : -----------'%*p'\n", 3, "Hello world");
	printf("width 25 minus : ----------------'%-25p'\n", "Hello world");
	printf("width 25 sans minus : -----------'%25p'\n", "Hello world");
	printf("width *30 minus : ---------------'%-*p'\n", 30, &i);
	printf("%d\n", printf("width *30 sans minus : ----------'%*p'\n", 30, "Hello world"));
	printf("%c",'\n');

	printf("Conversion i et d :\n");
	printf("i et d sont compatibles avec les flags -, width et .\n");
	printf("width 5 minus : -----------------'%-5i'\n", i);
	printf("width 5 sans minus : ------------'%5i'\n", i);
	printf("width *3 minus : ----------------'%-*i'\n", 3, i);
	printf("width *3 sans minus : -----------'%*d'\n", 3, i);
	printf("width 25 minus : ----------------'%-25d'\n", i);
	printf("width 25 sans minus : -----------'%25d'\n", i);
	printf("width *30 minus : ---------------'%-*d'\n", 30, i);
	printf("width *30 sans minus : ----------'%*d'\n", 30, i);
	printf("precision 3 : -------------------'%.3d'\n", i);
	printf("precision 33 : ------------------'%.33d'\n", i);
	printf("precision 5 width 2 : -----------'%2.5i'\n", i);
	printf("precision 5 width 20 : ----------'%20.5d'\n", i);
	printf("minus precision 5 width 20 : ----'%-20.5d'\n", i);
	printf("%c",'\n');


*/
	printf("Conversion i et d :\n");
	printf("i et d sont compatibles avec les flags '-' | width | '.' | '+' |  ' ' | '0'\n");
	printf("width 5 minus : -----------------'%-5i'\n", i);
	printf("width 5 : -----------------------'%5i'\n", i);
	printf("width 5 spc zero : --------------'% 05i'\n", i);
	printf("width *3 minus space : ----------'% -*i'\n", 3, i);
	printf("width *3 + : --------------------'%+*d'\n", 3, i);
	printf("width 25 minus : ----------------'%-25d'\n", i);
	printf("width 25 minus + : --------------'%-+25d'\n", i);
	printf("width 25 0 : --------------------'%025d'\n", i);
	printf("width 25 sans minus : -----------'%25d'\n", i);
	printf("width 25 sans minus spc : -------'% 25d'\n", i);
	printf("width *30 minus : ---------------'%-*d'\n", 30, i);
	printf("width *30 sans minus : ----------'%*d'\n", 30, i);
	printf("precision 3 : -------------------'%.3d'\n", i);
	printf("precision 33 spc : --------------'% .33d'\n", i);
	printf("precision 33 zero + : -----------'%+0.33d'\n", i);
	printf("precision 33 minus + : ----------'%+-.33d'\n", i);
	printf("precision 33 minus spc : --------'% -.33d'\n", i);
	printf("precision 1 width 2 : -----------'%2.1i'\n", i);
	printf("precision 1 width 4 : -----------'%4.1i'\n", i);
	printf("precision 5 width 2 zero : ------'%02.5i'\n", i);
	printf("precision 5 width 20 : ----------'%20.5d'\n", i);
	printf("precision 5 width 20 zero : -----'%020.5d'\n", i);
	printf("minus precision 5 width 20 + : --'%-+20.5d'\n", i);
	printf("minus precision 3 + : -----------'%+.3d'\n", 0);
	printf("zero precision 7 : --------------'%0.7d'\n", -5);
	printf("%d\n", printf("width 10 precision 7 zero : -----'%010.7d'\n", -5));
	printf("minus w 4 prec 5 : --------------'%-*.*d'\n", 4, 5, 10);
	printf("w 10 prec 21 : ------------------'%*.*d'\n", 10, 21, -10);
	printf("width 21 zero : ------'%0*d'\n", 21, -1011);
	printf("zero w -2 prec 0 : ---'%0*.0d'\n", -2);
	printf("%c",'\n');
/*
	printf("Conversion u :\n");
	printf("u est compatibles avec les flags '-' | width | '.' | '0'\n");
	printf("width 5 minus : -----------------'%-5u'\n", i);
	printf("width 5 : -----------------------'%5u'\n", i);
	printf("width 5 zero : ------------------'%05u'\n", i);
	printf("width *3 minus : ----------------'%-*u'\n", 3, i);
	printf("width *3 : ----------------------'%*u'\n", 3, i);
	printf("width 25 minus : ----------------'%-25u'\n", i);
	printf("width 25 minus : ----------------'%-25u'\n", i);
	printf("width 25 0 : --------------------'%025u'\n", i);
	printf("width 25 sans minus : -----------'%25u'\n", i);
	printf("width 25 sans minus : -----------'%25u'\n", i);
	printf("width *30 minus : ---------------'%-*u'\n", 30, i);
	printf("width *30 sans minus : ----------'%*u'\n", 30, i);
	printf("precision 3 : -------------------'%.3u'\n", i);
	printf("precision 33 : ------------------'%.33u'\n", i);
	printf("precision 33 zero : -------------'%0.33u'\n", i);
	printf("precision 33 minus : ------------'%-.33u'\n", i);
	printf("precision 33 minus : ------------'%-.33u'\n", i);
	printf("precision 1 width 2 : -----------'%2.1u'\n", i);
	printf("precision 1 width 4 : -----------'%4.1u'\n", i);
	printf("precision 5 width 2 zero : ------'%02.5u'\n", i);
	printf("precision 5 width 20 : ----------'%20.5u'\n", i);
	printf("precision 5 width 20 zero : -----'%020.5u'\n", i);
	printf("minus precision 5 width 20 : ----'%-20.5u'\n", i);
	printf("minus precision 3 : -------------'%.3u'\n", 0);
	printf("zero precision 7 : --------------'%0.7u'\n", -5);
	printf("%d\n", printf("width 10 precision 7 zero : -----'%010.7u'\n", -5));
	printf("%c",'\n');

	printf("Conversion x :\n");
	printf("x est compatible avec les flags '-' | width | '.' |'0' | '#' \n");
	printf("width 5 minus : -----------------'%-5x'\n", i);
	printf("width 5 : -----------------------'%5x'\n", i);
	printf("width 5 zero : ------------------'%05x'\n", i);
	printf("width *3 minus : ----------------'%-*x'\n", 3, i);
	printf("width *3 : ----------------------'%*x'\n", 3, i);
	printf("width 25 minus : ----------------'%-25x'\n", i);
	printf("width 25 minus : ----------------'%-25X'\n", i);
	printf("width 25 0 : --------------------'%025X'\n", i);
	printf("width 25 sans minus : -----------'%25X'\n", i);
	printf("width 25 sans minus : -----------'%25X'\n", i);
	printf("width *30 minus : ---------------'%-*X'\n", 30, i);
	printf("width *30 sans minus : ----------'%*X'\n", 30, i);
	printf("precision 3 : -------------------'%.3X'\n", i);
	printf("precision 33 : ------------------'%.33x'\n", i);
	printf("precision 33 zero : -------------'%0.33x'\n", i);
	printf("precision 33 minus : ------------'%-.33x'\n", i);
	printf("precision 33 minus : ------------'%-.33X'\n", i);
	printf("precision 1 width 2 : -----------'%2.1x'\n", i);
	printf("precision 1 width 4 : -----------'%4.1x'\n", i);
	printf("precision 5 width 2 zero : ------'%02.5X'\n", i);
	printf("precision 5 width 20 : ----------'%20.5X'\n", i);
	printf("precision 5 width 20 zero : -----'%020.5X'\n", i);
	printf("minus precision 5 width 20 : ----'%-20.5x'\n", i);
	printf("minus precision 3 : -------------'%.3x'\n", 0);
	printf("zero precision 7 : --------------'%#0.7X'\n", -5);
	printf("%d\n", printf("width 10 precision 7 zero : -----'%010.7X'\n", -5));
	printf("%c",'\n');
*/
	//printf("width %d minus : ----%s------------'%n'\n", 25, "tirets", ptr);
	return 0;
}

//%0-15.6d