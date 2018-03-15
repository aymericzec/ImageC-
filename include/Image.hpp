/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant une image dans une hiérachie de shapes
 */

#ifndef __IMAGE__
#define __IMAGE__

#include "Shape.hpp"
#include <set>
#include <memory>

using namespace std;

/**
 * Politique uniforme d'allocation mémoire
 * Toutes les shapes sont allouées dynamiquement
 * Une image les mémorise via un tableau de pointeurs de shapes
 */
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
    
    Point _originImage;
    /**
     * Conteneur de shapes allouées dynamiquement
     */
    set<shared_ptr<Shape>> _shapes;
	virtual list<Point *> getPoints();

public:
    static Image temoin;

    Image (const Point & a = Point(0,0), const Point & originImage = Point(0,0)) : _origin(a), _number(0), _originImage(originImage) , _shapes{shared_ptr<Shape>()} { }

    /**
     * contructeur de copie profonde
     */
    Image(const Image & image);

    virtual shared_ptr<Shape> copy() const;

    virtual ~Image()
    {
        
			/**
             * BUG si partage d'instances allouées dynamiquement
             * ==> IL FAUT IMPLEMENTER DES COMPTEURS DE REFERENCES
             * Dans l'implémentation proposée, les instances sont recopiées lorsqu'elles sont
             * ajoutées dans le tableau de shapes. Il n'y a pas de partage d'instances.
             * Dans la méthode ajouter on a :
                  _tableau[_nombre++] = ((Shape *) &f)->copy();
            */
         
        _shapes.clear();
      }

    shared_ptr<Shape> getShape(int index) const;

    void setShape(int index, shared_ptr<Shape> shape);

    int getNumber() const;

    Point getOrigin() const;
    

    void add(const Shape & s);

	virtual  Point getOriginImage() const;

    virtual void translation(const Point & trans);
    virtual void homothety(const Point & p);
	virtual void rotation(const double radius);
	virtual void centralSymmetry ();
	virtual void axialSymmetryX();
	virtual void axialSymmetryY();
	
	
    virtual void draw(ostream & os = cout) const;
    virtual void drawMLV() const;
    virtual double surface() const;
    virtual double perimeter() const;
    virtual double origineDistance(const Point & p) const;
    virtual void print(ostream & os = cout) const;

    
};
#endif
