/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : classe abstraite de base d'une hi�rarchie de conditions
 *
 * La classe Condition devrait proposer une fonction de copie virtuelle � l'instar de la classe Figure
 */

#ifndef CONDITION_H
#define CONDITION_H
#include <list>
#include "figure.hpp"

class Condition {
public:
    virtual bool verif(const Figure * f) const = 0;
    virtual string toString() const = 0;

protected:
    virtual ~Condition() {};
};
#endif
