/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : classe d�crivant une image dans une hi�rachie de shapes
 */

#ifndef __IMAGE__
#define __IMAGE__

#include "Shape.hpp"
#include <set>
#include <memory>

using namespace std;

/**
 * Politique uniforme d'allocation m�moire
 * Toutes les shapes sont allou�es dynamiquement
 * Une image les m�morise via un tableau de pointeurs de shapes
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
    /**
     * Conteneur de shapes allou�es dynamiquement
     */
    set<shared_ptr<Shape>> _shapes;
	virtual list<Point *> getPoints();

public:
    enum {IMAGE_MAX = 50};

    static Image temoin;

    Image (const Point & a = Point(0,0)) : _origin(a), _number(0), _shapes{shared_ptr<Shape>()} { }

    /**
     * contructeur de copie profonde
     */
    Image(const Image & image);

    virtual shared_ptr<Shape> copy() const;

    virtual ~Image()
    {
        
			/**
             * BUG si partage d'instances allou�es dynamiquement
             * ==> IL FAUT IMPLEMENTER DES COMPTEURS DE REFERENCES
             * Dans l'impl�mentation propos�e, les instances sont recopi�es lorsqu'elles sont
             * ajout�es dans le tableau de shapes. Il n'y a pas de partage d'instances.
             * Dans la m�thode ajouter on a :
                  _tableau[_nombre++] = ((Shape *) &f)->copy();
            */
         
        _shapes.clear();
      }

    shared_ptr<Shape> getShape(int index) const
    {
        if ((0 <= index) && (index < IMAGE_MAX)) {
			
            int i = 0;
            
			for(auto it = cbegin(_shapes); it != cend(_shapes); it++) {
								
				if(i == index) {
					auto shape(*it);
					return shape;
				}
				i++;
			}
		}
        return 0;
    }

    void setShape(int index, shared_ptr<Shape> shape)
    {
        int i = 0;
               
        for(auto it = cbegin(_shapes); it != cend(_shapes); it++) {
						
			if(i == index) {
				_shapes.insert(it, shape);
				break;
			}
			i++;
		}
    }

    int getNumber() const
    {
        return _number;
    }

    Point getOrigin() const
    {
        return _origin;
    }

    void add(const Shape & s);

    virtual void translation(const Point & trans);
    virtual void draw(ostream & os = cout) const;
    virtual double surface() const;
    virtual double perimeter() const;
    virtual double origineDistance(const Point & p) const;
    virtual void print(ostream & os = cout) const;

    
};
#endif
