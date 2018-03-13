#include <sstream>
#include <algorithm>
#include "Line.hpp"
#include "Matrice2D.hpp"
#include "Image.hpp"

using namespace std;

void testLine () {
	Line l1 = Line(Point(10, 20), Point(16, 30));
    cout << "Translation(5,8)" << endl;
    l1.translation(Point(5,8));
    cout << l1 << endl;

    Point p = l1.getOrigin();
    cout << "Homothetie " << p << endl;
    l1.homothety(p);

	double radius = 3.18;
    cout << "Rotation " << radius << endl;
    l1.rotation(radius);
    cout << l1 << endl;
    
    l1.centralSymmetry();
    cout << l1 << endl;
}

void testImage () {
	Image image;
	Line l1 = Line(Point(0,0), Point(15,15));
	
	image.add(l1);
	image.draw();
	image.translation(Point(15,15));
	image.draw();
}

int main (void) {
	testImage();
    return 0;
}
