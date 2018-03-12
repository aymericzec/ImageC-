#include <sstream>
#include <list>
#include <algorithm>
#include "ligne.hpp"
#include "matrice2D.hpp"

using namespace std;

/**
 * Un foncteur du conteneur de figures
 */
extern void affiche(const Figure * f);


/**
 * Un foncteur du conteneur de figures
 */
void affiche(const Figure * f)
{
    f->afficher(cout);
    cout << endl;
}

/**
 * Conversion d'un entier en un objet string
 */
string intToString(int n)
{
    /**
     * créer un flux de sort
     */
    ostringstream os;
    /**
     * écrire un nombre dans le flux
     */
    os << n;
    /**
     * récupérer une chaîne de caractères
     */
    return os.str();
}

int main (void) {
    Ligne l1 = Ligne(Point(10, 20), Point(16, 30));
    l1.dessiner(cout);
    cout << "Translation(5,8)" << endl;
    //l1.deplacer(Point(5,8));
    
    //initializer_list<Point &> p = {l1.getOrigine(), l1.getExtremite()};
    Point p = l1.getOrigine();
    //translation(p, l1);
    homothetie(p, l1);
    //l1.dessiner(cout);
    cout << l1 << endl;
}
