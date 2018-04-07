/**
 * \file Line.cpp
 * \brief Implementation d'une ligne
 * \author MOREAU.A ZECCHINI.A VIERIA_NORO.K
 * \version 0.1
 * \date 13 mars 2018
 *
 * Impl�m�ntation d'une classe d�crivant une ligne dans une hi�rachie de figures.
 *
 */
 
#include <cmath>
#include "Line.hpp"
#include <list>
#include "Matrice2D.hpp"
#include <MLV/MLV_all.h>
#include "Shapes.hpp"

using namespace enumShapes;

list<Point *> Line::getPoints() {
	return {&_origine, &_extremite};
}

/**
 * La ligne t�moin est une variable de classe
 */
Line Line::temoin = Line(Point(0,0), Point(1,1));

/**
 * Fonction virtuelle de copie
 */
shared_ptr<Shape> Line::copy() const
{
	return make_shared<Line>(*this);
    //return new Line(this->_origine, this->_extremite);
}

Point Line::getBegin() const
{
	return _origine;
}

Point Line::getExtremity() const
{
	return _extremite;
}

void Line::drawMLV() const
{
    MLV_draw_line(_origine.getX(), _origine.getY(), _extremite.getX(), _extremite.getY(),  MLV_COLOR_YELLOW); 		
}

void Line::print(ostream & os) const
{
    os << "Ligne (" << _origine << ", " << _extremite << ")" << endl;
}

double Line::surface() const
{
    double distance = sqrt( (_origine.getX() - _extremite.getX()) * (_origine.getX() - _extremite.getX())
                            + (_origine.getY() - _extremite.getY()) * (_origine.getY() - _extremite.getY()));

    const double epaisseur = 1.0;

    return distance * epaisseur;
}

double Line::perimeter() const 
{
	return surface();
}

double Line::origineDistance(const Point & p) const
{
	double distance = sqrt( (_origine.getX() - p.getX()) * (_origine.getX() - p.getX())
                            + (_origine.getY() - p.getY()) * (_origine.getY() - p.getY())); 
                            
    return distance;
}

Shapes Line::getEnum() const 
{
	return Shapes::LINE;
}

Point Line::getOrigin () const {
	int x = (this->_origine.getX() + this->_extremite.getX()) / 2;	
	int y = (this->_origine.getY() + this->_extremite.getY()) / 2;
	return Point(x, y);
}
