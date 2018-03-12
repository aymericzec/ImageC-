/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : impl�m�ntation d'une classe d�crivant un cercle dans une hi�rachie de figures
 */

#include "cercle.hpp"
#include <cmath>

/**
 * Le cercle t�moin est une variable de classe
 */
Cercle Cercle::temoin = Cercle(Point(0,0), 0);

Point Cercle::getCentre() const
{
	return _centre;
}

int Cercle::getRayon() const 
{
	return _rayon;
}

/**
 * Fonction virtuelle de copie
 */
Figure * Cercle::copy() const
{
   return new Cercle(this->_centre, this->_rayon);
}

list<Point *> Cercle::getPoints() const
{
	list<Point *> p = {_centre};
	
	return p;
}

/**
 * D�placement-translation de valeur le point p
 */
void Cercle::deplacer(const Point & p)
{
    _centre += p;
}

/**
 * Le dessin se limite � un affichage
 */
void Cercle::dessiner(ostream & os) const
{
    os << *this << endl;;
}

double  Cercle::surface() const
{
    return 3.1416 * _rayon * _rayon;
}

double Cercle::perimetre() const
{
	return 2 * 3.1416 * _rayon;
}

double Cercle::distance_origine(const Point & p) const 
{
	double distance = sqrt( (_centre.getX() - p.getX()) * (_centre.getX() - p.getX())
                            + (_centre.getY() - p.getY()) * (_centre.getY() - p.getY())); 
                            
    return distance;
}

void Cercle::afficher(ostream & os) const
{
    os << "cercle : (" << _centre << ", " << _rayon << ")" << endl;
}

