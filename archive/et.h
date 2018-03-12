/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant la condition Et
 *
 * La classe Et devrait définir un constructeur de copie et une surcharge de l'opérateur =.
 * En effet, elle a 2 attributs de type pointeur.
 */

#ifndef ET_H
#define ET_H
#include "condition.h"

class Et : public Condition {

public:
    Et(Condition * c1, Condition * c2) : _c1(c1), _c2(c2) { }

    virtual ~Et() { }

    virtual string toString() const
    {
        return _c1->toString() + " ET " + _c2->toString();
    }

    virtual bool verif(const Figure * f) const
    {
        if ((_c1->verif(f)) &&( _c2->verif(f)))
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
