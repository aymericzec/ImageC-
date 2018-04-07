/**
 * \file Circle.cpp
 * \brief Implémentation de la classe Cercle
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Cercle.
 *
 */
#include "Circle.hpp"
#include "Shapes.hpp"
#include <cmath>
#include <MLV/MLV_all.h>

using namespace enumShapes;

/**
 * Le cercle témoin est une variable de classe
 */
Circle Circle::temoin = Circle(Point(0,0), 0);

Point Circle::getCenter() const
{
	return _center;
}

double Circle::getRadius() const 
{
	return sqrt( (_center.getX() - _radius.getX()) * (_center.getX() - _radius.getX()) + (_center.getY() - _radius.getY()) * (_center.getY() - _radius.getY())); 
}

shared_ptr<Shape> Circle::copy() const
{
	return make_shared<Circle>(*this);
}

list<Point *> Circle::getPoints() {
	return {&_center, &_radius};
}

void Circle::drawMLV() const
{
     MLV_draw_circle(_center.getX(), _center.getY(), this->getRadius(), MLV_COLOR_YELLOW);	
}

double  Circle::surface() const
{
	double r = this->getRadius();
    return 3.1416 * r * r;
}

double Circle::perimeter() const
{
	double r = this->getRadius();
	return 2 * 3.1416 * r;
}

double Circle::origineDistance(const Point & p) const 
{
	double distance = sqrt( (_center.getX() - p.getX()) * (_center.getX() - p.getX())
                            + (_center.getY() - p.getY()) * (_center.getY() - p.getY())); 
                            
    return distance;
}

void Circle::print(ostream & os) const
{
    os << "cercle : (" << _center << ", " << _radius << ")" << " Perimetre: " << this->perimeter() << endl;
}

Shapes Circle::getEnum() const 
{
	return Shapes::CIRCLE;
}

Point Circle::getOrigin () const {
	return this->_center;
}

