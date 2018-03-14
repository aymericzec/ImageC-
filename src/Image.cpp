/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : impléméntation d'une classe décrivant une Image dans une hiérachie de shapes
 */

#include "Image.hpp"
#include <cmath>
#include <list>

static void printAux(ostream & os, const Image & image, int level);

/**
 * L'image témoin est une variable de classe
 */
Image Image::temoin = Image();


Image::Image(const Image & image) : _origin(image._origin), _number(image._number), _shapes(image._shapes)
{
	for (int i = 0; i < _number; i++)
    {
		this->setShape(i, image.getShape(i+1)->copy());
    }
}

/**
 * Fonction virtuelle de copie
 */
shared_ptr<Shape> Image::copy() const
{
    shared_ptr<Image> ptrImage = make_shared<Image>(*this);
    ptrImage->_number = this->_number;
    
	for (int i = 0; i < _number; i++)
    {	
		
		ptrImage->setShape(i, make_shared<Shape>(this->getShape(i+1)->copy()));
    }
    
    return ptrImage;
}


/**
 * ajout d' une shape à une image
 */
void Image::add(const Shape & s)
{
    if (s == *this)
        return;

    if (_number == IMAGE_MAX)
        cerr << "l' image est deja remplie ! " << endl;
    else
    {
        /** Code pour du partage d'instances allouées dynamiquement
         * nécessite des compteurs de référence pour leur libération mémoire
            en C ==> ABANDON
            _tableau[_nombre++] = (Shape *) (&f);
            en C++: du const_cast
            _tableau[_nombre++] = const_cast<Shape *> (&f);
        */
         this->setShape(_number++, (&s)->copy());
    }
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
    for (int i = 0; i < _number; i++)
    {            
        if(this->getShape(i+1) != 0)
			this->getShape(i+1)->translation(p);  
    }
}

/**
 * Le dessin se limite à un affichage
 */
void Image::draw(ostream & os) const
{
    os << *this << endl;
}

double Image::surface() const
{
    double res = 0;

    for (int i = 0; i < _number; i++)
    {
        if(this->getShape(i+1) != 0)
			res += this->getShape(i+1)->surface(); 
    }
    return res;
}

double Image::perimeter() const
{
	double p = 0.0;
	
	for(int i = 0; i < _number; i++) 
	{
		p += this->getShape(i+1)->perimeter();
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
    printAux(os, *this, 0);
}

static void printAux(ostream & os, const Image & image, int level)
{
    int j;
    for (j = 0; j < level; j++)
    {
                os << "\t";
    }
    os << "BEGIN IMAGE : " << image.getOrigin() << " " << image.getNumber() << " shapes " << endl;
    for (int i = 0; i < image.getNumber(); i++)
    {
        const Image * imageIn = dynamic_pointer_cast<const Image *> (image.getShape(i+1));
        if (imageIn != 0)
        {
            printAux(os, *imageIn, level + 1);
        }
        else
        {
            for (j = 0; j < level; j++)
            {
                os << "\t";
            }
            image.getShape(i+1)->print(os);
   
        }
    }
    for (j = 0; j < level; j++)
    {
                os << "\t";
    }
    os << "END IMAGE" << endl;
}
