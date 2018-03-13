/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant une ligne dans une hiérachie de figures
 */

#ifndef __LIGNE__
#define __LIGNE__
#include "Shape.hpp"

class Line : public Shape {

private:
	virtual list<Point *> getPoints();

public:
    static Line temoin;

	Line(const Point & a , const Point & b)
        : _origine(a), _extremite(b) { }
    
/**
 * \fn virtual Line * copy() const;
 * \brief Fonction virtuelle de copie
 *
 * \param 
 * \return Line *.
 */
    virtual Line * copy() const;
    virtual ~Line () { };
    
    Point getOrigin() const;
    Point getExtremity() const;

	virtual void draw(ostream & os = cout) const;
	virtual void print(ostream & os = cout) const;
	
    virtual double surface() const;
    virtual double perimeter() const;
    virtual double origineDistance(const Point & p) const;
    

private:
	Point _origine;
	Point _extremite;
};
#endif

