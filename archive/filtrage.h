/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe de filtrage des figures satisfaisant une condition
 */

#ifndef FILTRAGE_H
#define FILTRAGE_H
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <list>
#include "figure.hpp"
#include "condition.h"

using namespace std;

class Filtrage
{
public:
    static void remplitAlea(list<int> entiers, int n);
    static int compterSi(list<const Figure *> figures, Condition * condition, bool test);
    static bool supprimerSi(list<const Figure *> & figures, Condition * condition);
    static bool supprimerSiBis(list<const Figure *> & figures, Condition * condition);
    static bool supprimerSiProfond(list<const Figure *> & figures, Condition * condition);
    static bool supprimerSiProfondBis(list<const Figure *> & figures, Condition * condition);
    static Figure * getUneFigure(int x, int y);
    static list<const Figure *> creerFigures(int n);
};

#endif
