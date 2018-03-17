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

void testRectangleMlv () {
	
	int width = 640, height = 460;
	
	MLV_create_window("medium - 2 - mouse events", "mouse events", width, height);

	Rectangle r1 = Rectangle(Point(200,200), Point(400,400), Point(300,300));
	
	int vx[] = {r1.getA().getX(), r1.getB().getX(), r1.getD().getX(), r1.getC().getX()};
	int vy[] = {r1.getA().getY(), r1.getB().getY(), r1.getD().getY(), r1.getC().getY()};
	
	MLV_draw_filled_circle 	(r1.getA().getX(), r1.getA().getY(), 2, MLV_COLOR_YELLOW);
	MLV_draw_filled_circle 	(r1.getB().getX(), r1.getB().getY(), 2, MLV_COLOR_RED);
	MLV_draw_filled_circle 	(r1.getC().getX(), r1.getC().getY(), 2, MLV_COLOR_BLUE);
	MLV_draw_filled_circle 	(r1.getD().getX(), r1.getD().getY(), 2, MLV_COLOR_GREEN);
	
	MLV_draw_polygon(vx, vy, 4, MLV_COLOR_GREEN); 	
	MLV_actualise_window();
	int a;
	cout << "Appuyé sur un chiffre pour tester la translation: ";
	cin >> a;
	
	r1 = Rectangle(Point(200,200), Point(400,400), Point(300,300));
	r1.translation(Point(10,10));
	int vx2 [] = {r1.getA().getX(), r1.getB().getX(), r1.getD().getX(), r1.getC().getX()};
	int vy2 [] = {r1.getA().getY(), r1.getB().getY(), r1.getD().getY(), r1.getC().getY()};
	
	
	MLV_draw_polygon(vx2, vy2, 4, MLV_COLOR_GREEN); 	
	MLV_actualise_window();
	
	cout << "Appuyé sur un chiffre pour tester la rotation: ";
	cin >> a;

	r1 = Rectangle(Point(200,200), Point(400,400), Point(300,300));
	r1.rotation(0.785398);
	int vx3 [] = {r1.getA().getX(), r1.getB().getX(), r1.getD().getX(), r1.getC().getX()};
	int vy3 [] = {r1.getA().getY(), r1.getB().getY(), r1.getD().getY(), r1.getC().getY()};
	
	MLV_draw_polygon(vx3, vy3, 4, MLV_COLOR_BLUE); 	
	MLV_actualise_window();	

	cout << "Appuyé sur un chiffre pour tester l'homothétie: ";
	cin >> a;

	r1 = Rectangle(Point(100,100), Point(200,200), Point(150,150));
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	r1.homothety(Point(2,2));
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	int vx4 [] = {r1.getA().getX(), r1.getB().getX(), r1.getD().getX(), r1.getC().getX()};
	int vy4 [] = {r1.getA().getY(), r1.getB().getY(), r1.getD().getY(), r1.getC().getY()};
	
	MLV_draw_polygon(vx4, vy4, 4, MLV_COLOR_BLUE); 	
	MLV_actualise_window();	

	cout << "Appuyé sur un chiffre pour tester la symétrie centrale: ";
	cin >> a;
	
	r1 = Rectangle(Point(100,100), Point(200,200), Point(200,200));
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	r1.centralSymmetry();
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	int vx5 [] = {r1.getA().getX(), r1.getB().getX(), r1.getD().getX(), r1.getC().getX()};
	int vy5 [] = {r1.getA().getY(), r1.getB().getY(), r1.getD().getY(), r1.getC().getY()};
	
	MLV_draw_polygon(vx5, vy5, 4, MLV_COLOR_BLUE); 	
	MLV_actualise_window();	
	
	cout << "Appuyé sur un chiffre pour tester la symétrie X: ";
	cin >> a;

	r1 = Rectangle(Point(100,100), Point(200,200), Point(200,200));
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	r1.axialSymmetryX();
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	int vx7 [] = {r1.getA().getX(), r1.getB().getX(), r1.getD().getX(), r1.getC().getX()};
	int vy7 [] = {r1.getA().getY(), r1.getB().getY(), r1.getD().getY(), r1.getC().getY()};
	
	MLV_draw_polygon(vx7, vy7, 4, MLV_COLOR_BLUE); 	
	MLV_actualise_window();	
	
	cout << "Appuyé sur un chiffre pour tester la symétrie Y: ";
	cin >> a;

	r1 = Rectangle(Point(100,100), Point(200,200), Point(200,200));
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	r1.axialSymmetryY();
	
	cout << r1.getA() << " " << r1.getB() << " " << r1.getC() << " " << r1.getD() << endl;
	
	int vx6 [] = {r1.getA().getX(), r1.getB().getX(), r1.getD().getX(), r1.getC().getX()};
	int vy6 [] = {r1.getA().getY(), r1.getB().getY(), r1.getD().getY(), r1.getC().getY()};
	
	MLV_draw_polygon(vx6, vy6, 4, MLV_COLOR_BLUE); 	
	MLV_actualise_window();	
	
	cout << "Appuyé sur un chiffre pour terminer";
	cin >> a;
	
	MLV_free_window();
	
}

void testTriangleMlv () {  
    int width = 640, height = 460; 
     
    MLV_create_window("medium - 2 - mouse events", "mouse events", width, height); 
 
    Triangle t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), Point(300,300)); 
     
    int vx[] = {t1.getA().getX(), t1.getB().getX(), t1.getC().getX()}; 
    int vy[] = {t1.getA().getY(), t1.getB().getY(), t1.getC().getY()}; 
     
    MLV_draw_polygon(vx, vy, 3, MLV_COLOR_GREEN);      
    MLV_actualise_window(); 
    int a; 
    cout << "Appuyé sur un chiffre pour tester la translation: "; 
    cin >> a; 
     
    t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), Point(300,300)); 
    t1.translation(Point(10,10)); 
    int vx2 [] = {t1.getA().getX(), t1.getB().getX(), t1.getC().getX()}; 
    int vy2 [] = {t1.getA().getY(), t1.getB().getY(), t1.getC().getY()}; 
     
     
    MLV_draw_polygon(vx2, vy2, 3, MLV_COLOR_GREEN);      
    MLV_actualise_window(); 
     
    cout << "Appuyé sur un chiffre pour tester la rotation: "; 
    cin >> a; 
 
    t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), Point(300,300)); 
    t1.rotation(0.785398); 
    int vx3 [] = {t1.getA().getX(), t1.getB().getX(), t1.getC().getX()}; 
    int vy3 [] = {t1.getA().getY(), t1.getB().getY(), t1.getC().getY()}; 
     
    MLV_draw_polygon(vx3, vy3, 3, MLV_COLOR_BLUE);      
    MLV_actualise_window();     
 
    cout << "Appuyé sur un chiffre pour tester l'homothétie: "; 
    cin >> a; 
 
    t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), Point(300,300)); 
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    t1.homothety(Point(2,2)); 
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    int vx4 [] = {t1.getA().getX(), t1.getB().getX(), t1.getC().getX()}; 
    int vy4 [] = {t1.getA().getY(), t1.getB().getY(), t1.getC().getY()}; 
     
    MLV_draw_polygon(vx4, vy4, 3, MLV_COLOR_BLUE);      
    MLV_actualise_window();     
 
    cout << "Appuyé sur un chiffre pour tester la symétrie centrale: "; 
    cin >> a; 
     
    t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), Point(300,300));
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    t1.centralSymmetry(); 
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    int vx5 [] = {t1.getA().getX(), t1.getB().getX(), t1.getC().getX()}; 
    int vy5 [] = {t1.getA().getY(), t1.getB().getY(), t1.getC().getY()}; 
     
    MLV_draw_polygon(vx5, vy5, 3, MLV_COLOR_BLUE);      
    MLV_actualise_window();     
     
    cout << "Appuyé sur un chiffre pour tester la symétrie X: "; 
    cin >> a; 
 
    t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), Point(300,300)); 
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    t1.axialSymmetryX(); 
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    int vx7 [] = {t1.getA().getX(), t1.getB().getX(), t1.getC().getX()}; 
    int vy7 [] = {t1.getA().getY(), t1.getB().getY(), t1.getC().getY()}; 
     
    MLV_draw_polygon(vx7, vy7, 3, MLV_COLOR_BLUE);      
    MLV_actualise_window();     
     
    cout << "Appuyé sur un chiffre pour tester la symétrie Y: "; 
    cin >> a; 
 
    t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), Point(300,300)); 
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    t1.axialSymmetryY(); 
     
    cout << t1.getA() << " " << t1.getB() << " " << t1.getC() << endl; 
     
    int vx6 [] = {t1.getA().getX(), t1.getB().getX(), t1.getC().getX()}; 
    int vy6 [] = {t1.getA().getY(), t1.getB().getY(), t1.getC().getY()}; 
     
    MLV_draw_polygon(vx6, vy6, 3, MLV_COLOR_BLUE);      
    MLV_actualise_window();     
     
    cout << "Appuyé sur un chiffre pour terminer"; 
    cin >> a; 
     
    MLV_free_window(); 
     
}

void testCircleMlv () {  
    int width = 640, height = 460; 
     
    MLV_create_window("medium - 2 - mouse events", "mouse events", width, height); 
 
    Circle t1 = Circle(Point(200,200), Point(220,200), Point(200, 200)); 
     
    MLV_draw_circle(t1.getCenter().getX(),t1.getCenter().getY(), t1.getRadius(), MLV_COLOR_YELLOW);
    MLV_actualise_window(); 
    
    int a; 
    cout << "Appuyé sur un chiffre pour tester la translation: "; 
    cin >> a; 
     
    t1 = Circle(Point(200,200), Point(220,200), Point(200, 200)); 
    t1.translation(Point(10,10)); 
    
    MLV_draw_circle(t1.getCenter().getX(),t1.getCenter().getY(), t1.getRadius(), MLV_COLOR_YELLOW);
    MLV_actualise_window();
     
    cout << "Appuyé sur un chiffre pour tester la rotation: "; 
    cin >> a; 
 
    t1 = Circle(Point(200,200), Point(220,200), Point(180, 180));  
    t1.rotation(0.785398); 
    
	MLV_draw_circle(t1.getCenter().getX(),t1.getCenter().getY(), t1.getRadius(), MLV_COLOR_YELLOW);
    MLV_actualise_window();    
 
    cout << "Appuyé sur un chiffre pour tester l'homothétie: "; 
    cin >> a; 
 
    t1 = Circle(Point(200,200), Point(220,200), Point(200, 200)); 
          
    t1.homothety(Point(2,2)); 
     
	MLV_draw_circle(t1.getCenter().getX(),t1.getCenter().getY(), t1.getRadius(), MLV_COLOR_YELLOW);
    MLV_actualise_window();    
 
    cout << "Appuyé sur un chiffre pour tester la symétrie centrale: "; 
    cin >> a; 
     
    t1 = Circle(Point(200,200), Point(220,200), Point(200, 200)); 
     
     
    t1.centralSymmetry(); 
     
    MLV_draw_circle(t1.getCenter().getX(),t1.getCenter().getY(), t1.getRadius(), MLV_COLOR_YELLOW);
    MLV_actualise_window();
    cout << "Appuyé sur un chiffre pour tester la symétrie X: "; 
    cin >> a; 
 
    t1 = Circle(Point(200,200), Point(220,200), Point(200, 200)); 
     
     
    t1.axialSymmetryX(); 
     
    MLV_draw_circle(t1.getCenter().getX(),t1.getCenter().getY(), t1.getRadius(), MLV_COLOR_YELLOW);
    MLV_actualise_window();     
     
    cout << "Appuyé sur un chiffre pour tester la symétrie Y: "; 
    cin >> a; 
 
    t1 = Circle(Point(200,200), Point(220,200), Point(200, 200)); 
     
     
    t1.axialSymmetryY(); 
     
    MLV_draw_circle(t1.getCenter().getX(),t1.getCenter().getY(), t1.getRadius(), MLV_COLOR_YELLOW);
    MLV_actualise_window();  
     
    cout << "Appuyé sur un chiffre pour terminer"; 
    cin >> a; 
     
    MLV_free_window(); 
     
}

void testImageMlv ()  {
	int width = 640, height = 460; 
	int a;
    MLV_create_window("medium - 2 - mouse events", "mouse events", width, height); 
    MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	MLV_actualise_window();
	Point origin(width/2, height/2);
	
	Image image;
	
	Line l1 = Line(Point(200,200), Point(250,250), origin);
	Circle c1 = Circle(Point(200,200), Point(220,200), origin);
	Rectangle r1 = Rectangle(Point(200,200), Point(400,400), origin);
	Triangle t1 = Triangle(Point(200,200), Point(400,200), Point(300, 400), origin); 
	
	image.add(l1);
	image.add(c1);
	image.add(r1);
	image.add(t1);
	image.drawMLV();
	MLV_actualise_window();
	
	cout << "Appuyé sur un chiffre pour translatio de l'image"; 
    cin >> a; 
    
    MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
	MLV_actualise_window();
	//image.translation(Point(150,0));
	//image.rotation(3.1416);
	//image.centralSymmetry();
	//image.axialSymmetryX();
	//image.axialSymmetryY();
	image.homothety(Point(2,2));
	image.drawMLV();
	MLV_actualise_window();

	cout << "Appuyé sur un chiffre pour terminer"; 
    cin >> a; 
	
	MLV_free_window(); 
}

void testFile () {
	int width = 1000, height = 1000; 
	MLV_create_window("medium - 2 - mouse events", "mouse events", width, height); 
	shared_ptr<Shape> shape = ParseFile::parseFile("./test/image1.txt");
	shape->drawMLV();
	MLV_actualise_window();
	int a;
	cin >> a;
	MLV_free_window(); 
}

void testFilter () {
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
	
	for (auto a: s) {
		cout << "sss " <<  *a << endl;
	}
	cout << image << endl;
	
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

	cout << "suppresion perimetre inférieur à 2000" << endl;
	image.deletePerimeter(2000);
	cout << "Figure restante(s) " << endl << image << endl;
}

int main (void) {
	//testLineMlv();
	//testRectangleMlv();
	//testTriangleMlv();
	//testCircleMlv();
	//testImageMlv();
	//testFile();
	testFilter();
    return 0;
}
