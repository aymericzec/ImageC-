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
#include "Shape.hpp"
#include "Condition.hpp"

using namespace std;

class Filter
{
public:
    static void remplitAlea(list<int> entiers, int n);
    static int countIf(list<shared_ptr<const Shape>> figures, Condition * condition, bool test);
    static bool deleteIf(list<shared_ptr<const Shape>> & figures, Condition * condition);
    static shared_ptr<Shape> getShape(int x, int y);
    static list<shared_ptr<const Shape>> createShape(int n);
};

#endif
