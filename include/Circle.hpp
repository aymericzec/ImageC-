/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant un cercle dans une hiérachie de figures
 */

#ifndef __CIRCLE__
#define __CIRCLE__
#include "Shape.hpp"

using namespace std;

class Circle: public Shape
{
	
private:
	virtual list<Point *> getPoints();
	
public:
    static Circle temoin;

    Circle(const Point & center = Point(0,0), const Point & radius = Point(0,0), const Point & originImage = Point(0,0))
        : _center(center), _radius(radius), _originImage(originImage) { }
        
    Point getCenter() const;
    double getRadius() const;
    virtual Point getOriginImage() const;

    virtual shared_ptr<Shape> copy() const;

    virtual ~Circle() { }

    virtual void draw(ostream & os = cout) const;
    virtual void drawMLV() const;
    virtual double surface() const;
    virtual double perimeter() const;
    virtual double origineDistance(const Point & p) const;
    virtual void print(ostream & os = cout) const;
	
private:
    Point _center;
    Point _radius;
    Point _originImage;
};
#endif
