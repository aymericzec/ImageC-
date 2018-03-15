/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant la condition EstPetite
 */

#ifndef __MORELITTLE__
#define __MORELITTLE__
#include "Condition.h"

/**
 * Conversion d'un entier en un objet string
 */
extern string intToString(int n);

class MoreLittle : public Condition
{

public:
    MoreLittle(double seuil) : _seuil(seuil)
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

    virtual bool verif(const Shape * s) const
    {
        if(s->surface() < this->_seuil)
        {
            return true;
        }
        return false;
    }

private:
    double _seuil;
};
#endif
