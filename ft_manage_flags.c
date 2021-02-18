/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:35:33 by salimon           #+#    #+#             */
/*   Updated: 2021/02/18 17:17:26 by salimon          ###   ########.fr       */
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

int	ft_manage_minus(t_flags flags)
{
	if (flags.zero)
		flags.zero = 0;
	return (flags.minus);
}

int	ft_manage_zero(t_flags flags)
{
	
}

t_flags ft_manage_flags(const char *str, int i, t_flags flags, va_list args)
{
	while (str[i] && !ft_is_type(str, i))
	{
		if (str[i] == '-')													// -chiffre completera jusqu'a chiffre avec des ' '  0 annulé par -
			flags.minus = ft_manage_minus(flags);
		if (str[i] == '+')													//BONUS; imprime systématiquement le signe du nombre
			flags.sign = 1;
		if (str[i] == ' ')													// si le premier caractère n'est pas un signe, place un espace au début
			flags.space = 1;
		if (str[i] == '0' )													//pour les conversions numériques complète le début du champ par des 0. annulé par -
			flags.zero = ft_manage_zero(flags);
		if (str[i] == '#')													/*spécifie un format de sortie différent : pour o, le premier chiffre sera 0, pour x ou X,  0x ou 0X sera ajouté si le résultat est non nul, pour e,E,f,g,et G, la sortie comportera toujours un point décimal, pour g et G, les 0 de terminaison seront conservés.*/
			flags.prefix = 1;
		if (str[i] == ft_isdigit(str[i]))									//Un nombre qui précise la largeur minimum du champ d'impression (complété si nécessaire par des espaces ou 0 si demandé par le drapeau correspondant)
			flags.width = ft_manage_width(str, i, flags);
		if (str[i] == '.')													//Un point qui sépare la largeur du champ de la précision désirée (pour les flottants)
		if (/*Un nombre, la précision, qui donne
			soit le nombre maximum de caractères d'une chaîne à  imprimer,
			soit le nombre de chiffres à  imprimer à  droite du point décimal pour e, E et f,
			soit le nombre de chiffres significatifs pour g et G,
			soit le nombre minimum de chiffres à  imprimer pour un entier (des 0 seront rajoutés en tête pour remplir le champ).*/
			//. : init a -1. se compose d’un point ( . ) suivi d’un entier décimal non négatif qui, selon le type de conversion, spécifie le nombre de caractères de chaîne, le nombre de décimales ou le nombre de chiffres significatifs à générer
        	//Contrairement à la spécification de largeur, la spécification de précision peut entraîner la troncation de la valeur de sortie ou l’arrondi d’une valeur à virgule flottante. Si vous spécifiez 0 comme precision et que la valeur à convertir est 0, vous n’obtenez aucune sortie de caractères, comme illustré dans cet exemple : printf( "%.0d", 0 ); /* No characters output */
		if (str[i] == 'h' || str[i] == 'l')									//gerent aussi ll et hh. modifient la largeur du champ. h pour un argument short (ou unsigned short), l pour long  (ou unsigned long)
			flags.width_lh = ft_manage_lh();
		if (str[i] == '*')													//On peut spécifier la largeur et/ou la précision par *, auquel cas la valeur est calculée en convertissant le ou les argument(s) suivant(s), qui doi(ven)t être de type int.  Si la spécification de la largeur ou de la precision est un astérisque (*), un argument int issu de la liste d’arguments fournit la valeur. L’argument width doit précéder la valeur mise en forme dans la liste des arguments, comme illustré dans l’exemple suivant : printf("%0*d", 5, 3); /* 00003 is output */ Une valeur width manquante ou petite dans une spécification de conversion n’entraîne pas la troncation d’une valeur de sortie. Si le résultat d’une conversion est plus large que la valeur width , le champ peut être développé pour contenir le résultat de la conversion.
			break ;
		i++;
	}
	return (flags);
}