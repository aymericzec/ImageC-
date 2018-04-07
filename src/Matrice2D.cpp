/**
 * \file Matrice2D.cpp
 * \brief Implémentation d'une classe représentant des transformations sur des figures.
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter des transformations geometriques.
 *
 */
#include "Matrice2D.hpp"
#include <cmath>
#include <list>
#include "Line.hpp"
#include "Point.hpp"


void mulMatrice(double matrice [][2], Point & p)
{
	double result[2][1];
	
	result[0][0] = matrice[0][0] * p.getX() + matrice[0][1] * p.getY();
	result[1][0] = matrice[1][0] * p.getX() + matrice[1][1] * p.getY();
	
	p.setX(result[0][0]);
	p.setY(result[1][0]);
}

void Matrice2D::translation(const Point & p, list<Point *> & points)
{
	for(auto point : points) 
	{
		point->setX(point->getX() + p.getX());
		point->setY(point->getY() + p.getY());
	}
}

void Matrice2D::homothety(const Point & p, list<Point *> & points)
{
	double matrice[2][2];
	
	matrice[0][0] = p.getX();
	matrice[0][1] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = p.getY();

	for(auto n : points) 
	{
		mulMatrice(matrice, *n);
	}
}

void Matrice2D::rotation(const double angle, list<Point *> & points)
{
	double matrice[2][2];
	
	matrice[0][0] = cos(angle);
	matrice[0][1] = -sin(angle);
	matrice[1][0] = sin(angle);
	matrice[1][1] = cos(angle);
	
	for(auto n : points) 
	{
		mulMatrice(matrice, *n);
	}
}

void Matrice2D::axialSymmetryX(list<Point *> & points)
{
	double matrice[2][2];
	
	matrice[0][0] = 1;
	matrice[0][1] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = -1;
	
	for(auto n : points) 
	{
		mulMatrice(matrice, *n);
	}
}

void Matrice2D::axialSymmetryY(list<Point *> & points)
{
	double matrice[2][2];
	
	matrice[0][0] = -1;
	matrice[0][1] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = 1;
	
	for(auto n : points) 
	{
		mulMatrice(matrice, *n);
	}
}

void Matrice2D::centralSymmetry(list<Point *> & points)
{
	double matrice[2][2];
	
	matrice[0][0] = -1;
	matrice[0][1] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = -1;
	
	for(auto n : points) 
	{
		mulMatrice(matrice, *n);
	}
}
