/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : impléméntation d'une classe décrivant une Image dans une hiérachie de shapes
 */

#include "Image.hpp"
#include <cmath>
#include <list>
#include "Shapes.hpp"
using namespace enumShapes;

/**
 * L'image témoin est une variable de classe
 */
Image Image::temoin = Image();


Image::Image(const Image & image) : _origin(image._origin), _number(image._number), _originImage(image.getOriginImage()), _shapes(image._shapes) {}

/**
 * Fonction virtuelle de copie
 */
shared_ptr<Shape> Image::copy() const
{
    return make_shared<Image>(*this);
}


/**
 * ajout d' une shape à une image
 */
void Image::add(const Shape & s)
{
	this->_shapes.insert(s.copy());
}

list<Point *> Image::getPoints()
{
	list<Point *> p = {&_origin};
	
	return p;
}

/**
 * Déplacement-translation de valeur le point p
 * toutes les shapes de l'image sont également déplacées
 */
void Image::translation(const Point & p)
{
    _origin += p;
    
    for (auto shape: this->_shapes) {
		shape->translation(p);
	}
}

void Image::homothety(const Point & p)
{
    for (auto shape: this->_shapes) {
		shape->homothety(p);
	}
}

void Image::rotation(const double radius)
{
    for (auto shape: this->_shapes) {
		shape->rotation(radius);
	}
}

void Image::centralSymmetry()
{
    for (auto shape: this->_shapes) {
		shape->centralSymmetry();
	}
}
	
void Image::axialSymmetryX()
{
    for (auto shape: this->_shapes) {
		shape->axialSymmetryX();
	}
}
	
void Image::axialSymmetryY()
{
    for (auto shape: this->_shapes) {
		shape->axialSymmetryY();
	}
}

/**
 * Le dessin se limite à un affichage
 */
void Image::draw(ostream & os) const
{
    os << *this << endl;
}

/**
 * Le dessin se limite à un affichage
 */
void Image::drawMLV() const
{
    for (auto shape: this->_shapes) {
		shape->drawMLV();
	}
}

double Image::surface() const
{
    double res = 0;

    for (auto shape: this->_shapes) {
		res += shape->surface();
	}
    return res;
}

double Image::perimeter() const
{
	double p = 0.0;
	
    for (auto shape: this->_shapes) {
		p += shape->perimeter();
	}
	
	return p;
}

double Image::origineDistance(const Point & p) const
{
	double distance = sqrt( (_origin.getX() - p.getX()) * (_origin.getX() - p.getX())
                            + (_origin.getY() - p.getY()) * (_origin.getY() - p.getY())); 
                            
    return distance;
}

void Image::print(ostream & os) const
{
    this->printAux(os, 0);
}

void Image::printAux(ostream & os, int level) const
{
    int j;
    for (j = 0; j < level; j++)
    {
                os << "\t";
    }
    
    os << "IMAGE: origine " << this->getOrigin() << " Quantités: " << this->getSize() 
    << " Périmètre: " << this->perimeter() << " Aire:  " 
    << this->surface() << " Distance à l'origine: " << endl;
    
    
    for (auto shape: this->_shapes) {
		shared_ptr<const Image> imageIn = dynamic_pointer_cast<const Image>(shape);
		
		if (imageIn != 0)
        {
            imageIn->printAux(os, level + 1);
        }
        else
        {
            for (j = 0; j < level; j++)
            {
                os << "\t";
            }
            shape->print(os);
        }
	}
    	

    for (j = 0; j < level; j++)
    {
                os << "\t";
    }
    os << "END IMAGE" << endl;
}

int Image::getSize() const
{
	return this->_shapes.size();
}

Point Image::getOrigin() const
{
	return _origin;
}

Point Image::getOriginImage() const
{
	return _originImage;
}

Shapes Image::getEnum() const 
{
	return Shapes::IMAGE;
}
