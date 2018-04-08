
Pour installer Doxygene :
	sudo apt-get install graphviz doxygen doxygen-gui

graphviz permet la génération graphique
doxygen-gui est l'interface graphique

Lancement :
	doxywizard





En haut de chaque fichier
/**
 * \file main.c
 * \brief Programme de tests.
 * \author Franck.H
 * \version 0.1
 * \date 11 septembre 2007
 *
 * Programme de test pour l'objet de gestion des chaînes de caractères Str_t.
 *
 */


Pour une fonction

/**
 * \fn static Str_t * str_new (const char * sz)
 * \brief Fonction de création d'une nouvelle instance d'un objet Str_t.
 *
 * \param sz Chaîne à stocker dans l'objet Str_t, ne peut être NULL.
 * \return Instance nouvellement allouée d'un objet de type Str_t ou NULL.
 */


Pour une structure
/**
 * \struct Str_t
 * \brief Objet chaîne de caractères.
 *
 * Str_t est un petit objet de gestion de chaînes de caractères. 
 * La chaîne se termine obligatoirement par un zéro de fin et l'objet 
 * connait la taille de chaîne contient !
 */



Pour un enum 
/**
 * \enum Str_err_e
 * \brief Constantes d'erreurs.
 *
 * Str_err_e est une série de constantes prédéfinie pour diverses futures 
 * fonctions de l'objet Str_t.
 */


