#ifndef __TRIANGLE__
#define __TRIANGLE__
#include "Shape.hpp"

using namespace std;

class Triangle : public Shape {
private:
	virtual list<Point *> getPoints();
	
public:
	static Triangle temoin;
	
	Triangle(const Point & a, const Point & b, const Point & c, const Point & originImage)
		: _A(a), _B(b), _C(c), _originImage(originImage)  { }
		
	Point getA() const;
	Point getB() const;
	Point getC() const;
		
	virtual shared_ptr<Shape> copy() const;

    virtual ~Triangle() { }
    
    
    virtual Point getOriginImage() const;

	virtual void draw(ostream & os = cout) const;
	virtual void drawMLV() const;
    virtual double surface() const;
    virtual double perimeter() const;
    virtual double origineDistance(const Point & p) const;
    virtual void print(ostream & os = cout) const;

private:
	Point _A; //Point origine celui à gauche
	Point _B; //Point à droite
	Point _C; //Point en haut
	Point _originImage;
};


#endif
