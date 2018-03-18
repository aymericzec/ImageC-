#ifndef __TRIANGLE__
#define __TRIANGLE__
#include "Shape.hpp"
#include "Shapes.hpp"

using namespace enumShapes;
using namespace std;

class Triangle : public Shape {
private:
	virtual list<Point *> getPoints() override;
	
public:
	static Triangle temoin;
	
	Triangle(const Point & a, const Point & b, const Point & c, const Point & originImage)
		: _A(a), _B(b), _C(c), _originImage(originImage)  { }
		
	Point getA() const;
	Point getB() const;
	Point getC() const;
		
	virtual shared_ptr<Shape> copy() const override;

    virtual ~Triangle() { }
    
    
    virtual Point getOriginImage() const override;

	virtual void draw(ostream & os = cout) const override;
	virtual void drawMLV() const override;
    virtual double surface() const override;
    virtual double perimeter() const override;
    virtual double origineDistance(const Point & p) const override;
    virtual void print(ostream & os = cout) const override;
    virtual Shapes getEnum() const override;

private:
	Point _A; //Point origine celui à gauche
	Point _B; //Point à droite
	Point _C; //Point en haut
	Point _originImage;
};


#endif
