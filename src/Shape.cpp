/**
 * \file Shape.cpp
 * \brief Implementation d'une classe représentant une Figure
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter une Figure.
 *
 */
#include "Shape.hpp"
#include "Matrice2D.hpp"
#include "Shapes.hpp"
#include <string>


ostream & operator<< (ostream & os, const Shape & shape) {
	shape.print(os);
	return os;
}

bool Shape::operator== (const Shape & s) const {
	    return (this == &s);
}

bool Shape::operator== (const enumShapes::Shapes & typeShape) const {
	return this->getEnum() == typeShape;
}

void Shape::translation(const Point & p) {
	list<Point *> points = this->getPoints();
	Matrice2D::translation(p, points);
}

void Shape::homothety (const Point & p) {
	list<Point *> points = this->getPoints();
	Point origin = this->getOrigin();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - origin.getX());
		n->setY(n->getY() - origin.getY());
	}
	
	Matrice2D::homothety(p, points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + origin.getX());
		n->setY(n->getY() + origin.getY());
	}
}

void Shape::rotation (const double radius) {
	list<Point *> points = this->getPoints();
	Point origin = this->getOrigin();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - origin.getX());
		n->setY(n->getY() - origin.getY());
	}
	
	Matrice2D::rotation(radius, points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + origin.getX());
		n->setY(n->getY() + origin.getY());
	}
}

void Shape::centralSymmetry () {
	list<Point *> points = this->getPoints();
	Point origin = this->getOrigin();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - origin.getX());
		n->setY(n->getY() - origin.getY());
	}
	
	Matrice2D::centralSymmetry(points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + origin.getX());
		n->setY(n->getY() + origin.getY());
	}
}

void Shape::axialSymmetryX () {
	list<Point *> points = this->getPoints();
	Point origin = this->getOrigin();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - origin.getX());
		n->setY(n->getY() - origin.getY());
	}
	
	Matrice2D::axialSymmetryX(points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + origin.getX());
		n->setY(n->getY() + origin.getY());
	}
}

void Shape::axialSymmetryY () {
	list<Point *> points = this->getPoints();
	Point origin = this->getOrigin();
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() - origin.getX());
		n->setY(n->getY() - origin.getY());
	}
	
	Matrice2D::axialSymmetryY(points);
	
	for(auto n : this->getPoints()) 
	{
		n->setX(n->getX() + origin.getX());
		n->setY(n->getY() + origin.getY());
	}
}
