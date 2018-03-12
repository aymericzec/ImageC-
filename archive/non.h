/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant la condition Non
 *
 * La classe Non devrait définir un constructeur de copie et une surcharge de l'opérateur =.
 * En effet, elle a un attribut de type pointeur.
 */

#ifndef NON_H
#define NON_H
#include "condition.h"

class Non : public Condition {

public:
    Non(Condition * c) : condition(c) { }

    virtual ~Non() { }

    virtual string toString() const
    {
        return "NON " + condition->toString();
    }

    virtual bool verif(const Figure * f) const
    {
        return !(condition->verif(f));
    }

private:
    Condition * condition;
};
#endif
