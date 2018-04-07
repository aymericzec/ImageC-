/**
 * \file Line.hpp
 * \brief Classe représentant une Ligne
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter une Ligne héritant d'une Figure.
 *
 */
#ifndef __LIGNE__
#define __LIGNE__
#include "Shape.hpp"
#include "Shapes.hpp"

using namespace enumShapes;

class Line : public Shape {

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
    static Line temoin;

	/**
	 * \fn Line(const Point & a , const Point & b)
	 * \brief Constructeur d'une ligne
	 *
	 * \param Point, Point
	 * \return Line
	 */	
	Line(const Point & a , const Point & b)
        : _origine(a), _extremite(b) { }
		
	  
	/**
	 * \fn Point getOrigin() const;
	 * \brief Récupère le point origine d'une ligne
	 *
	 * \param void
	 * \return Point
	 */
    Point getBegin() const;
	
	/**
	 * \fn Point getExtremity() const;
	 * \brief Récupère le point extremité d'une ligne
	 *
	 * \param void
	 * \return Point
	 */
    Point getExtremity() const;
    
	/**
	 * \fn virtual shared_ptr<Shape> copy() const override
	 * \brief Renvoie une copie du triangle par un pointeur partagé. Les figures sont immutables.
	 *
	 * \param void
	 * \return shared_ptr<Shape>
	 */
    virtual shared_ptr<Shape> copy() const override;
	
	/**
	 * \fn virtual ~Line()
	 * \brief Destructeur d'une ligne.
	 *
	 * \param void
	 * \return void
	 */
    virtual ~Line () { };
  
    /**
	 * \fn virtual void drawMLV() const override
	 * \brief Dessine une ligne à partir de la MLV
	 *
	 * \param void
	 * \return void
	 */
	virtual void drawMLV() const override;
	
	/**
	 * \fn virtual void print(ostream & os = cout) const override;
	 * \brief Affiche une ligne dans une sortie
	 *
	 * \param ostream
	 * \return void
	 */
	virtual void print(ostream & os = cout) const override;
	
	/**
	 * \fn virtual double surface() const override
	 * \brief renvoie la surface d'une ligne
	 *
	 * \param void
	 * \return double
	 */
    virtual double surface() const override;
	
	/**
	 * \fn virtual double perimeter() const override
	 * \brief Renvoie le perimetre d'une ligne
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
	 * \fn virtual enumShapes::Shapes getEnum() const override
	 * \brief Renvoie l'enum auquel appartient la ligne
	 *
	 * \param void
	 * \return Shapes
	 */
    virtual enumShapes::Shapes getEnum() const override;
 
 	/**
	 * \fn virtual Point & getOrigin ()
	 * \brief Renvoie l'origine de la figure
	 *
	 * \param void
	 * \return Point
	 */   
    virtual Point getOrigin () const;

private:
	Point _origine;
	Point _extremite;
};
#endif

