/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : impléméntation d'une classe de filtrage des figures satisfaisant une condition
 */

#include <algorithm>
#include <iostream>
#include "Shape.hpp"
#include "Filter.hpp"
#include "Image.hpp"
#include "Line.hpp"

using namespace std;

/**
 * Le foncteur du container
 */
extern void print(Shape & shape);

/**
 * Retourne une figure aléatoire
 */
shared_ptr<Shape> Filter::getShape(int x, int y)
{
    int n = rand()% 3;
    switch(n)
    {
   /* case 0:
        return new Cercle(Point(x,y),rand()% 2000);*/
    case 1:
        return std::make_shared<Line>(new Line(Point(x,y),Point(rand()%2000, rand()%2000)));
   /* case 2:
        return new Image(Point(x,y));*/
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
list<shared_ptr<const Shape>> Filter::createShape(int n)
{
    list<shared_ptr<const Shape>> shapes = list<shared_ptr<const Shape>>();

    srand (time(NULL));
    for(int i = 0 ; i < n ; i++)
        shapes.push_back(getShape(10 * i, 10 * i));

    return shapes;
}


//Trier
void Methode private trier (list &, function)

void Methode triePerimetre(list &) -> trier (list, lambda bool true)
void Trier aire (list & , trier (list, function))
void rier distance (list& , trier (list, function))

//Rechercher
private list search(list, lamba);
public searchShape (list, typeid)
public searchPertimeter (list, double)

//count
private count (list, lamba)
public countShape (list, typeid)
countPerimeter(list, typeid)

//delete Supprimer Image si plus de figure
private delete (list, lamba)
public deleteShape (list, typeid)
countPerimeter(list, typeid)

countFigure(list, type)

/**
 * retourne le nombre de figures d'une liste de figures vérifiant la condition
 */
int Filter::countIf(list<shared_ptr<const Shape>> shapes, Condition * condition, bool test)
{
    int compteur = 0;

    /**
     * FOREACH ITERATORS
     */
    /*list<cshared_ptr<const Shape>>::const_iterator it(shapes.begin());
    list<shared_ptr<const Shape>>::const_iterator end(shapes.end());

    for( ; it != end; ++it)
    {
        if(condition->verif(*it) == test)
            compteur++;
    }*/
    return compteur;
}

bool Filter::deleteIf(list<shared_ptr<const Shape>> & figures, Condition * condition)
{
    bool flag = false;

    if (figures.empty() == true)
        return true;

    /**
     * FOREACH ITERATORS
     */
    
    return flag;
}
/*
//list<const Figure *>::iterator it(figures.begin());
    //list<const Figure *>::const_iterator end(figures.end());
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
            **
             * succès du dynamic-cast : on a une image
             *
            if (image != 0)
            {
                list<const Figure *> figuresImage = list<const Figure *>();
                for (int i = 0; i < image->getNombre(); i++)
                {
                    figuresImage.push_back(image->getFigure(i));
                }

                flag = Filtrage::supprimerSiProfondBis(figuresImage, condition);

                **
                 * suppression de l'image
                 *
                it = figures.erase(it);

                **
                 * Insertion des figures de l'image qui ne satisfont pas la condition
                 * dans une nouvelle image
                 * Puis insertion de cette nouvelle image dans la liste des figures.
                 *
                Image * nouvelle = new Image();
                list<const Figure *>::const_iterator it2 (figuresImage.begin());
                list<const Figure *>::const_iterator end2 (figuresImage.end());
                for( ; it2 != end2; ++it2)
                    nouvelle->ajouter(**it2);
                **
                 * insertion en tête afin d'éviter que l'itérateur devienne incohérent
                 *
                figures.push_front(nouvelle);
            }
            else
                ++it;
        }
    }*/
