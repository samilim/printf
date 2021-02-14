
#include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_manage_conversions(const char *str, int i)
{
	//int count;

	//count = 0;
	/*voir https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/printf_form.html*/

	if (str[i] == 'c') //prend un unsigned char, prend les char d'espacement en compte
		ft_putchar_fd(va_arg(args, unsigned char), 1);
	if (str[i] == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (str[i] == 'p') //print un ptr, prend donc un void *
		ft_putaddr_fd(va_args(args, void *), 1); //ft wip
	if (str[i] == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (str[i] == 'i')
		//same que %d ou bien nuancer avec hexa / octa?
	if (str[i] == 'u')
		//putnbr si int positif (même au delà de 255), si negatif affiche wtf)
	if (str[i] == 'x' || str[i] == 'X')
		ft_puthex_fd(va_arg(args, int), 1); //ft à faire, affiche l'hexa en min ou maj
/*BONUS*/	
	if (str[i] == 'n')
		//Ecrit dans l'argument, le nombre de caractères écrits jusque là par printf. Ne convertit pas d'arguments
	if (str[i] == 'f')
		//prend un double, gère les floats.  [-]mmm.ddd, où le nombre de d est donné par la précision (6 par défaut). Si la précision vaut 0, le point décimal est supprimé
	if (str[i] == 'e')
		// same que f mais format [-]mmm.ddde+/-xx
	if (str[i] == 'g')
		// Format %e ou %E si l'exposant est < -4 ou >= la précision, suivant %f sinon. Les 0 ou le point décimal à la fin du nombre ne sont pas imprimés
	if (str[i] == '%')
		ft_putchar_fd('%', 1);
	// + conversion o?
	//return (count); 
}





int	ft_manage_flags(char *str, int i)
{
	//% [ indicateurs] [ largeur] [. précision] [ taille] type
	//Entre % et le spécificateur de format on peut placer, dans l'ordre
	int	count;

	count = 0;
	if (str[i] == '-') // cadre l'argument converti à gauche
	if (str[i] == '+') //BONUS; imprime systématiquement le signe du nombre
		   //check si (check si va_arg int est pos ou neg et afficher le signe adéquat
	if (str[i] = ' ') // si le premier caractère n'est pas un signe, place un espace au début
	if (str[i] == '0') //pour les conversions numériques complète le début du champ par des 0
	if (str[i] == '#') /*spécifie un format de sortie différent :
		pour o, le premier chiffre sera 0,
		pour x ou X,  0x ou 0X sera ajouté si le résultat est non nul,
		pour e,E,f,g,et G, la sortie comportera toujours un point décimal,
		pour g et G, les 0 de terminaison seront conservés.*/
	if (str[i] == //Un nombre qui précise la largeur minimum du champ d'impression (complété si nécessaire par des espaces ou 0 si demandé par le drapeau correspondant)
	if (str[i] == '.') //Un point qui sépare la largeur du champ de la précision désirée (pour les flottants)
	if ( /*Un nombre, la précision, qui donne
		soit le nombre maximum de caractères d'une chaîne à  imprimer,
		soit le nombre de chiffres à  imprimer à  droite du point décimal pour e, E et f,
		soit le nombre de chiffres significatifs pour g et G,
		soit le nombre minimum de chiffres à  imprimer pour un entier (des 0 seront rajoutés en tête pour remplir le champ).*/
	if (str[i] == /*Une lettre h, l ou L, qui modifie la largeur du champ. h pour un argument short (ou unsigned short), l pour long  (ou unsigned long) et L pour long double*/
	if (str[i] == '*') //On peut spécifier la largeur et/ou la précision par *, auquel cas la valeur est calculée en convertissant le ou les argument(s) suivant(s), qui doi(ven)t être de type int
	return (count);

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
