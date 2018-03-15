/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe abstraite de base d'une hiérarchie de conditions
 *
 * La classe Condition devrait proposer une fonction de copie virtuelle à l'instar de la classe Figure
 */

#ifndef __CONDITION__
#define __CONDITION__
#include <list>
#include "Shape.hpp"

class Condition {
public:
    virtual bool verif(const Shape & shape) const = 0;
    virtual string toString() const = 0;

protected:
    virtual ~Condition() {};
};
#endif
