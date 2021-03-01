/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:12:16 by salimon           #+#    #+#             */
/*   Updated: 2021/03/01 01:29:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

t_flags	ft_init_flags(t_flags flags)
{
    flags.minus = 0;
    flags.sign = 0;
	flags.zero = 0;
    flags.space = 0;
    flags.prefix = 0;
    flags.width = 0;
    flags.precision = -1;
//BONUS
    flags.l = 0;
    flags.h = 0;
	return (flags);
}

int		ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int		ft_manage_conversions(const char *str, int i, va_list args, t_flags flags)
{
	if (str[i] == 'c')
		return (ft_conversion_c(va_arg(args, int), 1, flags));
	if (str[i] == 's')
		return (ft_conversion_s(va_arg(args, const char *), flags));
	if (str[i] == 'p')
		return (ft_conversion_p(va_arg(args, void *), flags));
	if (str[i] == 'd' || str[i] == 'i')
		return (ft_conversion_num(va_arg(args, int), 1, flags));
	if (str[i] == 'u')
		return (ft_conversion_u(va_arg(args, long long int), 1, flags));
	if (str[i] == 'x')
		return (ft_conversion_x(va_arg(args, unsigned int), flags));
	if (str[i] == 'X')
		return (ft_conversion_X(va_arg(args, unsigned int), flags));
	/*if (str[i] == 'n') Ecrit dans l'argument, le nombre de caractères écrits jusque là par printf. Ne convertit pas d'arguments
		return (ft_conversion_n(va_arg(args, int *), 1));
	if (str[i] == 'f' || str[i] == 'e' || str[i] == 'g') flag f prend un double, gère les floats.  [-]mmm.ddd, où le nombre de d est donné par la précision (6 par défaut). Si la précision vaut 0, le point décimal est supprimé. flag e same que f mais format [-]mmm.ddde+/-xx. Format %e ou %E si l'exposant est < -4 ou >= la précision, suivant %f sinon. Les 0 ou le point décimal à la fin du nombre ne sont pas imprimés
		return (ft_conversion_float(va_arg(args, float), 1));*/
	if (str[i] == '%')  //gerer cas dernier caractere
		return (ft_putchar_fd('%', 1));
	else
		return (0);
}

int             ft_printf(const char *str, ...)
{
		int	i;
		int count;
		t_flags	flags;
		va_list	args;

		i = 0;
		count = 0;
		va_start(args, str);
		if (ft_check_error(str))
			return (0);
		while (str[i])
		{
			if (str[i] == '%')
			{
				flags = ft_init_flags(flags);
				i++;
				flags = ft_manage_flags(str, i, flags, args);
				while (!ft_is_type(str, i))
					i++;
				count += ft_manage_conversions(str, i, args, flags);
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

/*
check error la str de base
free et proteger les malloc
precision 0*/

/*
DOC
//voir https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/printf_form.html
man 3 printf : https://docs.microsoft.com/fr-fr/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160
man 3 stdarg : https://koor.fr/C/cstdarg/cstdarg.w
kwargs: 
va_start
va_arg
va_copy
va_end
taille de champ

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
*/
