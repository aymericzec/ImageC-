/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant un cercle dans une hiérachie de figures
 */

#ifndef CERCLE_H
#define CERCLE_H
#include "figure.hpp"

using namespace std;

class Cercle: public Figure
{
public:
    static Cercle temoin;

    Cercle(const Point & centre = Point(0,0), int rayon = 0)
        : _centre(centre), _rayon(rayon){ }
        
    Point getCentre() const;
    int getRayon() const;

    virtual Figure * copy() const;

    virtual ~Cercle() { }
    
    virtual list<Point *> getPoints() const;

    virtual void deplacer(const Point & trans);
    virtual void dessiner(ostream & os = cout) const;
    virtual double surface() const;
    virtual double perimetre() const;
    virtual double distance_origine(const Point & p) const;
    virtual void afficher(ostream & os = cout) const;
	
private:
    Point _centre;
    int _rayon;
};
#endif
