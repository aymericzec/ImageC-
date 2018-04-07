/**
 * \file Rectangle.cpp
 * \brief Implémentation d'une classe représentant un Rectangle
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Rectangle.
 *
 */
#include <cmath>
#include "Rectangle.hpp"
#include <list>
#include <MLV/MLV_all.h>
#include "Shapes.hpp"

using namespace enumShapes;

/**
 * Le rectangle témoin est une variable de classe
 */
Rectangle Rectangle::temoin = Rectangle(Point(0,0), Point(2,2));

list<Point *> Rectangle::getPoints() {
	return {&_A, &_B, &_C, &_D};
}


Point Rectangle::getA() const
{
	return _A;
}

Point Rectangle::getB() const
{
	return _B;
}

Point Rectangle::getC() const
{
	return _C;
}

Point Rectangle::getD() const
{
	return _D;
}

/**
 * Fonction virtuelle de copie
 */
shared_ptr<Shape> Rectangle::copy() const
{
	return make_shared<Rectangle>(*this);
}


void Rectangle::drawMLV() const
{
    int vx [] = {_A.getX(), _B.getX(), _D.getX(), _C.getX()};
	int vy [] = {_A.getY(), _B.getY(), _D.getY(), _C.getY()};
	
	MLV_draw_polygon(vx, vy, 4, MLV_COLOR_BLUE); 		
}

/**
 * Calcul de la surface d'un rectangle
 */
double Rectangle::surface() const
{
	//Calcul des distances des deux cotés du rectangle
	double l = sqrt((_C.getX() - _A.getX()) * (_C.getX() - _A.getX())
					+ (_C.getY() - _A.getY()) * (_C.getY() - _A.getY()));
					
	double L = sqrt((_B.getX() - _C.getX()) * (_B.getX() - _C.getX())
					+ (_B.getY() - _C.getY()) * (_B.getY() - _C.getY()));
					
	return l * L;	
}

double Rectangle::perimeter() const 
{
	double l = sqrt((_C.getX() - _A.getX()) * (_C.getX() - _A.getX())
					+ (_C.getY() - _A.getY()) * (_C.getY() - _A.getY()));
					
	double L = sqrt((_B.getX() - _C.getX()) * (_B.getX() - _C.getX())
					+ (_B.getY() - _C.getY()) * (_B.getY() - _C.getY()));
					
	return (2 * l) + (2 * L);
}

double Rectangle::origineDistance(const Point & p) const
{
	double distance = sqrt( (_A.getX() - p.getX()) * (_A.getX() - p.getX())
                            + (_A.getY() - p.getY()) * (_A.getY() - p.getY())); 
                            
    return distance;
}

void Rectangle::print(ostream & os) const
{
    os << "rectangle (" << _A << ", " << _B << ", " << _C << ", " << _D << ")" << " Perimetre: " << this->perimeter() << endl;
}

Shapes Rectangle::getEnum() const 
{
	return Shapes::RECTANGLE;
}

Point Rectangle::getOrigin () const {
	int x = (this->_A.getX() + this->_D.getX()) / 2;
	int y = (this->_A.getY() + this->_D.getY()) / 2;
	return Point(x, y);
}
