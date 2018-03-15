/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant la condition Et
 *
 * La classe Et devrait définir un constructeur de copie et une surcharge de l'opérateur =.
 * En effet, elle a 2 attributs de type pointeur.
 */

#ifndef __AND__
#define __AND__
#include "Condition.h"
#include "Shape.h"

class AND : public Condition {

public:
    And(Condition * c1, Condition * c2) : _c1(c1), _c2(c2) { }

    virtual ~Et() { }

    virtual string toString() const
    {
        return _c1->toString() + " ET " + _c2->toString();
    }

    virtual bool verif(const Shape * s) const
    {
        if ((_c1->verif(s)) &&( _c2->verif(s)))
        {
            return true;
        }
        return false;
    }

private:
    Condition * _c1;
    Condition * _c2;
};

#endif
