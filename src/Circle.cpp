

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

/**
 * Le dessin se limite à un affichage
 */
void Circle::draw(ostream & os) const
{
    os << *this << endl;;
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

Point Circle::getOriginImage() const
{
	return _originImage;
}

Shapes Circle::getEnum() const 
{
	return Shapes::CIRCLE;
}

