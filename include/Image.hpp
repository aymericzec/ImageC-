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
#include "Filter.hpp"
#include "Shapes.hpp"

using namespace std;
using namespace enumShapes;

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
    
    
	virtual list<Point *> getPoints() override;
	
	list<shared_ptr<Shape>> sortImage(function<bool(const shared_ptr<Shape> &, const shared_ptr<Shape> &)> f);
	
	void printAux(ostream & os, int level) const;

public:
    static Image temoin;

    Image (const Point & a = Point(0,0), const Point & originImage = Point(0,0)) : _origin(a), _number(0), _originImage(originImage) , _shapes{} {}

    /**
     * contructeur de copie profonde
     */
    Image(const Image & image);

    virtual shared_ptr<Shape> copy() const override;

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


    int getSize() const;
    set<shared_ptr<Shape>> getShapes() const;
    Point getOrigin() const;
	virtual  Point getOriginImage() const override;
	virtual Shapes getEnum() const override;
	
	void add(const Shape & s);
	
	/**
	 * 
	 * Renvoie des listes au niveau 1 de la forme
	 * Car set est ordonnée sans doublons et on ne peut pas triées
	 * pas de sens de devoir trier une image
	 * Si on modifie le set l'insertion va devoir changer, si on change la comparaison alors si 2 figures ont le même paramètre une va etre supprimé
	 * a tester
	 * 
	 */

    virtual void translation(const Point & trans);
    virtual void homothety(const Point & p);
	virtual void rotation(const double radius);
	virtual void centralSymmetry ();
	virtual void axialSymmetryX();
	virtual void axialSymmetryY();
	
	
    virtual void draw(ostream & os = cout) const override;
    virtual void drawMLV() const override;
    virtual double surface() const override;
    virtual double perimeter() const override;
    virtual double origineDistance(const Point & p) const override;
    virtual void print(ostream & os = cout) const override;
    
    
    list<shared_ptr<Shape>> sortPerimeter (bool increase = true);
	list<shared_ptr<Shape>> sortSurface (bool increase = true);
	list<shared_ptr<Shape>> sortOriginDistance (bool increase = true);
	
		
	list<shared_ptr<Shape>> searchShape (Shapes typeShape);
	list<shared_ptr<Shape>> searchPerimeter (double perimeter);
	
	
	int countShape (Shapes typeShape);
	int countPerimeter (double perimeter);
	
	
	bool deleteShape (Shapes typeShape) {
		
		bool flag = false;

		if (this->_shapes.size() == 0) {
			return true;
		}
			
		for (auto shape: this->_shapes) {
			if (*shape == Shapes::IMAGE) {
				shared_ptr<Image> img = dynamic_pointer_cast<Image>(shape);
				img->deleteShape(typeShape);
			}
			else if (*shape == typeShape) {
				cout << *shape << " Suppression" << endl;
				this->_shapes.erase(shape);
				flag = true;
			}
		}

		return flag;		
	}

	bool deletePerimeter (double perimeter) {
			
		bool flag = false;

		if (this->_shapes.size() == 0) {
			return true;
		}
			
		for (auto shape: this->_shapes) {
			if (*shape == Shapes::IMAGE) {
				shared_ptr<Image> img = dynamic_pointer_cast<Image>(shape);
				img->deletePerimeter(perimeter);
			}
				
			if (shape->perimeter() < perimeter) {
				cout << *shape << " Suppression" << endl;
				this->_shapes.erase(shape);
				flag = true;
			}
		}

		return flag;	
	}    
};


#endif
