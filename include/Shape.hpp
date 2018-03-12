/**
 * auteurs          : Zecchini Aymeric
 * mail             : zecchini.aymeric@gmail.com
 * date de création : 12/03/2018
 * description      : classe abstraite de base d'une hiérarchie de figures
 */

#ifndef __SHAPE__
#define __SHAPE__
#include <iostream>
#include "Point.hpp"
#include <list>

using namespace std;

// classe abstraite représentant une figure
class Shape {

public:
    /**
     * Il est impossible de rendre les constructeurs de copie virtuels.
     * Par suite, une fonction virtuelle de copy est définie qui permet
     * la simulation de constructeurs virtuels.
     */
    virtual Shape * copy() const = 0;
    virtual ~Shape() { };
    
    virtual void translation(const Point & p);
	virtual void homothety(const Point & p);
	virtual void rotation(const double radius);
	virtual void centralSymmetry (initializer_list<Point> & p);
	virtual void axialSymmetryX(initializer_list<Point> & p);
	virtual void axialSymmetryY(initializer_list<Point> & p);
	
	virtual void draw (ostream & os = cout) const = 0;
    virtual void print(ostream & os) const = 0;

    virtual double surface() const = 0;
    virtual double perimeter() const = 0;
    virtual double origineDistance(const Point & p) const = 0;

	bool operator== (const Shape & f) const;


    friend ostream & operator<< (ostream & os, const Shape & shape);
};



#endif
