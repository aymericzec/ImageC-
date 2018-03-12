/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : impléméntation d'une classe de filtrage des figures satisfaisant une condition
 */

#include <algorithm>
#include <iostream>
#include "filtrage.h"
#include "image.hpp"
#include "ligne.hpp"
#include "cercle.hpp"

using namespace std;

/**
 * Le foncteur du container
 */
extern void affiche(Figure * f);

static bool supprimerSiProfondAux(list<const Figure *> & figures,  list<const Figure *> & copy, Condition * condition);

/**
 * Retourne une figure aléatoire
 */
Figure * Filtrage::getUneFigure(int x, int y)
{
    int n = rand()% 3;
    switch(n)
    {
    case 0:
        return new Cercle(Point(x,y),rand()% 2000);
    case 1:
        return new Ligne(Point(x,y),Point(rand()%2000, rand()%2000));
    case 2:
        return new Image(Point(x,y));
    default:
        /**
         *  pointeur nul en C++
         */
        return 0;
    }
}

/**
 * Utilisation de la STL : type list
 * Retourne une liste de figures aléatoires
 */
list<const Figure *> Filtrage::creerFigures(int n)
{
    list<const Figure *> figures = list<const Figure *>();

    srand (time(NULL));
    for(int i = 0 ; i < n ; i++)
        figures.push_back(getUneFigure(10 * i, 10 * i));

    return figures;
}

/**
 * retourne le nombre de figures d'une liste de figures vérifiant la condition
 */
int Filtrage::compterSi(list<const Figure *> figures, Condition * condition, bool test)
{
    int compteur = 0;

    /**
     * FOREACH ITERATORS
     */
    list<const Figure *>::const_iterator it(figures.begin());
    list<const Figure *>::const_iterator end(figures.end());

    for( ; it != end; ++it)
    {
        if(condition->verif(*it) == test)
            compteur++;
    }
    return compteur;
}


/**
 * Suppression superficielle des figures satisfaisant la condition
 * supprime les figures de l'image en les désallouant
 * si la figure est une image alors ses figures sont également désallouées
 * Si une image contient une image alors les figures de cette dernière ne sont pas supprimées.
 * Utilisation de la méthode remove ==> utile de copier la liste pour itérer
 */
bool Filtrage::supprimerSi(list<const Figure *> & figures, Condition * condition)
{
    bool flag = false;

    /**
     *Les conteneurs gèrent leur structure de données de manière dynamique, et sont susceptibles de la réorganiser
     * dès qu’on les manipule. On veillera donc à ne plus utiliser les itérateurs d’un conteneur dès qu’une méthode
     * permettant de le modifier aura été appelée.
     * Ne pas respecter cette règle conduirait, dans le meilleur des cas, à ne pas parcourir complètement
     * l’ensemble des objets du conteneur, et dans le pire des cas, à planter immédiatement le programme
     */

    /**
     * void remove (const value_type& val);
     * The container is modified.
     * The elements removed are modified.
     * Concurrently accessing or modifying other elements is safe,
     * although iterating through the container is not.
     */

    /**
     * ==> création d'une copie de la liste
     * l'itération se fera sur cette copie de liste, et la suppression des éléments sur la liste originale
     *
     *
     * CTOR de copie superficielle des listes de la STL
     */
    list<const Figure *> copy = list<const Figure *>(figures);

    /**
     * FOREACH ITERATORS sur la copie
     */
    list<const Figure *>::const_iterator it(copy.begin());
    list<const Figure *>::const_iterator end(copy.end());

    for( ; it != end; ++it)
    {
        if(condition->verif(*it) == true)
        {
            flag = true;
            /**
             * suppression dans la liste originale
             */
            figures.remove(*it);
        }
    }
    return flag;
}

/**
 * Suppression superficielle des figures satisfaisant la condition
 * supprime les figures de l'image en les désallouant
 * si la figure est une image alors ses figures sont également désallouées
 * Si une image contient une image alors les figures de cette dernière ne sont pas supprimées.
 * Utilisation de la méthode erase ==> inutile de copier la liste pour itérer
 */
bool Filtrage::supprimerSiBis(list<const Figure *> & figures, Condition * condition)
{
    bool flag = false;

    /**
     * FOREACH ITERATORS
     */
    list<const Figure *>::iterator it(figures.begin());
    list<const Figure *>::const_iterator end(figures.end());

    while(it != end)
    {
        if(condition->verif(*it) == true)
        {
            flag = true;
            /**
             * suppression dans la liste originale
             */
            it = figures.erase(it);
        }
        else
            ++it;
    }
    return flag;
}


/**
 * Suppression profonde des figures satisfaisant la condition
 * supprime les figures de l'image en les désallouant
 * si la figure est une image alors ses figures sont également désallouées
 * si une image contient une image alors les figures de cette dernière sont supprimées.
 * Utilisation de la méthode remove ==> utile de copier la liste pour itérer
 */
bool Filtrage::supprimerSiProfond(list<const Figure *> & figures, Condition * condition)
{
    list<const Figure *> copyFigures = list<const Figure *>(figures);
    return supprimerSiProfondAux(figures, copyFigures, condition);
}

bool supprimerSiProfondAux(list<const Figure *> & figures,  list<const Figure *> & copyFigures, Condition * condition)
{
    bool flag = false;

    if (figures.empty() == true)
        return true;

    /**
     * FOREACH ITERATORS sur la copie
     */
    list<const Figure *>::const_iterator it(copyFigures.begin());
    list<const Figure *>::const_iterator end(copyFigures.end());
    for( ; it != end; ++it)
    {
        if(condition->verif(*it) == true)
        {
            flag = true;
            figures.remove(*it);
        }
        else
        {
            const Image * image = dynamic_cast<const Image *>(*it);
            /**
             * succès du dynamic-cast : on a une image
             */
            if (image != 0)
            {
                list<const Figure *> figuresImage = list<const Figure *>();
                for (int i = 0; i < image->getNombre(); i++)
                {
                    figuresImage.push_back(image->getFigure(i));
                }

                flag = Filtrage::supprimerSiProfond(figuresImage, condition);

                /**
                 * suppression de l'image
                 */
                figures.remove(*it);

                /**
                 * Insertion des figures de l'image qui ne satisfont pas la condition
                 * dans une nouvelle image
                 * Puis insertion de cette nouvelle image dans la liste des figures.
                 */
                Image * nouvelle = new Image();
                list<const Figure *>::iterator it2 (figuresImage.begin());
                list<const Figure *>::iterator end2 (figuresImage.end());
                for( ; it2 != end2; ++it2)
                    nouvelle->ajouter(**it2);
                figures.push_back(nouvelle);
            }
        }
    }
    return flag;
}

/**
 * Suppression profonde des figures satisfaisant la condition
 * supprime les figures de l'image en les désallouant
 * si la figure est une image alors ses figures sont également désallouées
 * si une image contient une image alors les figures de cette dernière sont supprimées.
 * Utilisation  de la méthode erase ==> inutile de copier la liste pour itérer
 */
bool Filtrage::supprimerSiProfondBis(list<const Figure *> & figures, Condition * condition)
{
    bool flag = false;

    if (figures.empty() == true)
        return true;

    /**
     * FOREACH ITERATORS
     */
    list<const Figure *>::iterator it(figures.begin());
    list<const Figure *>::const_iterator end(figures.end());
    while(it != end)
    {
        if(condition->verif(*it) == true)
        {
            flag = true;
            it = figures.erase(it);
        }
        else
        {
            const Image * image = dynamic_cast<const Image *>(*it);
            /**
             * succès du dynamic-cast : on a une image
             */
            if (image != 0)
            {
                list<const Figure *> figuresImage = list<const Figure *>();
                for (int i = 0; i < image->getNombre(); i++)
                {
                    figuresImage.push_back(image->getFigure(i));
                }

                flag = Filtrage::supprimerSiProfondBis(figuresImage, condition);

                /**
                 * suppression de l'image
                 */
                it = figures.erase(it);

                /**
                 * Insertion des figures de l'image qui ne satisfont pas la condition
                 * dans une nouvelle image
                 * Puis insertion de cette nouvelle image dans la liste des figures.
                 */
                Image * nouvelle = new Image();
                list<const Figure *>::const_iterator it2 (figuresImage.begin());
                list<const Figure *>::const_iterator end2 (figuresImage.end());
                for( ; it2 != end2; ++it2)
                    nouvelle->ajouter(**it2);
                /**
                 * insertion en tête afin d'éviter que l'itérateur devienne incohérent
                 */
                figures.push_front(nouvelle);
            }
            else
                ++it;
        }
    }
    return flag;
}
