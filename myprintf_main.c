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
	
	ft_print("Conversion p :\n");
	ft_printf("l'addresse de ptr est : %p ", ptr);
	//printf("Conversion i et d :\n");*/
	return 0;
}

//gcc ft_conversion_c.c ft_manage_flags.c ft_printf\ copy.c ft_printf_utils.c ft_printf.h myprintf_main.c