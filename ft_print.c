
int		ft_printf(const char *, ...)
{
}



/*

DOC
man 3 printf / man 3 stdarg

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
• Gérez tous les flags suivants : ’# +’ (oui espace est un flag valide)*/
