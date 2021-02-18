#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct 	s_flags
{
//INDICATEURS
    int minus; // -chiffre completera jusqu'a width avec des ' '  0 annulé par -. Compatible avec s
    int sign; //+ : imprime systématiquement le signe du nombre. BONUS
	int zero; ///pour les conversions numériques complète le début du champ par des 0. Annulé par -
    int space; //si le premier caractère n'est pas un signe, place un espace au début. BONUS
    int prefix; //BONUS # : compatible avec conv gefxX
//LARGEUR
    unsigned int width; //controle le nb minimal de caracteres affches
    unsigned int width_spec; //* Si la spécification de la largeur ou de la precision est un astérisque (*), un argument int issu de la liste d’arguments fournit la valeur. L’argument width doit précéder la valeur mise en forme dans la liste des arguments, comme illustré dans l’exemple suivant : printf("%0*d", 5, 3); /* 00003 is output */
        //Une valeur width manquante ou petite dans une spécification de conversion n’entraîne pas la troncation d’une valeur de sortie. Si le résultat d’une conversion est plus large que la valeur width , le champ peut être développé pour contenir le résultat de la conversion.
//PRECISION
    int precision; //. : init a -1. se compose d’un point ( . ) suivi d’un entier décimal non négatif qui, selon le type de conversion, spécifie le nombre de caractères de chaîne, le nombre de décimales ou le nombre de chiffres significatifs à générer
        //Contrairement à la spécification de largeur, la spécification de précision peut entraîner la troncation de la valeur de sortie ou l’arrondi d’une valeur à virgule flottante. Si vous spécifiez 0 comme precision et que la valeur à convertir est 0, vous n’obtenez aucune sortie de caractères, comme illustré dans cet exemple : printf( "%.0d", 0 ); /* No characters output */
    int precision_spec;
//BONUS
    int //l 
    int //ll 
    int //h
    int //hh

}		        t_flags;

int				ft_printf(const char *str, ...);

#endif
