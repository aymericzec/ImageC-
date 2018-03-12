#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.hpp"

using namespace std;

class Triangle : public Figure {
	
public:
	static Triangle temoin;
	
	Triangle(const Point & a, const Point & b, const Point & c)
		: _A(a), _B(b), _C(c) { }
		
	Point getA() const;
	Point getB() const;
	Point getC() const;
		
	virtual Figure * copy() const;

    virtual ~Triangle() { }
    
    virtual list<Point *> getPoints() const;

	virtual void deplacer(const Point & trans);
	virtual void dessiner(ostream & os = cout) const;
    virtual double surface() const;
    virtual double perimetre() const;
    virtual double distance_origine(const Point & p) const;
    virtual void afficher(ostream & os = cout) const;

private:
	Point _A; //Point origine celui à gauche
	Point _B; //Point à droite
	Point _C; //Point en haut
};


#endif
