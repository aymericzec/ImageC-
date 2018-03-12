#include "Matrice2D.hpp"
#include <cmath>
#include "Line.hpp"


void mulMatrice(double matrice [][2], const Point & p)
{
	double result[2][1];
	
	result[0][0] = matrice[0][0] * p.getX() + matrice[0][1] * p.getY();
	result[1][0] = matrice[1][0] * p.getX() + matrice[1][1] * p.getY();
	
	p.setX(result[0][0]);
	p.setY(result[1][0]);
}


void translation(const Point & p, Figure & figure)
{
	figure.deplacer(p);
	cout << "ok" << endl;
}

void homothety(const Point & p, Figure & figure)
{
	double matrice[2][2];
	
	matrice[0][0] = 1;
	matrice[0][1] = p.getX();
	matrice[1][0] = p.getY();
	matrice[1][1] = 1;

	for(auto n : figure.getPoints()) 
	{
		cout << n->getX() << endl;
		mulMatrice(matrice, *n);
	}
}

void Matrice2D::rotation(const double angle, initializer_list<Point> & p)
{
	double matrice[2][2];
	
	matrice[0][0] = cos(angle);
	matrice[0][1] = -sin(angle);
	matrice[1][0] = sin(angle);
	matrice[1][1] = cos(angle);
	
	for(auto n : p) 
	{
		mulMatrice(matrice, n);
	}
}

void Matrice2D::axialSymmetryX(initializer_list<Point> & p)
{
	double matrice[2][2];
	
	matrice[0][0] = 1;
	matrice[0][1] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = -1;
	
	for(auto n : p) 
	{
		mulMatrice(matrice, n);
	}
}

void Matrice2D::axialSymmetryY(initializer_list<Point> & p)
{
	double matrice[2][2];
	
	matrice[0][0] = -1;
	matrice[0][1] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = 1;
	
	for(auto n : p) 
	{
		mulMatrice(matrice, n);
	}
}

void Matrice2D::centralSymmetry(initializer_list<Point> & p)
{
	double matrice[2][2];
	
	matrice[0][0] = -1;
	matrice[0][1] = 0;
	matrice[1][0] = 0;
	matrice[1][1] = -1;
	
	for(auto n : p) 
	{
		mulMatrice(matrice, n);
	}
}
