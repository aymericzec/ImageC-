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
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - this->getOriginImage().getX());
		n->setY(n->getY() - this->getOriginImage().getY());
	}
	
	Matrice2D::homothety(p, points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + this->getOriginImage().getX());
		n->setY(n->getY() + this->getOriginImage().getY());
	}
}

void Shape::rotation (const double radius) {
	list<Point *> points = this->getPoints();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - this->getOriginImage().getX());
		n->setY(n->getY() - this->getOriginImage().getY());
	}
	
	Matrice2D::rotation(radius, points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + this->getOriginImage().getX());
		n->setY(n->getY() + this->getOriginImage().getY());
	}
}

void Shape::centralSymmetry () {
	list<Point *> points = this->getPoints();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - this->getOriginImage().getX());
		n->setY(n->getY() - this->getOriginImage().getY());
	}
	
	Matrice2D::centralSymmetry(points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + this->getOriginImage().getX());
		n->setY(n->getY() + this->getOriginImage().getY());
	}
}

void Shape::axialSymmetryX () {
	
	list<Point *> points = this->getPoints();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - this->getOriginImage().getX());
		n->setY(n->getY() - this->getOriginImage().getY());
	}
	
	Matrice2D::axialSymmetryX(points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + this->getOriginImage().getX());
		n->setY(n->getY() + this->getOriginImage().getY());
	}
}

void Shape::axialSymmetryY () {
	list<Point *> points = this->getPoints();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - this->getOriginImage().getX());
		n->setY(n->getY() - this->getOriginImage().getY());
	}
	
	Matrice2D::axialSymmetryY(points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + this->getOriginImage().getX());
		n->setY(n->getY() + this->getOriginImage().getY());
	}
}
