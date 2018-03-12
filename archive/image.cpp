/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : impléméntation d'une classe décrivant une Image dans une hiérachie de figures
 */

#include "image.hpp"
#include <cmath>

static void afficherAux(ostream & os, const Image & image, int niveau);

/**
 * L'image témoin est une variable de classe
 */
Image Image::temoin = Image();


Image::Image(const Image & image) : _origine(image._origine), _nombre(image._nombre), _tableau(image._tableau)
{
	for (int i = 0; i < _nombre; i++)
    {
		this->setFigure(i, image.getFigure(i+1)->copy());
    }
}

/**
 * Fonction virtuelle de copie
 */
Figure * Image::copy() const
{
    Image * res = new Image(this->_origine);
    res->_nombre = this->_nombre;
    
	for (int i = 0; i < _nombre; i++)
    {
		res->setFigure(i, this->getFigure(i+1)->copy());
    }
    
    return res;
}


/**
 * ajout d' une figure à une image
 */
void Image::ajouter(const Figure & f)
{
    if (f == *this)
        return;

    if (_nombre == IMAGE_MAX)
        cerr << "l' image est deja remplie ! " << endl;
    else
    {
        /** Code pour du partage d'instances allouées dynamiquement
         * nécessite des compteurs de référence pour leur libération mémoire
            en C ==> ABANDON
            _tableau[_nombre++] = (Figure *) (&f);
            en C++: du const_cast
            _tableau[_nombre++] = const_cast<Figure *> (&f);
        */
         this->setFigure(_nombre++, (&f)->copy());
    }
}

list<Point *> Image::getPoints() const
{
	list<Point *> p = {_origine};
	
	return p;
}

/**
 * Déplacement-translation de valeur le point p
 * toutes les figures de l'image sont également déplacées
 */
void Image::deplacer(const Point & p)
{
    _origine += p;
    for (int i = 0; i < _nombre; i++)
    {            
        if(this->getFigure(i+1) != 0)
			this->getFigure(i+1)->deplacer(p);  
    }
}

/**
 * Le dessin se limite à un affichage
 */
void Image::dessiner(ostream & os) const
{
    os << *this << endl;
}

double Image::surface() const
{
    double res = 0;

    for (int i = 0; i < _nombre; i++)
    {
        if(this->getFigure(i+1) != 0)
			res += this->getFigure(i+1)->surface(); 
    }
    return res;
}

double Image::perimetre() const
{
	double p = 0.0;
	
	for(int i = 0; i < _nombre; i++) 
	{
		p += this->getFigure(i+1)->perimetre();
	}
	
	return p;
}

double Image::distance_origine(const Point & p) const
{
	double distance = sqrt( (_origine.getX() - p.getX()) * (_origine.getX() - p.getX())
                            + (_origine.getY() - p.getY()) * (_origine.getY() - p.getY())); 
                            
    return distance;
}

void Image::afficher(ostream & os) const
{
    afficherAux(os, *this, 0);
}

static void afficherAux(ostream & os, const Image & image, int niveau)
{
    int j;
    for (j = 0; j < niveau; j++)
    {
                os << "\t";
    }
    os << "BEGIN IMAGE : " << image.getOrigine() << " " << image.getNombre() << " figures " << endl;
    for (int i = 0; i < image.getNombre(); i++)
    {
        const Image * imageIn = dynamic_cast<const Image *> (image.getFigure(i+1));
        if (imageIn != 0)
        {
            afficherAux(os, *imageIn, niveau + 1);
        }
        else
        {
            for (j = 0; j < niveau; j++)
            {
                os << "\t";
            }
            image.getFigure(i+1)->afficher(os);
   
        }
    }
    for (j = 0; j < niveau; j++)
    {
                os << "\t";
    }
    os << "END IMAGE" << endl;
}
