/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : classe d�crivant la condition EstUn
 */

#ifndef ESTUN_H
#define ESTUN_H
#include <cstring>
#include <typeinfo>
#include "condition.h"

class EstUn : public Condition {

public:
    EstUn(const Figure * f) : ftemoin(f) { }

    virtual ~EstUn() { }

    virtual string toString() const
    {
        return "EST UN " + string(typeid(*ftemoin).name());
    }

    virtual bool verif(const Figure * f) const
    {
       if (typeid(*ftemoin) == typeid(*f))
               return true;
        return false;
    }

private :
    const Figure * ftemoin;
};
#endif
