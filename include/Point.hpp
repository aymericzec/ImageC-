/**
 * \file Point.hpp
 * \brief Classe représentant un Point
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Point.
 *
 */
#ifndef __POINT__
#define __POINT__
#include <iostream>

using namespace std;

class Point
{
public:

	/**
	 * \fn Point(int a = 0, int b = 0)
	 * \brief Constructeur d'un point
	 *
	 * \param int, int
	 * \return Point
	 */
    Point(int a = 0, int b = 0): x(a), y(b) { };

	/**
	 * \fn int getX () const
	 * \brief Récupère la valeur en x
	 *
	 * \param void
	 * \return int
	 */
    int getX () const;
	
	/**
	 * \fn void setX (int a)
	 * \brief Modifie la valeur en x
	 *
	 * \param void
	 * \return int
	 */
    void setX (int a);
	
	/**
	 * \fn int getY () const
	 * \brief Récupère la valeur en y
	 *
	 * \param void
	 * \return int
	 */
    int getY () const;
	
	/**
	 * \fn void setY (int b)
	 * \brief Modifie la valeur en y
	 *
	 * \param void
	 * \return int
	 */
    void setY (int b);

	/**
	 * \fn Point operator+ (const Point & p) const
	 * \brief Redéfinition de l'opérateur +
	 *
	 * \param Point
	 * \return Point
	 */
    Point operator+ (const Point & p) const;
	
	/**
	 * \fn Point operator+= (const Point & p)
	 * \brief Redéfinition de l'opérateur +=
	 *
	 * \param Point
	 * \return Point
	 */
    Point & operator+= (const Point & p);
	
	/**
	 * \fn Point operator= (const Point & p)
	 * \brief Redéfinition de l'opérateur +
	 *
	 * \param Point
	 * \return Point
	 */
    Point & operator= (const Point & p);

	/**
	 * \fn friend ostream & operator<< (ostream & os, const Point & p)
	 * \brief Redéfinition de l'opérateur<<
	 *
	 * \param ostream, Point
	 * \return ostream
	 */
    friend ostream & operator<< (ostream & os, const Point & p);
	
private:
   int x;
   int y;
};
#endif
