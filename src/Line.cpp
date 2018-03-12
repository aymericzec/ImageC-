/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : impléméntation d'une classe décrivant une ligne dans une hiérachie de figures
 */

#include <cmath>
#include "Line.hpp"

/**
 * La ligne témoin est une variable de classe
 */
Line Line::temoin = Line(Point(0,0), Point(1,1));

Point Line::getOrigin() const
{
	return _origine;
}

Point Line::getExtremity() const
{
	return _extremite;
}

/**
 * Fonction virtuelle de copie
 */
Figure * Line::copy() const
{
    return new Line(this->_origine, this->_extremite);
}

/**
 * Déplacement-translation de valeur le point p
 */
void Line::translation(const Point & p)
{
    _origine += p;
    _extremite += p;
}

/**
 * Le dessin se limite à un affichage
 */
void Line::dessiner(ostream & os) const
{
    os << *this << endl;;
}

/**
 * TOUR DE MAGIE GEOMETRIQUE
 * une ligne est vue pour les besoins de la cause comme
 * une segment (origine, exptremite] avec une épaisseur
 * soit un rectangle dont on peut calculer la surfade!!!!
 */
double Line::surface() const
{
    double distance = sqrt( (_origine.getX() - _extremite.getX()) * (_origine.getX() - _extremite.getX())
                            + (_origine.getY() - _extremite.getY()) * (_origine.getY() - _extremite.getY()));

    const double epaisseur = 1.0;

    return distance * epaisseur;
}

double Line::perimetre() const 
{
	return surface();
}

double Line::distance_origine(const Point & p) const
{
	double distance = sqrt( (_origine.getX() - p.getX()) * (_origine.getX() - p.getX())
                            + (_origine.getY() - p.getY()) * (_origine.getY() - p.getY())); 
                            
    return distance;
}

void Line::afficher(ostream & os) const
{
    os << "ligne (" << _origine << ", " << _extremite << ")" << endl;
}
