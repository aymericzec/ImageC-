/**
 * \file Matrice2D.hpp
 * \brief Classe fournissant des calculs de matrices à partir de points
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe fournissant des methodes statiques de calcul de matrice
 *
 */

#ifndef __MATRICE2D__
#define __MATRICE2D__
#include <iostream>
#include <list>
#include "Point.hpp"

using namespace std;

class Matrice2D {
private:

	/**
	 * \fn friend void mulMatrice(double matrice [][2], Point & p)
	 * \brief multiplie une matrice par une valeur
	 *
	 * \param double [][], Point &
	 * \return void
	 */	
	friend void mulMatrice(double matrice [][2], Point & p);
	
public:
	virtual ~Matrice2D() { };
	
	/**
	 * \fn static void translation(const Point & p, list<Point *> & points)
	 * \brief Translate une liste de points par un point
	 *
	 * \param Point, list<Point *> &
	 * \return void
	 */	
	static void translation(const Point & p, list<Point *> & points);
	
	/**
	 * \fn static void homothety(const Point & p, list<Point *> & points)
	 * \brief Effectue l'homothety d'une liste de point à partir d'un point
	 *
	 * \param Point, list<Point *> &
	 * \return void
	 */	
	static void homothety(const Point & p, list<Point *> & points);
	
	/**
	 * \fn static void rotation(const double angle, list<Point *> & points)
	 * \brief Effectue une rotation sur une liste de point à partir d'un angle
	 *
	 * \param double, list<Point *> &
	 * \return void
	 */		
	static void rotation(const double angle, list<Point *> & points);

	/**
	 * \fn static void axialSymmetryX(list<Point *> & points)
	 * \brief Effectue la symetrie sur X d'une liste de points
	 *
	 * \param list<Point *> &
	 * \return void
	 */	
	static void axialSymmetryX(list<Point *> & points);

	/**
	 * \fn static void axialSymmetryY(list<Point *> & points)
	 * \brief Effecute la symetrie d'une liste sur Y
	 *
	 * \param list<Point *> &
	 * \return void
	 */	
	static void axialSymmetryY(list<Point *> & points);

	/**
	 * \fn static void centralSymmetry(list<Point *> & points)
	 * \brief Effecute une symetrie centrale
	 *
	 * \param list<Point *> &
	 * \return void
	 */
	static void centralSymmetry(list<Point *> & points);
};



#endif
