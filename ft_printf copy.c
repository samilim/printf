# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_putstr_fd(const char *s, int fd)
{
	int count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		ft_putchar_fd(*s++, fd);
		count++;
	}
	return (count);
}

//WIP
/*
int		ft_putaddr_fd(void *ptr, int fd)
{
	void *addr;
	int count;
	
	(char *)addr = &ptr;
	count = 0;
	while (*addr)
	{
		ft_putchar_fd(*addr++, 1);
		count++;
	}
	return (count);
}*/

int		ft_putnbr_fd(int nb, int fd)
{
	int count;

	count = 0;
	if (nb == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		nb = 147483648;
		count = 10;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
		count++;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd(nb % 10 + '0', fd);
		count++;
	}
	else
	{
		ft_putchar_fd(nb + '0', fd);
		count++;
	}
}

int		ft_manage_conversions(const char *str, int i, va_list args)
{
	if (str[i] == 'c')
		return (ft_putchar_fd(va_arg(args, unsigned char), 1));
	if (str[i] == 's')
		return (ft_putstr_fd(va_arg(args, const char *), 1));
	/*if (str[i] == 'p')
		return (ft_putaddr_fd(va_arg(args, void *), 1));*/
	if (str[i] == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	if (str[i] == '%')
		return (ft_putchar_fd('%', 1));
}

int             ft_printf(const char *str, ...)
{
		int	i;
		int count;
		va_list	args; //Cette liste va servir à naviguer parmis les arguments (qui sont au départ indéfinis tant en nombre qu'en type)
		va_start(args, str); //initialise la va_liste des args

		i = 0;
		count = 0;
		while (str[i])
		{
			if (str[i] == '%')
			{
				i++;
				//ft_manage_flags(str, i);
				//i += ft_manage_flags(str, i);
				//ft_manage_conditions(str, i);
				count += ft_manage_conversions(str, i,args);
				i++;
			}
			else
			{
				count += ft_putchar_fd(str[i], 1);
				i++;
			}
		}
		va_end(args);
		return (count);
}


int main()
{
	//int i = 42;

	printf("%d\n",ft_printf("mon printf \taffiche X : %c, affiche prct : %%, affiche hello : %s, affiche -42 : %d\n", 'X', "hello", -42));
	printf("%d\n",printf("    printf \taffiche X : %c, affiche prct : %%, affiche hello : %s, affiche -42 : %d\n", 'X', "hello", -42));
	return 0;
}



/*
INTRO
La versatilité de printf en C représente un bon exercice de programmation pour nous.
Ce projet est d’une difficulté modérée. Il vous permettra d’utiliser les kwargs en C La clé
de la réussite pour ft_printf est un code bien structuré et extensible.

DOC
//voir https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/printf_form.html
man 3 printf : https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160
man 3 stdarg : https://koor.fr/C/cstdarg/cstdarg.w
kwargs: 
va_start
va_arg
va_copy
va_end
conditions: cspdiuxX%
flags : ’-0.*’  + BONUS[ 'l ll h hh'  ++ ’# +’ ]
taille de champ
BONUS conversions : nfge
arguments à taille variable

à mettre au clair : différence entre null vide et 0


INDICATIONS
Fonctions externes autorisées;  malloc, free, write, va_start, va_arg, va_copy, va_end

Vous ne devez pas gérer de buffer, contrairement au vrai printf
Vous devez gérer les conversions suivantes : cspdiuxX%
Vous devez gérer n’importe quelle combinaison de flags ’-0.*’ et la taille de champ
minimale avec toutes les conversions
Votre rendu sera comparé au vrai printf

BONUS
Gérez une ou plusieurs des conversions suivantes : nfge
• Gérez un ou plusieurs des flags suivants : l ll h hh
• Gérez tous les flags suivants : ’# +’ (oui espace est un flag valide)


IDEES
*/
