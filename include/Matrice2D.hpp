#ifndef __MATRICE2D__
#define __MATRICE2D__
#include <iostream>
#include "point.hpp"
#include "figure.hpp"

using namespace std;

extern void translation(const Point & p, Figure & figure);
extern void homothetie(const Point & p, Figure & figure);

class Matrice2D {
private:
	void mulMatrice(double matrice [][2], const Point & p);
public:

	virtual ~Matrice2D() { };
	
	friend void translation(const Point & p, Figure & figure);
	friend void homothety(const Point & p, Figure & figure);
	friend void rotation(const double angle, initializer_list<Point> & p);
	friend void axialSymmetryX(initializer_list<Point> & p);
	friend void axialSymmetryY(initializer_list<Point> & p);
	friend void centralSymmetry(initializer_list<Point> & p);
	
};



#endif
