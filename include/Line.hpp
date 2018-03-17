/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant une ligne dans une hiérachie de figures
 */

#ifndef __LIGNE__
#define __LIGNE__
#include "Shape.hpp"
#include "Shapes.hpp"

using namespace enumShapes;

class Line : public Shape {

private:
	virtual list<Point *> getPoints();

public:
    static Line temoin;

	Line(const Point & a , const Point & b, const Point & originImage)
        : _origine(a), _extremite(b), _originImage(originImage) { }
    
/**
 * \fn virtual Line * copy() const;
 * \brief Fonction virtuelle de copie
 *
 * \param 
 * \return Line *.
 */
    virtual shared_ptr<Shape> copy() const;
    virtual ~Line () { };
    
    Point getOrigin() const;
    Point getExtremity() const;
    
    virtual Point getOriginImage() const;

	virtual void draw(ostream & os = cout) const;
	virtual void drawMLV() const;
	virtual void print(ostream & os = cout) const;
	
    virtual double surface() const;
    virtual double perimeter() const;
    virtual double origineDistance(const Point & p) const;
    
    virtual Shapes getEnum() const;
    

private:
	Point _origine;
	Point _extremite;
	Point _originImage;
};
#endif

