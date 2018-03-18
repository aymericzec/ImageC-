/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : impl�m�ntation d'une classe d�crivant une Image dans une hi�rachie de shapes
 */

#include "Image.hpp"
#include <cmath>
#include <list>
#include "Shapes.hpp"


using namespace enumShapes;


/**
 * L'image t�moin est une variable de classe
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

list<Point *> Image::getPoints()
{
	list<Point *> p = {&_origin};
	
	return p;
}

int Image::getSize() const
{
	return this->_shapes.size();
}

set<shared_ptr<Shape>> Image::getShapes() const
{
	return this->_shapes;
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

/**
 * ajout d' une shape � une image
 */
void Image::add(const Shape & s)
{
	this->_shapes.insert(s.copy());
}

/**
 * D�placement-translation de valeur le point p
 * toutes les shapes de l'image sont �galement d�plac�es
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
 * Le dessin se limite � un affichage
 */
void Image::draw(ostream & os) const
{
    os << *this << endl;
}

/**
 * Le dessin se limite � un affichage
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
    
    os << "IMAGE: origine " << this->getOrigin() << " Quantit�s: " << this->getSize() 
    << " P�rim�tre: " << this->perimeter() << " Aire:  " 
    << this->surface() << " Distance � l'origine: " << endl;
    
    
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



list<shared_ptr<Shape>> Image::sortImage(function<bool(const shared_ptr<Shape> &, const shared_ptr<Shape> &)> f) {
	
	list<shared_ptr<Shape>> shapesList;

	for(const auto & ptr: this->_shapes){
		shapesList.push_back(ptr);
	}
			
	shapesList.sort(f);
		
	return shapesList;
}

list<shared_ptr<Shape>> Image::sortPerimeter (bool increase) {
	
	if (increase) {
		return this->sortImage([&](const shared_ptr<Shape> & a, const shared_ptr<Shape> & b) -> bool { return a->perimeter() < b->perimeter();});
	} else {
		return this->sortImage([&](const shared_ptr<Shape> & a, const shared_ptr<Shape> & b) -> bool { return a->perimeter() > b->perimeter();});
	}
}

list<shared_ptr<Shape>> Image::sortSurface (bool increase) {
	
	if (increase) {
		return this->sortImage([&](const shared_ptr<Shape> & a, const shared_ptr<Shape> & b) -> bool { return a->surface() < b->surface();});
	} else {
		return this->sortImage([&](const shared_ptr<Shape> & a, const shared_ptr<Shape> & b) -> bool { return a->surface() > b->surface();});
	}
}

list<shared_ptr<Shape>> Image::sortOriginDistance (bool increase) {
	
	Point origin = this->getOrigin();
		
	if (increase) {
		return this->sortImage([&](const shared_ptr<Shape> & a, const shared_ptr<Shape> & b) -> bool { return a->origineDistance(origin) < b->origineDistance(origin);});
	} else {
		return this->sortImage([&](const shared_ptr<Shape> & a, const shared_ptr<Shape> & b) -> bool { return a->origineDistance(origin) > b->origineDistance(origin);});
	}
}

list<shared_ptr<Shape>> Image::searchShape (Shapes typeShape) {
		
	list<shared_ptr<Shape>> shapes;
		
	for (auto shape: this->_shapes) {
		if (*shape == typeShape) {
			shapes.push_back(shape);
		}
	}
		
	return shapes;
}

list<shared_ptr<Shape>> Image::searchPerimeter (double perimeter) {
		
	list<shared_ptr<Shape>> shapes;
		
	for (auto shape: this->_shapes) {
		if (shape->perimeter() < perimeter) {
			shapes.push_back(shape);
		}
	}
		
	return shapes;
}

int Image::countShape (Shapes typeShape) {
	return searchShape(typeShape).size();
}

int Image::countPerimeter (double perimeter) {
	return searchPerimeter(perimeter).size();
}
