#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main()
{
	char	*ptr;

	ptr = "56";
    int i = 42567;
	ft_printf("Conversion c :\n");
	ft_printf("c est compatible avec les flags - et width\n");
	ft_printf("width 5 minus : --------------'%-5c'\n", 'X');
	ft_printf("width 5 sans minus : ---------'%5c'\n", 'X');
	ft_printf("width *3 minus : -------------'%-*c'\n", 3, 'X');
	ft_printf("%d\n",ft_printf("width *3 sans minus : --------'%*c'\n", 3, 'X'));
	ft_printf("width *neg : -----------------'%*c'\n", -5, 'X');
	ft_printf("%c",'\n');


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
	ft_printf("%d\n",ft_printf("minus precision 5 width 20 : ----'%-20.5s'\n", "Hello world"));
	ft_printf("width 12 precision vide : -------'%*.s'\n", 12, "Hello world");
	ft_printf("width 12 precision 0 : ----------'%*.0s'\n", 12, "Hello world");
	ft_printf("width 10 precision 3 : ----------'%*.3s'\n", 10,  "Hello world");
	ft_printf("precision 3 : -------------------'%.3s'\n", "Hello world");
	ft_printf("width 10 prec vide : ------------'%10.s'\n", "Hello world");
	ft_printf(" %10.s %1.s ", "123", "4567\n");
	ft_printf("[ %-3.s ]\n", NULL);
	ft_printf("%c",'\n');


	ft_printf("MY ft_printf\n");
	ft_printf("Conversion p :\n");
	ft_printf("l'addresse de ptr est : %p\n", ptr);
	ft_printf("p est compatible avec les flags - et width\n");
	ft_printf("width 5 minus : -----------------'%-5p'\n", ptr);
	ft_printf("width 5 sans minus : ------------'%5p'\n", ptr);
	ft_printf("width *3 minus : ----------------'%-*p'\n", 3, "Hello world");
	ft_printf("width *3 sans minus : -----------'%*p'\n", 3, "Hello world");
	ft_printf("width 25 minus : ----------------'%-25p'\n", "Hello world");
	ft_printf("width 25 sans minus : -----------'%25p'\n", "Hello world");
	ft_printf("width *30 minus : ---------------'%-*p'\n", 30, &i);
	ft_printf("%d\n",ft_printf("width *30 sans minus : ----------'%*p'\n", 30, "Hello world"));
	ft_printf("'%10p %-10p '\n", 0, 0);
	ft_printf("%c",'\n');

	printf("OG printf\n");
	printf("Conversion p :\n");
	printf("l'addresse de ptr est : %p\n", ptr);
	printf("p est compatible avec les flags - et width\n");
	printf("width 5 minus : -----------------'%-5p'\n", ptr);
	printf("width 5 sans minus : ------------'%5p'\n", ptr);
	printf("width *3 minus : ----------------'%-*p'\n", 3, "Hello world");
	printf("width *3 sans minus : -----------'%*p'\n", 3, "Hello world");
	printf("width 25 minus : ----------------'%-25p'\n", "Hello world");
	printf("width 25 sans minus : -----------'%25p'\n", "Hello world");
	printf("width *30 minus : ---------------'%-*p'\n", 30, &i);
	printf("%d\n", printf("width *30 sans minus : ----------'%*p'\n", 30, "Hello world"));
	printf("'%10p %-10p '\n", 0, 0);
	printf("%c",'\n');


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
	ft_printf("minus w 4 prec 5 : --------------'%-*.*d'\n", 4, 5, 10);
	ft_printf("w 10 prec 21 : ------------------'%*.*d'\n", 10, 21, -10);
	ft_printf("width 21 zero : -----------------'%0*d'\n", 21, -1011);
	ft_printf("width 21 : ----------------------'%*d'\n", 21, -1011);
	ft_printf("zero w -2 prec 0 : --------------'%0*.0d'\n", -2, 98);
	ft_printf("int max %d\n", 2147483648);
	ft_printf("uint max %i\n", 4294967295);
	ft_printf("%c",'\n');


	ft_printf("Conversion u :\n");
	ft_printf("u est compatibles avec les flags '-' | width | '.' | '0'\n");
	ft_printf("width 5 minus : -----------------'%-5u'\n", i);
	ft_printf("width 5 : -----------------------'%5u'\n", i);
	ft_printf("width 5 zero : ------------------'%05u'\n", i);
	ft_printf("width *3 minus : ----------------'%-*u'\n", 3, i);
	ft_printf("width *3 : ----------------------'%*u'\n", 3, i);
	ft_printf("width 25 minus : ----------------'%-25u'\n", i);
	ft_printf("width 25 minus : ----------------'%-25u'\n", i);
	ft_printf("width 25 0 : --------------------'%025u'\n", i);
	ft_printf("width 25 sans minus : -----------'%25u'\n", i);
	ft_printf("width 25 sans minus : -----------'%25u'\n", i);
	ft_printf("width *30 minus : ---------------'%-*u'\n", 30, i);
	ft_printf("width *30 sans minus : ----------'%*u'\n", 30, i);
	ft_printf("precision 3 : -------------------'%.3u'\n", i);
	ft_printf("precision 33 : ------------------'%.33u'\n", i);
	ft_printf("precision 33 zero : -------------'%0.33u'\n", i);
	ft_printf("precision 33 minus : ------------'%-.33u'\n", i);
	ft_printf("precision 33 minus : ------------'%-.33u'\n", i);
	ft_printf("precision 1 width 2 : -----------'%2.1u'\n", i);
	ft_printf("precision 1 width 4 : -----------'%4.1u'\n", i);
	ft_printf("precision 5 width 2 zero : ------'%02.5u'\n", i);
	ft_printf("precision 5 width 20 : ----------'%20.5u'\n", i);
	ft_printf("precision 5 width 20 zero : -----'%020.5u'\n", i);
	ft_printf("minus precision 5 width 20 : ----'%-20.5u'\n", i);
	ft_printf("minus precision 3 : -------------'%.3u'\n", 0);
	ft_printf("zero precision 7 : --------------'%0.7u'\n", -5);
	ft_printf("%d\n", ft_printf("width 10 precision 7 zero : -----'%010.7u'\n", -5));
	ft_printf("uint max %u\n", 4294967295);
	ft_printf("%c",'\n');


	ft_printf("Conversion x :\n");
	ft_printf("x est compatible avec les flags '-' | width | '.' |'0' | '#' \n");
	ft_printf("width 5 minus : -----------------'%-5x'\n", i);
	ft_printf("width 5 : -----------------------'%5x'\n", i);
	ft_printf("width 5 zero : ------------------'%05x'\n", i);
	ft_printf("width *3 minus : ----------------'%-*x'\n", 3, i);
	ft_printf("width *3 : ----------------------'%*x'\n", 3, i);
	ft_printf("width 25 minus : ----------------'%-25x'\n", i);
	ft_printf("width 25 minus : ----------------'%-25X'\n", i);
	ft_printf("width 25 0 : --------------------'%025X'\n", i);
	ft_printf("width 25 sans minus : -----------'%25X'\n", i);
	ft_printf("width 25 sans minus : -----------'%25X'\n", i);
	ft_printf("width *30 minus : ---------------'%-*X'\n", 30, i);
	ft_printf("width *30 sans minus : ----------'%*X'\n", 30, i);
	ft_printf("precision 3 : -------------------'%.3X'\n", i);
	ft_printf("precision 33 : ------------------'%.33x'\n", i);
	ft_printf("precision 33 zero : -------------'%0.33x'\n", i);
	ft_printf("precision 33 minus : ------------'%-.33x'\n", i);
	ft_printf("precision 33 minus : ------------'%-.33X'\n", i);
	ft_printf("precision 1 width 2 : -----------'%2.1x'\n", i);
	ft_printf("precision 1 width 4 : -----------'%4.1x'\n", i);
	ft_printf("precision 5 width 2 zero : ------'%02.5X'\n", i);
	ft_printf("precision 5 width 20 : ----------'%20.5X'\n", i);
	ft_printf("precision 5 width 20 zero : -----'%020.5X'\n", i);
	ft_printf("minus precision 5 width 20 : ----'%-20.5x'\n", i);
	ft_printf("minus precision 3 : -------------'%.3x'\n", 0);
	ft_printf("zero precision 7 : --------------'%#0.7X'\n", -5);
	ft_printf("%d\n", ft_printf("width 10 precision 7 zero : -----'%010.7X'\n", -5));
	ft_printf("%c",'\n');

	while (1)
	{};
	return 0;
}

//gcc ft_conversion_c.c ft_manage_flags.c ft_printf.c ft_printf_utils.c ft_printf.h myprintf_main.c ft_conversion_s.c ft_itoa.c ft_conversion_p.c ft_conversion_num.c ft_conversion_u.c ft_llitoa.c ft_conversion_xlow.c ft_conversion_Xup.c ft_check_error.c && ./a.out
//gcc -fsanitize=address -g3 ft_conversion_c.c ft_manage_flags.c ft_printf.c ft_printf_utils.c ft_printf.h myprintf_main.c ft_conversion_s.c ft_itoa.c ft_conversion_p.c ft_conversion_num.c ft_conversion_u.c ft_llitoa.c ft_conversion_xlow.c ft_conversion_Xup.c ft_check_error.c && ./a.out


/*testeurs :
https://github.com/cacharle/ft_printf_test*/