#include "Shape.hpp"

ostream & operator<< (ostream & os, const Figure & figure) {
	figure.afficher(os);
	return os;
}

bool operator== (const Figure & f) const {
	    return (this == &f);
}
