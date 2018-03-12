#include <cmath>
#include "rectangle.hpp"

/**
 * Le rectangle témoin est une variable de classe
 */
Rectangle Rectangle::temoin = Rectangle(Point(0,0), Point(2,2));

Point Rectangle::getA() const
{
	return _A;
}

Point Rectangle::getB() const
{
	return _B;
}

Point Rectangle::getC() const
{
	return _C;
}

Point Rectangle::getD() const
{
	return _D;
}

/**
 * Fonction virtuelle de copie
 */
Figure * Rectangle::copy() const
{
    return new Rectangle(this->_A, this->_B);
}

list<Point *> Rectangle::getPoints() const
{
	list<Point *> p = {_A, _B, _C, _D};
	
	return p;
}

/**
 * Déplacement-translation de valeur le point p
 */
void Rectangle::deplacer(const Point & p)
{
    _A += p;
    _B += p;
    _C += p;
    _D += p;
}

/**
 * Le dessin se limite à un affichage
 */
void Rectangle::dessiner(ostream & os) const
{
    os << *this << endl;;
}

/**
 * Calcul de la surface d'un rectangle
 */
double Rectangle::surface() const
{
	//Calcul des distances des deux cotés du rectangle
	double l = sqrt((_C.getX() - _A.getX()) * (_C.getX() - _A.getX())
					+ (_C.getY() - _A.getY()) * (_C.getY() - _A.getY()));
					
	double L = sqrt((_B.getX() - _C.getX()) * (_B.getX() - _C.getX())
					+ (_B.getY() - _C.getY()) * (_B.getY() - _C.getY()));
					
	return l * L;	
}

double Rectangle::perimetre() const 
{
	double l = sqrt((_C.getX() - _A.getX()) * (_C.getX() - _A.getX())
					+ (_C.getY() - _A.getY()) * (_C.getY() - _A.getY()));
					
	double L = sqrt((_B.getX() - _C.getX()) * (_B.getX() - _C.getX())
					+ (_B.getY() - _C.getY()) * (_B.getY() - _C.getY()));
					
	return (2 * l) + (2 * L);
}

double Rectangle::distance_origine(const Point & p) const
{
	double distance = sqrt( (_A.getX() - p.getX()) * (_A.getX() - p.getX())
                            + (_A.getY() - p.getY()) * (_A.getY() - p.getY())); 
                            
    return distance;
}

void Rectangle::afficher(ostream & os) const
{
    os << "rectangle (" << _A << ", " << _B << ", " << _C << ", " << _D << ")" << endl;
}
