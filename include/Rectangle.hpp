#ifndef __RECTANGLE__
#define __RECTANGLE__
#include "Shape.hpp"
#include "Shapes.hpp"
#include <list>

using namespace std;
using namespace enumShapes;

class Rectangle : public Shape {

private:
	virtual list<Point *> getPoints() override;

public:
	static Rectangle temoin;
	
	Rectangle(const Point & a, const Point & b, const Point & originImage  = Point(0,0)): _A(a), _D(b), _originImage(originImage), _B(), _C() 
	{ 
		_B.setX(_D.getX());
		_B.setY(_A.getY());
		_C.setX(_A.getX());
		_C.setY(_D.getY());
	}
	
	Point getA() const;
	Point getB() const;
	Point getC() const;
	Point getD() const;
		
	virtual shared_ptr<Shape> copy() const override;
    virtual ~Rectangle() { }
   

    virtual Point getOriginImage() const override;

	virtual void draw(ostream & os = cout) const override;
	virtual void drawMLV() const override;
	virtual void print(ostream & os = cout) const override;
	
    virtual double surface() const override;
    virtual double perimeter() const override;
    virtual double origineDistance(const Point & p) const override;
    
    virtual Shapes getEnum() const override;
    
private:
	Point _A; //Point en haut à gauche
	Point _D; //Point en bas à droite
	Point _originImage;
	Point _B; //Point en haut à droite
	Point _C; //Point en bas à gauche
};


#endif
