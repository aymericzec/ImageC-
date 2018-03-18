#include <sstream>
#include <algorithm>
#include "Line.hpp"
#include "Matrice2D.hpp"
#include "Image.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include <MLV/MLV_all.h>
#include "ParseFile.hpp"
#include "Filter.hpp"
#include "Shapes.hpp"


using namespace std;


void lineMLV() {
	
	int width = 1000, height = 600;
	
	MLV_create_window("Lignes", "Lignes", width, height);
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);

	Line l1 = Line(Point(400,300), Point(600,300), Point(500, 300));
	
	l1.drawMLV();
	MLV_actualise_window();
	
	int a;
	
	cout << "Appuyez sur un chiffre pour tester la translation: ";
	cin >> a;
	
	l1.translation(Point(0,100));

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	l1.drawMLV();	
	MLV_actualise_window();

	cout << "Appuyez sur un chiffre pour tester la rotation: ";
	cin >> a;
	
	l1.rotation(2);

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	l1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester l'homothétie: ";
	cin >> a;
	
	l1.homothety(Point(2,2));
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	l1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie centrale: ";
	cin >> a;
	
	l1.centralSymmetry();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	l1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie X: ";
	cin >> a;
	
	l1.axialSymmetryX();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	l1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie Y: ";
	cin >> a;
	
	l1.axialSymmetryY();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	l1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window();
}


void circleMLV() {
	
	int width = 1000, height = 600;
	
	MLV_create_window("Cercles", "Cercles", width, height);
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);

	Circle c1 = Circle(Point(300,300), Point(340,300), Point(300, 300));
	
	c1.drawMLV();
	MLV_actualise_window();
	
	int a;
	
	cout << "Appuyez sur un chiffre pour tester la translation: ";
	cin >> a;
	
	c1.translation(Point(0,100));

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	c1.drawMLV();	
	MLV_actualise_window();

	cout << "Appuyez sur un chiffre pour tester la rotation: ";
	cin >> a;
	
	c1.rotation(2);

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	c1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester l'homothétie: ";
	cin >> a;
	
	c1.homothety(Point(2,2));
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	c1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie centrale: ";
	cin >> a;
	
	c1.centralSymmetry();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	c1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie X: ";
	cin >> a;
	
	c1.axialSymmetryX();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	c1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie Y: ";
	cin >> a;
	
	c1.axialSymmetryY();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	c1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window();
}


void rectangleMLV() {
	
	int width = 1000, height = 600;
	
	MLV_create_window("Rectangles", "Rectangles", width, height);
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);

	Rectangle r1 = Rectangle(Point(400,300), Point(500,400), Point(450,350));
	
	r1.drawMLV();
	MLV_actualise_window();
	
	int a;
	
	cout << "Appuyez sur un chiffre pour tester la translation: ";
	cin >> a;
	
	r1.translation(Point(0,100));

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	r1.drawMLV();	
	MLV_actualise_window();

	cout << "Appuyez sur un chiffre pour tester la rotation: ";
	cin >> a;
	
	r1.rotation(2);

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	r1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester l'homothétie: ";
	cin >> a;
	
	r1.homothety(Point(2,2));
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	r1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie centrale: ";
	cin >> a;
	
	r1.centralSymmetry();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	r1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie X: ";
	cin >> a;
	
	r1.axialSymmetryX();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	r1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie Y: ";
	cin >> a;
	
	r1.axialSymmetryY();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	r1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window();
}


void triangleMLV() {
	
	int width = 1000, height = 600;
	
	MLV_create_window("Triangles", "Triangles", width, height);
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);

	Triangle t1 = Triangle(Point(300,200), Point(500,200), Point(400, 400), Point(400,300));
	
	t1.drawMLV();
	MLV_actualise_window();
	
	int a;
	
	cout << "Appuyez sur un chiffre pour tester la translation: ";
	cin >> a;
	
	t1.translation(Point(0,100));

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	t1.drawMLV();	
	MLV_actualise_window();

	cout << "Appuyez sur un chiffre pour tester la rotation: ";
	cin >> a;
	
	t1.rotation(2);

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	t1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester l'homothétie: ";
	cin >> a;
	
	t1.homothety(Point(2,2));
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	t1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie centrale: ";
	cin >> a;
	
	t1.centralSymmetry();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	t1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie X: ";
	cin >> a;
	
	t1.axialSymmetryX();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	t1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie Y: ";
	cin >> a;
	
	t1.axialSymmetryY();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	t1.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window();
}


void imageMLV() {
	
	int width = 1000, height = 600;
	
	MLV_create_window("Triangles", "Triangles", width, height);
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	
	Image image;

	Line l1 = Line(Point(400,300), Point(600,300), Point(500, 300));
	Circle c1 = Circle(Point(300,300), Point(340,300), Point(300, 300));
	Rectangle r1 = Rectangle(Point(400,300), Point(500,400), Point(450,350));
	Triangle t1 = Triangle(Point(300,200), Point(500,200), Point(400, 400), Point(400,300));
	
	image.add(l1);
	image.add(c1);
	image.add(r1);
	image.add(t1);
	
	image.drawMLV();
	MLV_actualise_window();
	
	int a;
	
	cout << "Appuyez sur un chiffre pour tester la translation: ";
	cin >> a;
	
	image.translation(Point(0,100));

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	image.drawMLV();	
	MLV_actualise_window();

	cout << "Appuyez sur un chiffre pour tester la rotation: ";
	cin >> a;
	
	image.rotation(2);

	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	image.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester l'homothétie: ";
	cin >> a;
	
	image.homothety(Point(2,2));
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	image.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie centrale: ";
	cin >> a;
	
	image.centralSymmetry();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	image.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie X: ";
	cin >> a;
	
	image.axialSymmetryX();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	image.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour tester la symétrie Y: ";
	cin >> a;
	
	image.axialSymmetryY();
	
	MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	image.drawMLV();	
	MLV_actualise_window();
	
	cout << "Appuyez sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window();
}


void readFile () {
	
	int width = 1000, height = 1000; 
	
	MLV_create_window("Figures géométriques", "Figures géométriques", width, height); 
	
	shared_ptr<Shape> shape = ParseFile::parseFile("./test/image1.txt");
	shape->drawMLV();
	MLV_actualise_window();
	
	int a;
	
	cout << "Appuyez sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window(); 
}


void filter () {
	
	Image image(Point(500,500), Point(500,500));
	image.add(Circle(Point(100,100), Point(500,500)));
	image.add(Rectangle(Point(200,200), Point(600,600)));
	
	Image image2(Point(500,500), Point(600,600));
	image2.add(Circle(Point(500,500), Point(800,800)));
	
	image.add(image2);
	image.add(Image(Point(500,500), Point(500,500)));
	image.add(Circle(Point(500,500), Point(800,800)));
	image.add(Rectangle(Point(200,200), Point(600,600)));

	cout << image << endl;
	
	cout << endl << endl;
	
	list<shared_ptr<Shape>> s = image.sortPerimeter();
	
	/*for (auto a: s) {
		cout << "sss " <<  *a << endl;
	}
	cout << image << endl;*/
	
	s = image.searchShape(Shapes::CIRCLE);
	
	cout << "Recherche de cercle: " << endl;
	for (auto a: s) {
		cout <<  *a << endl;
	}
	
	cout << "Nombre de rectangle: " <<  image.countShape(Shapes::RECTANGLE) << endl;

	cout << "Nombre < 2000: " <<  image.countPerimeter(2000) << endl;
	
	cout << "suppresion des cercles" << endl;
	image.deleteShape(Shapes::CIRCLE);
	cout << image << endl;

	cout << "suppresion perimetre inférieur a 2000" << endl;
	image.deletePerimeter(2000);
	cout << "Figure restante(s) " << endl << image << endl;
}


int main(void)
{
    int choix;
   
    do
    {
		cout << "1 : Ligne " << endl;
        cout << "2 : Cercle " << endl;
        cout << "3 : Rectangle " << endl;
        cout << "4 : Triangle " << endl;
        cout << "5 : Lecture du fichier " << endl;
        cout << "6 : Filtrage des figures " << endl;
        cout << "Votre choix : ";
        cin >> choix;
    }
    while (choix < 1 || choix > 6);

    switch(choix)
	{
    case 1 :
		lineMLV();
        break;
    case 2 :
        circleMLV();
        break;
    case 3 :
        rectangleMLV();
        break;
    case 4 :
        triangleMLV();
        break;
    case 5 :
        readFile();
        break;
    case 6 :
        filter();
        break;
    default :
        cout << "Choix invalide " << endl;
        break;
    }

    return 0;
}
