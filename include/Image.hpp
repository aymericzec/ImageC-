/**
 * \file Image.hpp
 * \brief Classe représentant une Image
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter une Image, herite d'une Figure et contient des Images plus petites.
 *
 */
#ifndef __IMAGE__
#define __IMAGE__

#include "Shape.hpp"
#include <set>
#include <memory>
#include "Shapes.hpp"

using namespace std;
using namespace enumShapes;


class Image : public Shape
{
private:
    /**
     * Origine de la shape
     */
    Point _origin;
   
    /**
     * Nombre de shapes dans une image
     */
    int _number;

    /**
     * Conteneur de shapes allouées dynamiquement
     */
    set<shared_ptr<Shape>> _shapes;
    
    /**
	 * \fn virtual list<Point *> getPoints() override
	 * \brief Méthode privé permettant de renvoyer la liste des points de la figure.
	 *
	 * \param void
	 * \return list<Point *>
	 */
	virtual list<Point *> getPoints() override;
	
	/**
	 * \fn list<shared_ptr<Shape>> sortImage(function<bool(const shared_ptr<Shape> &, const shared_ptr<Shape> &)> f);
	 * \brief Permet de trier une Image à partir d'une function
	 *
	 * \param function<bool(const shared_ptr<Shape> &, const shared_ptr<Shape> &)>
	 * \return list<shared_ptr<Shape>> 
	 */
	list<shared_ptr<Shape>> sortImage(function<bool(const shared_ptr<Shape> &, const shared_ptr<Shape> &)> f);
	
	/**
	 * \fn void printAux(ostream & os, int level) const
	 * \brief Permet de faire une recursion sur une Image pour afficher ses figures
	 *
	 * \param ostream, int
	 * \return void
	 */	
	void printAux(ostream & os, int level) const;

public:
    static Image temoin;
	/**
	 * \fn Image (const Point & a = Point(0,0), const Point & originImage = Point(0,0))
	 * \brief Construit une Image
	 *
	 * \param Point, Point
	 * \return Image
	 */
    Image (const Point & a = Point(0,0)) : _origin(a), _number(0), _shapes{} {}

	/**
	 * \fn Image(const Image & image)
	 * \brief Constructeur de copie
	 *
	 * \param const Image
	 * \return Image
	 */
    Image(const Image & image);
    
	/**
	 * \fn virtual shared_ptr<Shape> copy() const override
	 * \brief Constructeur de copie virtuelle
	 *
	 * \param void
	 * \return shared_ptr<Shape>
	 */
    virtual shared_ptr<Shape> copy() const override;
    
	/**
	 * \fn virtual ~Image()
	 * \brief Destructeur d'image
	 *
	 * \param void
	 * \return void
	 */
    virtual ~Image()
    {
    
    }

	/**
	 * \fn int getSize() const
	 * \brief Renvoie le nombre de figures que contient l'image de niveau 1
	 *
	 * \param void
	 * \return int
	 */
    int getSize() const;
    
	/**
	 * \fn set<shared_ptr<Shape>> getShapes() const
	 * \brief Renvoie les figures de l'Image
	 *
	 * \param void
	 * \return set<shared_ptr<Shape>>
	 */
    set<shared_ptr<Shape>> getShapes() const;
    
 	/**
	 * \fn Point getOrigin() const
	 * \brief Renvoie l'origine de l'image
	 *
	 * \param void
	 * \return Point
	 */
    Point getOrigin() const;

	/**
	 * \fn virtual Shapes getEnum() const override
	 * \brief Renvoie l'enum de l'image
	 *
	 * \param void
	 * \return Shapes
	 */
	virtual Shapes getEnum() const override;
	

	/**
	 * \fn bool add(const Shape & s)
	 * \brief Ajoute une figure dans l'image. N'ajoute pas si l'air est plus grande que l'image.
	 *
	 * \param const Shape &
	 * \return bool
	 */
	bool add(const Shape & s);
	
	/**
	 * 
	 * Renvoie des listes au niveau 1 de la forme
	 * Car set est ordonnée sans doublons et on ne peut pas triées
	 * pas de sens de devoir trier une image
	 * Si on modifie le set l'insertion va devoir changer, si on change la comparaison alors si 2 figures ont le même paramètre une va etre supprimé
	 * a tester
	 * 
	 */

 	/**
	 * \fn virtual void translation(const Point & trans)
	 * \brief fait une translation sur les figures de l'image
	 *
	 * \param const Point
	 * \return void
	 */
    virtual void translation(const Point & trans);
    
 	/**
	 * \fn virtual void homothety(const Point & p)
	 * \brief 
	 *
	 * \param Point
	 * \return void
	 */
    virtual void homothety(const Point & p);
    
	/**
	 * \fn virtual void rotation(const double radius)
	 * \brief fait une rotation sur les figures de l'image
	 *
	 * \param double
	 * \return void
	 */
	virtual void rotation(const double radius);
	
	/**
	 * \fn virtual void centralSymmetry ()
	 * \brief Fait une symetrie centrale sur les figures de l'image
	 *
	 * \param void
	 * \return void
	 */
	virtual void centralSymmetry ();
	
	/**
	 * \fn virtual void axialSymmetryX()
	 * \brief Fait une symetrie sur X sur les figures de l'image
	 *
	 * \param void
	 * \return void
	 */
	virtual void axialSymmetryX();
	
	/**
	 * \fn virtual void axialSymmetryY()
	 * \brief Fait une symetrie sur Y sur les figures de l'image
	 *
	 * \param void
	 * \return void
	 */
	virtual void axialSymmetryY();
 
 	/**
	 * \fn virtual void drawMLV() const override
	 * \brief Dessine une image avec la bibliothèque MLV
	 *
	 * \param void
	 * \return void
	 */
    virtual void drawMLV() const override;
 
 	/**
	 * \fn virtual double surface() const override
	 * \brief Renvoie la somme des surfaces des figures que contient l'image
	 *
	 * \param void
	 * \return double
	 */
    virtual double surface() const override;
  
  	/**
	 * \fn virtual double perimeter() const override
	 * \brief Renvoie la somme des perimetres que contient l'image
	 *
	 * \param void
	 * \return double
	 */
    virtual double perimeter() const override;
  
  	/**
	 * \fn virtual double origineDistance(const Point & p) const override
	 * \brief Renvoie la distance entre l'origine de l'image et un point
	 *
	 * \param void
	 * \return double
	 */
    virtual double origineDistance(const Point & p) const override;
   
   	/**
	 * \fn virtual void print(ostream & os = cout) const override
	 * \brief Affiche une image dans une sortie
	 *
	 * \param ostreal
	 * \return void
	 */
    virtual void print(ostream & os = cout) const override;
    
  	/**
	 * \fn list<shared_ptr<Shape>> sortPerimeter (bool increase = true)
	 * \brief renvoie une liste triée des figures d'une image par perimetre
	 *
	 * \param bool
	 * \return list<shared_ptr<Shape>>
	 */
    list<shared_ptr<Shape>> sortPerimeter (bool increase = true);
    
	/**
	 * \fn list<shared_ptr<Shape>> sortSurface (bool increase = true)
	 * \brief renvoie une liste triée des figures d'une image par surface
	 *
	 * \param bool
	 * \return list<shared_ptr<Shape>>
	 */
	list<shared_ptr<Shape>> sortSurface (bool increase = true);
	
	/**
	 * \fn list<shared_ptr<Shape>> sortOriginDistance (bool increase = true)
	 * \brief renvoie une liste triée par distance par rapport à un point
	 *
	 * \param void
	 * \return list<Point *>
	 */
	list<shared_ptr<Shape>> sortOriginDistance (bool increase = true);
	
	/**
	 * \fn list<shared_ptr<Shape>> searchShape (Shapes typeShape)
	 * \brief Renvoie une liste contenant toutes les figures d'un certain type
	 *
	 * \param Shapes
	 * \return list<shared_ptr<Shape>>
	 */		
	list<shared_ptr<Shape>> searchShape (Shapes typeShape);

	/**
	 * \fn list<shared_ptr<Shape>> searchPerimeter (double perimeter)
	 * \brief Renvoie une liste de figure qui contient un perimetre superieur à une valeur
	 *
	 * \param double
	 * \return list<shared_ptr<Shape>>
	 */
	list<shared_ptr<Shape>> searchPerimeter (double perimeter);
	
	/**
	 * \fn int countShape (Shapes typeShape)
	 * \brief Conte les figures d'un certain type
	 *
	 * \param Shapes
	 * \return int
	 */	
	int countShape (Shapes typeShape);

	/**
	 * \fn int countPerimeter (double perimeter)
	 * \brief Conte les figures superieur à un certain perimetre
	 *
	 * \param void
	 * \return int
	 */
	int countPerimeter (double perimeter);
	
	/**
	 * \fn bool deleteShape (Shapes typeShape)
	 * \brief Permet de supprimer les figures d'une image d'un certain type
	 *
	 * \param Shapes
	 * \return bool
	 */	
	bool deleteShape (Shapes typeShape);

	/**
	 * \fn bool deletePerimeter (double perimeter)
	 * \brief Supprime les figures d'une image inférieur à un certain perimetre
	 *
	 * \param double
	 * \return bool
	 */
	bool deletePerimeter (double perimeter);    
};


#endif
