/**
 * \file Rectangle.hpp
 * \brief Classe représentant un Rectangle
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Rectangle héritant d'une Figure.
 *
 */
#ifndef __RECTANGLE__
#define __RECTANGLE__
#include "Shape.hpp"
#include "Shapes.hpp"
#include <list>

using namespace std;
using namespace enumShapes;

class Rectangle : public Shape {

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
	static Rectangle temoin;
	
	/**
	 * \fn Rectangle(const Point & a, const Point & b)
	 * \brief Constructeur d'un rectangle
	 *
	 * \param Point, Point
	 * \return Rectangle
	 */
	Rectangle(const Point & a, const Point & b): _A(a), _D(b), _B(), _C() 
	{ 
		_B.setX(_D.getX());
		_B.setY(_A.getY());
		_C.setX(_A.getX());
		_C.setY(_D.getY());
	}
	
	/**
	 * \fn Point getA() const;
	 * \brief Récuperer le premier point du rectangle
	 *
	 * \param void
	 * \return Point
	 */
	Point getA() const;
	
	/**
	 * \fn Point getB() const;
	 * \brief Récuperer le deuxième point du rectangle
	 *
	 * \param void
	 * \return Point
	 */
	Point getB() const;
	
	/**
	 * \fn Point getC() const;
	 * \brief Récuperer le troisième point du rectangle
	 *
	 * \param void
	 * \return Point
	 */
	Point getC() const;
	
	/**
	 * \fn Point getD() const;
	 * \brief Récuperer le quatrième point du rectangle
	 *
	 * \param void
	 * \return Point
	 */
	Point getD() const;
		
	/**
	 * \fn virtual shared_ptr<Shape> copy() const override
	 * \brief Renvoie une copie du triangle par un pointeur partagé. Les figures sont immutables.
	 *
	 * \param void
	 * \return shared_ptr<Shape>
	 */ 
	virtual shared_ptr<Shape> copy() const override;
	
	/**
	 * \fn virtual ~Rectangle()
	 * \brief Destructeur d'un rectangle.
	 *
	 * \param void
	 * \return void
	 */
    virtual ~Rectangle() { }
   
   /**
	 * \fn virtual void drawMLV() const override
	 * \brief Dessine un rectangle à partir de la MLV
	 *
	 * \param void
	 * \return void
	 */
	virtual void drawMLV() const override;
	
	/**
	 * \fn virtual void print(ostream & os = cout) const override;
	 * \brief Affiche un rectangle dans une sortie
	 *
	 * \param ostream
	 * \return void
	 */
	virtual void print(ostream & os = cout) const override;
	
	/**
	 * \fn virtual double surface() const override
	 * \brief renvoie la surface d'un rectangle
	 *
	 * \param void
	 * \return double
	 */ 
    virtual double surface() const override;
	
	/**
	 * \fn virtual double perimeter() const override
	 * \brief Renvoie le perimetre d'un rectangle
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
	 * \brief Renvoie l'enum auquel appartient le rectangle
	 *
	 * \param void
	 * \return Shapes
	 */
    virtual enumShapes::Shapes getEnum() const override;
    
 	/**
	 * \fn Point Rectangle::getOrigin () const
	 * \brief Renvoie l'origine d'un rectangle
	 *
	 * \param void
	 * \return Point
	 */   
    virtual Point getOrigin () const;
    
private:
	Point _A; //Point en haut à gauche
	Point _D; //Point en bas à droite
	Point _B; //Point en haut à droite
	Point _C; //Point en bas à gauche
};


#endif
