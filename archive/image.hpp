/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : classe d�crivant une image dans une hi�rachie de figures
 */

#ifndef IMAGE_H
#define IMAGE_H

#include "figure.hpp"
#include <set>
#include <memory>

using namespace std;

/**
 * Politique uniforme d'allocation m�moire
 * Toutes les figures sont allou�es dynamiquement
 * Une image les m�morise via un tableau de pointeurs de figures
 */
class Image : public Figure
{

public:
    enum {IMAGE_MAX = 50};

    static Image temoin;

    Image (const Point & a = Point(0,0)) : _origine(a), _nombre(0), _tableau{shared_ptr<Figure>()} { }

    /**
     * contructeur de copie profonde
     */
    Image(const Image & image);

    virtual Figure * copy() const;

    virtual ~Image()
    {
        
			/**
             * BUG si partage d'instances allou�es dynamiquement
             * ==> IL FAUT IMPLEMENTER DES COMPTEURS DE REFERENCES
             * Dans l'impl�mentation propos�e, les instances sont recopi�es lorsqu'elles sont
             * ajout�es dans le tableau de figures. Il n'y a pas de partage d'instances.
             * Dans la m�thode ajouter on a :
                  _tableau[_nombre++] = ((Figure *) &f)->copy();
            */
         
        _tableau.clear();
      }

    Figure * getFigure(int index) const
    {
        if ((0 <= index) && (index < IMAGE_MAX)) {
			
            int i = 0;
            
			for(auto it = cbegin(_tableau); it != cend(_tableau); it++) {
								
				if(i == index) {
					auto figure(*it);
					return figure.get();
				}
				i++;
			}
		}
        return 0;
    }

    void setFigure(int index, Figure * figure)
    {
        int i = 0;
               
        for(auto it = cbegin(_tableau); it != cend(_tableau); it++) {
						
			if(i == index) {
				_tableau.insert(it, shared_ptr<Figure>(figure));
				break;
			}
			i++;
		}
    }

    int getNombre() const
    {
        return _nombre;
    }

    Point getOrigine() const
    {
        return _origine;
    }

    void ajouter(const Figure & f);
    
    virtual list<Point *> getPoints() const;

    virtual void deplacer(const Point & trans);
    virtual void dessiner(ostream & os = cout) const;
    virtual double surface() const;
    virtual double perimetre() const;
    virtual double distance_origine(const Point & p) const;
    virtual void afficher(ostream & os = cout) const;
private:
    /**
     * Origine de la figure
     */
    Point _origine;
    /**
     * Nombre de figures dans une image
     */
    int _nombre;
    /**
     * Conteneur de figures allou�es dynamiquement
     */
    set<shared_ptr<Figure>> _tableau;
    
};
#endif
