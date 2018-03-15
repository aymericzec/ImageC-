#include <sstream>
#include <algorithm>
#include "Line.hpp"
#include "Matrice2D.hpp"
#include "Image.hpp"
#include <MLV/MLV_all.h>

using namespace std;

void testLine () {
	Line l1 = Line(Point(10, 20), Point(16, 30), Point(0,0));
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
	Line l1 = Line(Point(0,0), Point(15,15), Point(0,0));
	
	image.add(l1);
	image.draw();
	image.translation(Point(15,15));
	image.draw();
}

void testLineMlv () {
	
	int width = 640, height = 460;
	
	MLV_create_window("medium - 2 - mouse events", "mouse events", width, height);

	Line l1 = Line(Point(200,200), Point(300,300), Point(250, 250));
	
	Point origin = l1.getOrigin();
	Point extrimity = l1.getExtremity();
	
	cout << origin.getX() << " " << origin.getY() << " " << extrimity.getX() << " " << extrimity.getY() << endl;
	
	MLV_draw_line(origin.getX(), origin.getY(), extrimity.getX(), extrimity.getY(),  MLV_COLOR_GREEN); 		
	MLV_draw_filled_circle 	(275,225, 2, MLV_COLOR_YELLOW);
	MLV_actualise_window();
	int a;
	cout << "Appuyé sur un chiffre pour tester la translation: ";
	cin >> a;
	
	l1.translation(Point(0,200));
	origin = l1.getOrigin();
	extrimity = l1.getExtremity();
	cout << origin.getX() << " " << origin.getY() << " " << extrimity.getX() << " " << extrimity.getY() << endl;

	MLV_draw_line(origin.getX(), origin.getY(), extrimity.getX(), extrimity.getY(),  MLV_COLOR_GREEN); 		
	MLV_actualise_window();


	cout << "Appuyé sur un chiffre pour tester la rotation: ";
	cin >> a;
	
	l1 = Line(Point(200,200), Point(300,300), Point(250, 250));
	
	l1.rotation(1.57);
	origin = l1.getOrigin();
	extrimity = l1.getExtremity();
	cout << origin.getX() << " " << origin.getY() << " " << extrimity.getX() << " " << extrimity.getY() << endl;

	MLV_draw_line(origin.getX(), origin.getY(), extrimity.getX(), extrimity.getY(),  MLV_COLOR_RED); 		
	MLV_actualise_window();
	
	cout << "Appuyé sur un chiffre pour tester l'homothétie: ";
	cin >> a;
	
	l1 = Line(Point(200,200), Point(300,300), Point(250, 250));
	
	l1.homothety(Point(1,1));
	origin = l1.getOrigin();
	extrimity = l1.getExtremity();
	cout << origin.getX() << " " << origin.getY() << " " << extrimity.getX() << " " << extrimity.getY() << endl;

	MLV_draw_line(origin.getX(), origin.getY(), extrimity.getX(), extrimity.getY(),  MLV_COLOR_YELLOW); 		
	MLV_actualise_window();

	
	
	
	cout << "Appuyé sur un chiffre pour tester la symétrie centrale: ";
	cin >> a;
	
	l1 = Line(Point(200,200), Point(300,300), Point(275, 225));
	
	l1.centralSymmetry();
	origin = l1.getOrigin();
	extrimity = l1.getExtremity();
	cout << origin.getX() << " " << origin.getY() << " " << extrimity.getX() << " " << extrimity.getY() << endl;

	MLV_draw_line(origin.getX(), origin.getY(), extrimity.getX(), extrimity.getY(),  MLV_COLOR_YELLOW); 		
	MLV_actualise_window();
	
	cout << "Appuyé sur un chiffre pour tester la symétrie X: ";
	cin >> a;
	
	l1 = Line(Point(200,200), Point(300,300), Point(275, 225));
	
	l1.axialSymmetryX();
	origin = l1.getOrigin();
	extrimity = l1.getExtremity();
	cout << origin.getX() << " " << origin.getY() << " " << extrimity.getX() << " " << extrimity.getY() << endl;

	MLV_draw_line(origin.getX(), origin.getY(), extrimity.getX(), extrimity.getY(),  MLV_COLOR_BLUE); 		
	MLV_actualise_window();
	
	cout << "Appuyé sur un chiffre pour tester la symétrie Y: ";
	cin >> a;
	
	l1 = Line(Point(200,200), Point(300,300), Point(275, 225));
	
	l1.axialSymmetryY();
	origin = l1.getOrigin();
	extrimity = l1.getExtremity();
	cout << origin.getX() << " " << origin.getY() << " " << extrimity.getX() << " " << extrimity.getY() << endl;

	MLV_draw_line(origin.getX(), origin.getY(), extrimity.getX(), extrimity.getY(),  MLV_COLOR_GREEN); 		
	MLV_actualise_window();
	
	cout << "Appuyé sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window();
	
}

int main (void) {
	testLineMlv();
	
	
	
    return 0;
}
