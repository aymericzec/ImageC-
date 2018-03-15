/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : classe décrivant la condition EstUn
 */

#ifndef __IS__
#define __IS8_
#include <cstring>
#include <typeinfo>
#include "Condition.h"
#include "Shape.h"

class Is : public Condition {

public:
    Is(const Shape * s) : ftemoin(s) { }

    virtual ~EstUn() { }

    virtual string toString() const
    {
        return "EST UN " + string(typeid(*ftemoin).name());
    }

    virtual bool verif(const Shape * s) const
    {
       if (typeid(*ftemoin) == typeid(*s))
               return true;
        return false;
    }

private :
    const Figure * ftemoin;
};
#endif
