#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main()
{
	char	*ptr;

	ptr = "56";
    int i = 42;
	/*ft_printf("Conversion c :\n");
	ft_printf("c est compatible avec les flags - et width\n");
	ft_printf("width 5 minus : --------------'%-5c'\n", 'X');
	ft_printf("width 5 sans minus : ---------'%5c'\n", 'X');
	ft_printf("width *3 minus : -------------'%-*c'\n", 3, 'X');
	ft_printf("width *3 sans minus : --------'%*c'\n", 3, 'X');
    ft_printf("%c",'X');
	ft_printf("%c",'\n');*/
/*
	ft_printf("Conversion s :\n");
	ft_printf("s est compatible avec les flags -, width et .\n");
	ft_printf("width 5 minus : -----------------'%-5s'\n", "Hello world");
	ft_printf("width 5 sans minus : ------------'%5s'\n", "Hello world");
	ft_printf("width *3 minus : ----------------'%-*s'\n", 3, "Hello world");
	ft_printf("width *3 sans minus : -----------'%*s'\n", 3, "Hello world");
	ft_printf("width 25 minus : ----------------'%-25s'\n", "Hello world");
	ft_printf("width 25 sans minus : -----------'%25s'\n", "Hello world");
	ft_printf("width *30 minus : ---------------'%-*s'\n", 30, "Hello world");
	ft_printf("width *30 sans minus : ----------'%*s'\n", 30, "Hello world");
	ft_printf("precision 3 : -------------------'%.3s'\n", "Hello world");
	ft_printf("precision 33 : ------------------'%.33s'\n", "Hello world");
	ft_printf("precision 5 width 2 : -----------'%2.5s'\n", "Hello world");
	ft_printf("precision 5 width 20 : ----------'%20.5s'\n", "Hello world");
	ft_printf("minus precision 5 width 20 : ----'%-20.5s'\n", "Hello world");
	ft_printf("%c",'\n');
	*/

/*
	ft_printf("MY PRINTF\n");
	ft_printf("Conversion p :\n");
	ft_printf("l'addresse de ptr est : %p\n", ptr);
	ft_printf("p est compatible avec les flags - et width\n");
	ft_printf("width 5 minus : -----------------'%-5p'\n", "Hello world");
	ft_printf("width 5 sans minus : ------------'%5p'\n", "Hello world");
	ft_printf("width *3 minus : ----------------'%-*p'\n", 3, "Hello world");
	ft_printf("width *3 sans minus : -----------'%*p'\n", 3, "Hello world");
	ft_printf("width 25 minus : ----------------'%-25p'\n", "Hello world");
	ft_printf("width 25 sans minus : -----------'%25p'\n", "Hello world");
	ft_printf("width *30 minus : ---------------'%-*p'\n", 30, &i);
	printf("%d\n",ft_printf("width *30 sans minus : ----------'%*p'\n", 30, "Hello world"));
	ft_printf("%c",'\n');

	printf("PRINTF\n");
	printf("Conversion p :\n");
	printf("l'addresse de ptr est : %p\n", ptr);
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
*/
/*
	printf("Conversion i et d :\n");
	printf("i et d sont compatibles avec les flags '-' | width | '.' | '+' |  ' ' | '0'\n");
	printf("width 5 minus : -----------------'%-5i'\n", i);
	printf("width 5 sans minus : ------------'%5i'\n", i);
	printf("width 5 spc zero : --------------'% 05i'\n", i);
	printf("width *3 minus space : ----------'% -*i'\n", 3, i);
	printf("width *3 sans minus + : ---------'%+*d'\n", 3, i);
	printf("width 25 minus : ----------------'%-25d'\n", i);
	printf("width 25 sans minus : -----------'%25d'\n", i);
	printf("width 25 sans minus spc : -------'% 25d'\n", i);
	printf("width *30 minus : ---------------'%-*d'\n", 30, i);
	printf("width *30 sans minus : ----------'%*d'\n", 30, i);
	printf("precision 3 : -------------------'%.3d'\n", i);
	printf("precision 33 spc : --------------'% .33d'\n", i);
	printf("precision 33 zero + : -----------'%+0.33d'\n", i);
	printf("precision 5 width 2 : -----------'%2.5i'\n", i);
	printf("precision 5 width 2 zero : ------'%02.5i'\n", i);
	printf("precision 5 width 20 : ----------'%20.5d'\n", i);
	printf("precision 5 width 20 zero : -----'%020.5d'\n", i);
	printf("minus precision 5 width 20 + : --'%-+20.5d'\n", i);
	printf("%c",'\n');*/

	ft_printf("Conversion i et d :\n");
	ft_printf("i et d sont compatibles avec les flags '-' | width | '.' | '+' |  ' ' | '0'\n");
	ft_printf("width 5 minus : -----------------'%-5i'\n", i);
	ft_printf("width 5 : -----------------------'%5i'\n", i);
	ft_printf("width 5 spc zero : --------------'% 05i'\n", i);
	ft_printf("width *3 minus space : ----------'% -*i'\n", 3, i);
	ft_printf("width *3 + : --------------------'%+*d'\n", 3, i);
	ft_printf("width 25 minus : ----------------'%-25d'\n", i);
	ft_printf("width 25 minus + : --------------'%-+25d'\n", i);
	ft_printf("width 25 0 : --------------------'%025d'\n", i);
	ft_printf("width 25 sans minus : -----------'%25d'\n", i);
	ft_printf("width 25 sans minus spc : -------'% 25d'\n", i);
	ft_printf("width *30 minus : ---------------'%-*d'\n", 30, i);
	ft_printf("width *30 sans minus : ----------'%*d'\n", 30, i);
	ft_printf("precision 3 : -------------------'%.3d'\n", i);
	ft_printf("precision 33 spc : --------------'% .33d'\n", i);
	ft_printf("precision 33 zero + : -----------'%+0.33d'\n", i);
	ft_printf("precision 33 minus + : ----------'%+-.33d'\n", i);
	ft_printf("precision 33 minus spc : --------'% -.33d'\n", i);
	ft_printf("precision 1 width 2 : -----------'%2.1i'\n", i);
	ft_printf("precision 1 width 4 : -----------'%4.1i'\n", i);
	ft_printf("precision 5 width 2 zero : ------'%02.5i'\n", i);
	ft_printf("precision 5 width 20 : ----------'%20.5d'\n", i);
	ft_printf("precision 5 width 20 zero : -----'%020.5d'\n", i);
	ft_printf("minus precision 5 width 20 + : --'%-+20.5d'\n", i);
	ft_printf("minus precision 3 + : -----------'%+.3d'\n", 0);
	ft_printf("zero precision 7 : --------------'%0.7d'\n", -5);
	ft_printf("%d\n", ft_printf("width 10 precision 7 zero : -----'%010.7d'\n", -5));
	ft_printf("%c",'\n');
	//printf("Conversion i et d :\n");*/
	return 0;
}

//gcc ft_conversion_c.c ft_manage_flags.c ft_printf\ copy.c ft_printf_u
//gcc ft_conversion_c.c ft_manage_flags.c ft_printf\ copy.c ft_printf_utils.c ft_printf.h myprintf_main.c ft_conversion_s.c ft_itoa.c ft_conversion_p.c ft_conversion_num.c && ./a.out