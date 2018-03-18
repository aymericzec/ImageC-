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
#include "Filter.hpp"
#include "Shapes.hpp"

using namespace std;
using namespace enumShapes;

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
    
    Point _originImage;
    /**
     * Conteneur de shapes allou�es dynamiquement
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
             * BUG si partage d'instances allou�es dynamiquement
             * ==> IL FAUT IMPLEMENTER DES COMPTEURS DE REFERENCES
             * Dans l'impl�mentation propos�e, les instances sont recopi�es lorsqu'elles sont
             * ajout�es dans le tableau de shapes. Il n'y a pas de partage d'instances.
             * Dans la m�thode ajouter on a :
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
	 * Car set est ordonn�e sans doublons et on ne peut pas tri�es
	 * pas de sens de devoir trier une image
	 * Si on modifie le set l'insertion va devoir changer, si on change la comparaison alors si 2 figures ont le m�me param�tre une va etre supprim�
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
