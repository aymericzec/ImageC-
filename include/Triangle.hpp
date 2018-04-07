/**
 * \file Triangle.hpp
 * \brief Classe représentant un Triangle
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Triangle héritant d'une Figure.
 *
 */
#ifndef __TRIANGLE__
#define __TRIANGLE__
#include "Shape.hpp"
#include "Shapes.hpp"

using namespace enumShapes;
using namespace std;

class Triangle : public Shape {
private:

 	/**
	 * \fn virtual list<Point *> getPoints() override
	 * \brief Méthode privé permettant de renvoyer la liste des points de la figure.
	 *
	 * \param void
	 * \return list<Point *>
	 */
	virtual list<Point *> getPoints() override;
	
public:
	static Triangle temoin;
	
 	/**
	 * \fn Triangle(const Point & a, const Point & b, const Point & c)
	 * \brief Constructeur d'un triangle
	 *
	 * \param Point, Point, Point
	 * \return Triangle
	 */	
	Triangle(const Point & a, const Point & b, const Point & c)
		: _A(a), _B(b), _C(c) { }
		
	/**
	 * \fn Point getA() const;
	 * \brief Récuperer le premier point du triangle
	 *
	 * \param void
	 * \return Point
	 */   
	Point getA() const;
	
	/**
	 * \fn Point getB() const;
	 * \brief Récuperer le deuxième point du triangle
	 *
	 * \param void
	 * \return Point
	 */
	Point getB() const;
	
	/**
	 * \fn Point getC() const;
	 * \brief Récuperer le troisième point du triangle
	 *
	 * \param void
	 * \return Point
	 */
	Point getC() const;
		
	/**
	 * \fn virtual shared_ptr<Shape> copy() const override
	 * \brief Renvoie une copie du triangle par un pointeur partagé. Les figures sont immutables.
	 *
	 * \param void
	 * \return shared_ptr<Shape>
	 */ 
	virtual shared_ptr<Shape> copy() const override;

	/**
	 * \fn virtual ~Triangle()
	 * \brief Destructeur d'un triangle.
	 *
	 * \param void
	 * \return void
	 */
    virtual ~Triangle() { }

	/**
	 * \fn virtual void drawMLV() const override
	 * \brief Dessine un triangle à partir de la MLV
	 *
	 * \param void
	 * \return void
	 */
	virtual void drawMLV() const override;
	
	/**
	 * \fn virtual double surface() const override
	 * \brief renvoie la surface d'un triangle
	 *
	 * \param void
	 * \return double
	 */ 
    virtual double surface() const override;
	
	/**
	 * \fn virtual double perimeter() const override
	 * \brief Renvoie le perimetre d'un triangle
	 *
	 * \param void
	 * \return double
	 */
    virtual double perimeter() const override;
	
	/**
	 * \fn virtual double origineDistance(const Point & p) const override
	 * \brief Récupere la distance par rapport à un point
	 *
	 * \param Point
	 * \return double
	 */
    virtual double origineDistance(const Point & p) const override;
	
	/**
	 * \fn virtual void print(ostream & os = cout) const override;
	 * \brief Affiche un triangle dans une sortie
	 *
	 * \param ostream
	 * \return void
	 */
    virtual void print(ostream & os = cout) const override;
	
	/**
	 * \fn virtual enumShapes::Shapes getEnum() const override
	 * \brief Renvoie l'enum auquel appartient le triangle
	 *
	 * \param void
	 * \return Shapes
	 */     
    virtual enumShapes::Shapes getEnum() const override;

	/**
	 * \fn virtual Point getOrigin () const
	 * \brief Renvoie l'origine du triangle
	 *
	 * \param void
	 * \return Point
	 */
	virtual Point getOrigin () const;

private:
	Point _A; //Point origine celui à gauche
	Point _B; //Point à droite
	Point _C; //Point en haut
};


#endif
