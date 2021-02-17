/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:12:16 by salimon           #+#    #+#             */
/*   Updated: 2021/02/17 17:12:55 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "ft_printf.h"

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

int		ft_nb_count(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

int		ft_putnbr_fd(int nb, int fd)
{
	int count;

	count = ft_nb_count(nb);
	if (t_list.minus && (nb >= 0))
		write (1, '+', 1);
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
	return (count);
}

	ft_manage_flags()
	{
		
	}


// le type détermine soit l’interprétation de precision , soit la précision par défaut quand precision est omis, comme illustré dans le tableau 

int		ft_manage_conversions(const char *str, int i, va_list args)
{
	if (str[i] == 'c')
		return (ft_putchar_fd(va_arg(args, unsigned char), 1));
	if (str[i] == 's')
		return (ft_putstr_fd(va_arg(args, const char *), 1));
	/*if (str[i] == 'p')
		return (ft_putaddr_fd(va_arg(args, void *), 1));*/
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	/*if (str[i] == 'u')
		putnbr si int positif (même au delà de 255), si negatif affiche wtf)*/
	/*if (str[i] == 'x' || str[i] == 'X')
		ft_puthex_fd(va_arg(args, int), 1); //ft à faire, affiche l'hexa en min ou maj*/
	if (str[i] == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (0);
}

	ft_init_flags(t_flags flags)
{
//INDICATEURS
    flags.minus = 0;
    flags.sign = 0; //+ : imprime systématiquement le signe du nombre. BONUS
	flags.zero = 0; ///pour les conversions numériques complète le début du champ par des 0. Annulé par -
    flags.space = 0; //si le premier caractère n'est pas un signe, place un espace au début. BONUS
    flags.prefix = ; //BONUS
//LARGEUR
    flags.width = ; //controle le nb minimal de caracteres affches
    flags.width_spec; //* Si la spécification de la largeur ou de la precision est un astérisque (*), un argument int issu de la liste d’arguments fournit la valeur. L’argument width doit précéder la valeur mise en forme dans la liste des arguments, comme illustré dans l’exemple suivant : printf("%0*d", 5, 3); /* 00003 is output */
        //Une valeur width manquante ou petite dans une spécification de conversion n’entraîne pas la troncation d’une valeur de sortie. Si le résultat d’une conversion est plus large que la valeur width , le champ peut être développé pour contenir le résultat de la conversion.
//PRECISION
    flags.precision = -1;
    flags.precision_spec = ;
//BONUS
    int //l 
    int //ll 
    int //h
    int //hh
	return (flags);
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
			if (str[i] == '%') //gerer si % dernier car
			{
				flags = ft_init_flags(flags);
				i++;
				ft_manage_flags(str, i, flags); //check et assigne valeur a chaque flag pour chaque conversion
				count += ft_manage_conversions(str, i, args);
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
	int i = 42;
	int *ptr;

	ptr = &i;
	//printf("%d\n",ft_printf("mon printf \taffiche X : %c, affiche prct : %%, affiche hello : %s, affiche -42 : %d, affiche adresse de i : %p\n", 'X', "hello", -95, ptr));
	printf("addr = %p\n", ptr);
	//printf("%d\n",printf("    printf \taffiche X : %c, affiche prct : %%, affiche hello : %s, affiche -42 : %d, affiche adresse de i : %p\n", 'X', "hello", -95, ptr));
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
