/**
 * \file Circle.hpp
 * \brief Classe représentant un Cercle
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Cercle héritant d'une Figure.
 *
 */
#ifndef __CIRCLE__
#define __CIRCLE__
#include "Shape.hpp"
#include "Shapes.hpp"

using namespace std;

class Circle: public Shape
{
	
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
    static Circle temoin;


	/**
	 * \fn Circle(const Point & center = Point(0,0), const Point & radius = Point(0,0), const Point & originImage = Point(0,0))
	 * \brief Constructeur d'un cercle
	 *
	 * \param Point, Point
	 * \return Circle
	 */
    Circle(const Point & center = Point(0,0), const Point & radius = Point(0,0))
        : _center(center), _radius(radius) { }
    
    /**
	 * \fn Point getCenter() const;
	 * \brief Récuperer le centre du cercle
	 *
	 * \param void
	 * \return Point
	 */    
    Point getCenter() const;
    
    /**
	 * \fn double getRadius() const
	 * \brief Récuperer le rayon du cercle
	 *
	 * \param void
	 * \return double
	 */  
    double getRadius() const;

    /**
	 * \fn virtual shared_ptr<Shape> copy() const override
	 * \brief Renvoie une copie du cercle par un pointeur partagé. Les figures sont immutables.
	 *
	 * \param void
	 * \return shared_ptr<Shape>
	 */  
    virtual shared_ptr<Shape> copy() const override;


    /**
	 * \fn virtual ~Circle()
	 * \brief Destructeur du cercle.
	 *
	 * \param void
	 * \return void
	 */  
    virtual ~Circle() { }
    
   /**
	 * \fn virtual void drawMLV() const override
	 * \brief Dessine un cercle à partir de la MLV
	 *
	 * \param void
	 * \return void
	 */  
    virtual void drawMLV() const override;
    
   /**
	 * \fn virtual double surface() const override
	 * \brief renvoie la surface cercle
	 *
	 * \param void
	 * \return double
	 */     
    virtual double surface() const override;
    
   /**
	 * \fn virtual double perimeter() const override
	 * \brief Renvoie le perimetre du Cercle
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
	 * \brief Affiche un cercle dans une sortie
	 *
	 * \param ostream
	 * \return void
	 */     
    virtual void print(ostream & os = cout) const override;
    
   /**
	 * \fn virtual enumShapes::Shapes getEnum() const override
	 * \brief Renvoie l'enum auquel appartient le Cercle
	 *
	 * \param Aucun
	 * \return Shapes
	 */     
	virtual enumShapes::Shapes getEnum() const override;

   /**
	 * \fn virtual Point getOrigin () const
	 * \brief Renvoie le centre d'un cercle
	 *
	 * \param Aucun
	 * \return Point
	 */ 	
	virtual Point getOrigin () const;
	
private:
    Point _center;
    Point _radius;
};
#endif
