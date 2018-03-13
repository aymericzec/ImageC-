#ifndef __MATRICE2D__
#define __MATRICE2D__
#include <iostream>
#include <list>
#include "Point.hpp"

using namespace std;

class Matrice2D {
private:
	friend void mulMatrice(double matrice [][2], Point & p);
	
public:
	virtual ~Matrice2D() { };
	
	static void translation(const Point & p, list<Point *> & points);
	static void homothety(const Point & p, list<Point *> & points);
	static void rotation(const double angle, list<Point *> & points);
	static void axialSymmetryX(list<Point *> & points);
	static void axialSymmetryY(list<Point *> & points);
	static void centralSymmetry(list<Point *> & points);
};



#endif
