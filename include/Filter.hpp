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
#include <functional>
#include "Shape.hpp"
//#include "Condition.hpp"

using namespace std;

class Filter
{
	
private: 
	static void sortShapes(list<shared_ptr<Shape>> & shapes, function<bool(const shared_ptr<Shape> &, const shared_ptr<Shape> &)> f);

public:
	static void sortPerimeter(list<shared_ptr<Shape>> & shapes, bool increase = true);
	bool sortSurface(Shape & shape1, Shape & shape2, bool asc = true, Point p = Point(0,0));
	bool sortDistance(Shape & shape1, Shape & shape2, bool asc = true, Point p = Point(0,0));
	
	list<shared_ptr<Shape>> searchShape(list<shared_ptr<Shape>> & shapes, Shape * shape);
	list<shared_ptr<Shape>> searchPerimeter(list<shared_ptr<Shape>> & shapes, const double perimeter);


    /*static void remplitAlea(list<int> entiers, int n);
    static int countIf(list<shared_ptr<const Shape>> figures, Condition * condition, bool test);
    static bool deleteIf(list<shared_ptr<const Shape>> & figures, Condition * condition);
    static shared_ptr<Shape> getShape(int x, int y);
    static list<shared_ptr<const Shape>> createShape(int n);*/
};

#endif
