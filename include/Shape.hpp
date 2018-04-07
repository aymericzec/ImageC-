/**
 * \file Shape.hpp
 * \brief Classe représentant une Figure
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter une Figure.
 *
 */
#ifndef __SHAPE__
#define __SHAPE__
#include <iostream>
#include "Point.hpp"
#include <list>
#include <memory>
#include "Shapes.hpp"

using namespace std;

class Shape {
private:

	/**
	 * \fn virtual list<Point *> getPoints() override
	 * \brief Méthode privé permettant de renvoyer la liste des points de la figure.
	 *
	 * \param void
	 * \return list<Point *>
	 */
	virtual list<Point *> getPoints() = 0;
	
public:
   
   /**
	 * \fn virtual shared_ptr<Shape> copy() const override
	 * \brief Renvoie une copie du triangle par un pointeur partagé. Les figures sont immutables.
	 *
	 * \param void
	 * \return shared_ptr<Shape>
	 */ 
    virtual shared_ptr<Shape> copy() const = 0;
	
	/**
	 * \fn virtual ~Shape()
	 * \brief Destructeur d'une figure.
	 *
	 * \param void
	 * \return void
	 */
    virtual ~Shape () { };
    
	/**
	 * \fn virtual void translation(const Point & p)
	 * \brief Applique une translation sur une figure
	 *
	 * \param Point
	 * \return void
	 */
    virtual void translation(const Point & p);
	
	/**
	 * \fn virtual void homothety(const Point & p)
	 * \brief Applique une homothetie sur une figure
	 *
	 * \param Point
	 * \return void
	 */
	virtual void homothety(const Point & p);
	
	/**
	 * \fn virtual void rotation(const double radius))
	 * \brief Applique une rotation sur une figure
	 *
	 * \param double
	 * \return void
	 */
	virtual void rotation(const double radius);
	
	/**
	 * \fn virtual void centralSymmetry()
	 * \brief Applique une symetrie centrale sur une figure
	 *
	 * \param void
	 * \return void
	 */
	virtual void centralSymmetry();
	
	/**
	 * \fn virtual void axialSymmetryX()
	 * \brief Applique une symetrie en x sur une figure
	 *
	 * \param void
	 * \return void
	 */
	virtual void axialSymmetryX();
	
	/**
	 * \fn virtual void axialSymmetryY()
	 * \brief Applique une symetrie en y sur une figure
	 *
	 * \param void
	 * \return void
	 */
	virtual void axialSymmetryY();
	
	/**
	 * \fn virtual void drawMLV() const override
	 * \brief Dessine une figure à partir de la MLV
	 *
	 * \param void
	 * \return void
	 */
	virtual void drawMLV() const = 0;
	
	/**
	 * \fn virtual void print(ostream & os = cout) const override;
	 * \brief Affiche une figure dans une sortie
	 *
	 * \param ostream
	 * \return void
	 */
    virtual void print(ostream & os) const = 0;

	/**
	 * \fn virtual double surface() const override
	 * \brief renvoie la surface d'une figure
	 *
	 * \param void
	 * \return double
	 */
    virtual double surface() const = 0;
	
	/**
	 * \fn virtual double perimeter() const override
	 * \brief Renvoie le perimetre d'une figure
	 *
	 * \param void
	 * \return double
	 */
    virtual double perimeter() const = 0;
	
	/**
	 * \fn virtual double origineDistance(const Point & p) const override
	 * \brief Récupere la distance par rapport à un point
	 *
	 * \param Point
	 * \return double
	 */
    virtual double origineDistance(const Point & p) const = 0;
    
	/**
	 * \fn virtual enumShapes::Shapes getEnum() const override
	 * \brief Renvoie l'enum auquel appartient la figure
	 *
	 * \param void
	 * \return Shapes
	 */
    virtual enumShapes::Shapes getEnum() const = 0;

	/**
	 * \fn bool operator== (const Shape & f) const
	 * \brief Redéfinition de l'opérateur ==
	 *
	 * \param Shape
	 * \return bool
	 */
	bool operator== (const Shape & f) const;

	/**
	 * \fn friend ostream & operator<< (ostream & os, const Shape & shape)
	 * \brief Redéfinition de l'opérateur <<
	 *
	 * \param ostream, Shape
	 * \return ostream
	 */
    friend ostream & operator<< (ostream & os, const Shape & shape);
	
	/**
	 * \fn bool operator== (const enumShapes::Shapes & typeShape) const
	 * \brief Redéfinition de l'opérateur ==
	 *
	 * \param Shape
	 * \return bool
	 */
    bool operator== (const enumShapes::Shapes & typeShape) const;
    
	/**
	 * \fn Point & getOrigin() const
	 * \brief Renvoie l'origine de la figure, son centre pour un rectangle, cercle, ligne et triangle
	 *
	 * \param void
	 * \return Point &
	 */
    virtual Point getOrigin() const = 0;
};
#endif
