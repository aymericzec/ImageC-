/**
 * \file Line.cpp
 * \brief Implementation d'une ligne
 * \author MOREAU.A ZECCHINI.A VIERIA_NORO.K
 * \version 0.1
 * \date 13 mars 2018
 *
 * Impléméntation d'une classe décrivant une ligne dans une hiérachie de figures.
 *
 */
 
#include <cmath>
#include "Line.hpp"
#include <list>
#include "Matrice2D.hpp"

list<Point *> Line::getPoints() {
	return {&_origine};
}

/**
 * La ligne témoin est une variable de classe
 */
Line Line::temoin = Line(Point(0,0), Point(1,1));

/**
 * Fonction virtuelle de copie
 */
Line * Line::copy() const
{
    return new Line(this->_origine, this->_extremite);
}

Point Line::getOrigin() const
{
	return _origine;
}

Point Line::getExtremity() const
{
	return _extremite;
}

/**
 * Le dessin se limite à un affichage
 */
void Line::draw(ostream & os) const
{
    os << *this << endl;;
}

void Line::print(ostream & os) const
{
    os << "Ligne (" << _origine << ", " << _extremite << ")" << endl;
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

double Line::perimeter() const 
{
	return surface();
}

double Line::origineDistance(const Point & p) const
{
	double distance = sqrt( (_origine.getX() - p.getX()) * (_origine.getX() - p.getX())
                            + (_origine.getY() - p.getY()) * (_origine.getY() - p.getY())); 
                            
    return distance;
}


