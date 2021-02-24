/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:35:33 by salimon           #+#    #+#             */
/*   Updated: 2021/02/24 03:02:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    ft_is_type(const char *str, int i)
{
	const char* types;
	int j;

	types = "cspdiuxXnfge%";
	j = 0;
	while (types[j])
	{
		if (str[i] == types[j])
			return (1);
		j++;
	}
	return (0);
}

t_flags	ft_manage_minus(t_flags flags)
{
	flags.zero = 0;
	flags.minus = 1;
	return (flags);
}

t_flags	ft_manage_width(const char* str, int i, t_flags flags, va_list args)
{
	char	*save_digit;
	int		j;

	save_digit = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!save_digit)
	{
		flags.precision = 0;
		return (flags);
	}
	j = 0;
	if (str[i] == '*')
	{
		flags.width = va_arg(args, int);
		return (flags);
	}
	while (ft_isdigit(str[i]))
		save_digit[j++] = str[i++];
	flags.width = ft_atoi(save_digit);
	free(save_digit);
	return (flags);
}

t_flags ft_manage_precision(const char* str, int i, t_flags flags, va_list args)
{
	char	*save_digit;
	int		j;

	save_digit = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!save_digit)
	{
		flags.precision = 0;
		return (flags);
	}
	j = 0;
	if (str[i + 1] == '*')
		flags.precision = va_arg(args, int);
	if (str[i + 1] && ft_isdigit(str[i + 1]))
	{
		i++;
		while (ft_isdigit(str[i]))
			save_digit[j++] = str[i++];
	}
	flags.precision = ft_atoi(save_digit);
	free(save_digit);
	return (flags);
}

t_flags ft_manage_flags(const char *str, int i, t_flags flags, va_list args)
{
	while (str[i] && !ft_is_type(str, i))
	{
		if (str[i] == '0' && flags.minus == 0)
			flags.zero = 1;
		else if (str[i] == '-')
			flags = ft_manage_minus(flags);
		else if (str[i] == '+')	//BONUS; imprime systématiquement le signe du nombre
		{
			flags.sign = 1;
			flags.space = 0;
		}
		else if (str[i] == ' ' && flags.sign == 0)	// si le premier caractère n'est pas un signe, place un espace au début
			flags.space = 1;
		else if (str[i] == '#')	/*spécifie un format de sortie différent : pour o, le premier chiffre sera 0, pour x ou X,  0x ou 0X sera ajouté si le résultat est non nul, pour e,E,f,g,et G, la sortie comportera toujours un point décimal, pour g et G, les 0 de terminaison seront conservés.*/
			flags.prefix = 1;
		else if (ft_isdigit(str[i]) || (str[i] == '*' && str[i - 1] != '.'))
		{	
			flags = ft_manage_width(str, i, flags, args);
			while (ft_isdigit(str[i + 1]))
				i++;
		}
		else if (str[i] == '.')
		{						//Un point qui sépare la largeur du champ de la précision désirée (pour les flottants)
			flags = ft_manage_precision(str, i, flags, args);
			while (ft_isdigit(str[i + 1]))
				i++;
		}
		/*else if (str[i] == 'h' || str[i] == 'l')	//gerent aussi ll et hh. modifient la largeur du champ. h pour un argument short (ou unsigned short), l pour long  (ou unsigned long)
			ft_manage_lh();*/
		else
		{
			flags.precision = 0;
			return (flags);
		}
		i++;
	}
	return (flags);
}

/*NOTES SUR LA PRECISION
Un nombre, la précision, qui donne
	soit le nombre maximum de caractères d'une chaîne à  imprimer,
	soit le nombre de chiffres à  imprimer à  droite du point décimal pour e, E et f,
	soit le nombre de chiffres significatifs pour g et G,
	soit le nombre minimum de chiffres à  imprimer pour un entier (des 0 seront rajoutés en tête pour remplir le champ).*/
	//. : init a -1. se compose d’un point ( . ) suivi d’un entier décimal non négatif qui, selon le type de conversion, spécifie le nombre de caractères de chaîne, le nombre de décimales ou le nombre de chiffres significatifs à générer
    //Contrairement à la spécification de largeur, la spécification de précision peut entraîner la troncation de la valeur de sortie ou l’arrondi d’une valeur à virgule flottante. Si vous spécifiez 0 comme precision et que la valeur à convertir est 0, vous n’obtenez aucune sortie de caractères, comme illustré dans cet exemple : printf( "%.0d", 0 ); /* No characters output */