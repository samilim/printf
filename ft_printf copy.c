

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_manage_conversions(const char *str, int i, va_list args)
{
	//int count;

	//count = 0;
	//voir https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/printf_form.html

	if (str[i] == 'c') //prend un unsigned char, prend les char d'espacement en compte
		ft_putchar_fd(va_arg(args, unsigned char), 1);
	
	if (str[i] == '%')
		ft_putchar_fd('%', 1);
	// + conversion o?
	//return (count); 
}




int             ft_printf(const char *str, ...)
{
		int	i;
		va_list	args; //Cette liste va servir à naviguer parmis les arguments (qui sont au départ indéfinis tant en nombre qu'en type)

		i = 0;
		va_start(args, str); //initialise la va_liste des args
		while (str[i])
		{
			/*if (str[i] == '\')
			{
				ft_manage_hex();
				if (!charaspécial)
				i++;
			}*/
			if (str[i] == '%')
			{
				i++;
				//ft_manage_flags(str, i);
				//i += ft_manage_flags(str, i);
				//ft_manage_conditions(str, i);
				//i += ft_manage_conversions(str, i);
				ft_manage_conversions(str, i, args); //test only
				i++;  //testonly
			}
			else
			{
				ft_putchar_fd(str[i], 1);
				i++;
			}
		}
		va_end(args);
		return (i); /*nb d'octs lus sans le \0*/
}


int main()
{
	//int i = 42;

	ft_printf("hello hibou %c !", 'o');
	//printf("Ceci est un test; %s\n jghg. %d jg.   %ih", "chaine affichée", 4643, i);
}



/*
INTRO
La versatilité de printf en C représente un bon exercice de programmation pour nous.
Ce projet est d’une difficulté modérée. Il vous permettra d’utiliser les kwargs en C La clé
de la réussite pour ft_printf est un code bien structuré et extensible.

DOC
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
