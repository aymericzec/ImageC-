/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : classe d�crivant une ligne dans une hi�rachie de figures
 */

#ifndef __LIGNE__
#define __LIGNE__
#include "Shape.hpp"

class Line: public Figure {


public:
    static Ligne temoin;

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

    virtual void translation(const Point & p);
	virtual void homothety(const Point & p);
	virtual void rotation(const double radius);
	virtual void centralSymmetry (initializer_list<Point> & p);
	virtual void axialSymmetryX(initializer_list<Point> & p);
	virtual void axialSymmetryY(initializer_list<Point> & p);

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

