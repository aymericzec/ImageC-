#include "Shape.hpp"
#include "Matrice2D.hpp"

ostream & operator<< (ostream & os, const Shape & shape) {
	shape.print(os);
	return os;
}

bool Shape::operator== (const Shape & s) const {
	    return (this == &s);
}

void Shape::translation(const Point & p) {
	list<Point *> points = this->getPoints();
	Matrice2D::translation(p, points);
}

void Shape::homothety (const Point & p) {
	list<Point *> points = this->getPoints();
	Matrice2D::homothety(p, points);
}

void Shape::rotation (const double radius) {
	list<Point *> points = this->getPoints();
	Matrice2D::rotation(radius, points);
}

void Shape::centralSymmetry () {
	list<Point *> points = this->getPoints();
	Matrice2D::centralSymmetry(points);
}
void Shape::axialSymmetryX () {
	list<Point *> points = this->getPoints();
	Matrice2D::axialSymmetryX(points);
}

void Shape::axialSymmetryY () {
	list<Point *> points = this->getPoints();
	Matrice2D::axialSymmetryY(points);
}
