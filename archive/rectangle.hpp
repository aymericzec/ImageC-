#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.hpp"

using namespace std;

class Rectangle : public Figure {

public:
	static Rectangle temoin;
	
	Rectangle(const Point & a, const Point & b): _A(a), _B(b), _C(), _D() 
	{ 
		_C.setX(_A.getX());
		_C.setY(_B.getY());
		_D.setX(_B.getX());
		_D.setY(_A.getY());
	}
	
	Point getA() const;
	Point getB() const;
	Point getC() const;
	Point getD() const;
		
	virtual Figure * copy() const;

    virtual ~Rectangle() { }
    
    virtual list<Point *> getPoints() const;

	virtual void deplacer(const Point & trans);
	virtual void dessiner(ostream & os = cout) const;
    virtual double surface() const;
    virtual double perimetre() const;
    virtual double distance_origine(const Point & p) const;
    virtual void afficher(ostream & os = cout) const;
    
private:
	Point _A; //Point origine en bas à gauche
	Point _B; //Point en haut à droite
	Point _C; //Point en haut à gauche
	Point _D; //Point en bas à droite
};


#endif
