/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant la condition EstPetite
 */

#ifndef ESTPETITE_H
#define ESTPETITE_H
#include "condition.h"

/**
 * Conversion d'un entier en un objet string
 */
extern string intToString(int n);

class EstPetite : public Condition
{

public:
    EstPetite(double seuil) : _seuil(seuil)
    {
    }

    virtual ~EstPetite() { }

    double getSeuil() const
    {
        return this->_seuil;
    }

    virtual string toString() const
    {
        return string("La surface EST PLUS PETITE QUE ") + "" + intToString(_seuil);
    }

    virtual bool verif(const Figure * f) const
    {
        if(f->surface() < this->_seuil)
        {
            return true;
        }
        return false;
    }

private:
    double _seuil;
};
#endif
