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
#include "Shapes.hpp"
#include <unistd.h>
 
 
using namespace std;
 
 
void lineMLV() {
     
    int width = 1000, height = 600;
     
    MLV_create_window("Lignes", "Lignes", width, height);
    MLV_draw_filled_rectangle(0, 0, width, height, MLV_COLOR_BLACK);
 
    Line l1 = Line(Point(400,300), Point(600,300));
     
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
 
    Circle c1 = Circle(Point(300,300), Point(340,300));
     
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
 
    Rectangle r1 = Rectangle(Point(400,300), Point(500,400));
     
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
 
    Triangle t1 = Triangle(Point(300,200), Point(500,200), Point(400, 400));
     
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
 
    Line l1 = Line(Point(400,300), Point(600,300));
    Circle c1 = Circle(Point(300,300), Point(340,300));
    Rectangle r1 = Rectangle(Point(400,300), Point(500,400));
    Triangle t1 = Triangle(Point(300,200), Point(500,200), Point(400, 400));
     
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
     
    shared_ptr<Shape> shape = ParseFile::parseFile("./Images/image1.txt");
    shape->drawMLV();
    cout << shape->getOrigin() << endl;
    MLV_actualise_window();
     
    int a;
     
    cout << "Appuyez sur un chiffre pour terminer";
    cin >> a;
     
    MLV_free_window(); 
}
 
 
void filter () {
     
    Image image(Point(500,500));
    image.add(Circle(Point(100,100), Point(500,500)));
    image.add(Rectangle(Point(200,200), Point(600,600)));
     
    Image image2(Point(500,500));
    image2.add(Circle(Point(500,500), Point(800,800)));
     
    image.add(image2);
    image.add(Image(Point(500,500)));
    image.add(Circle(Point(500,500), Point(800,800)));
    image.add(Rectangle(Point(200,200), Point(600,600)));
 
    cout << image << endl;
     
    cout << endl << endl;
     
    list<shared_ptr<Shape>> s = image.sortPerimeter();
     
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
 
void demo(){
    int width = 1000, height = 600;
    MLV_Keyboard_button touche;
     
    MLV_create_window("Demonstration", "Demonstration", width, height);
    cout << "Voici un scénario de demonstration qui montre l'ensemble des fonctionnalitées possible" << endl;
    cout << "Cette demonstration se deroule étape par étape" << endl;
    cout << "Appuyer sur une touche du clavier pour passé à l'étape suivante" << endl;
 
    cout << endl;
    cout << "Creation d'Image 1 de centre (300, 300)" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    Image image(Point(300,300));
    MLV_draw_circle( 300, 300, 0, MLV_COLOR_YELLOW );
    image.drawMLV();     
    MLV_actualise_window();
     
    cout << "Image 1 : Creation d'un cercle" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
 
    image.add(Circle(Point(300,150), Point(300,200)));
    image.drawMLV();     
    MLV_actualise_window();
     
    cout << "Image 1 : Creation d'une ligne" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    image.add(Line(Point(200,450), Point(400,400)));
    image.drawMLV();     
    MLV_actualise_window();
 
    cout << "Creation d'Image 2 de centre (700,300)" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    Image image2(Point(700,300));
    MLV_draw_circle( 700, 300, 0, MLV_COLOR_BLUE );
    image2.drawMLV();     
    MLV_actualise_window();
 
    cout << "Image 2 : Creation d'un rectangle" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    image2.add(Rectangle(Point(600,150), Point(750,200)));
    image2.drawMLV();     
    MLV_actualise_window();
 
    cout << "Image 2 : Creation d'un triangle" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    Triangle t = Triangle(Point(600,550), Point(700,350), Point(800, 550));
    image2.add(t);
    image2.drawMLV();     
    MLV_actualise_window();
     
    cout << "Image 1 : Homotecie *2" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    image.homothety(Point(2,2));
    MLV_clear_window(MLV_COLOR_BLACK);
    image.drawMLV();
    image2.drawMLV();
    MLV_actualise_window();
     
    cout << "Image 2 : Triangle : symetrie central" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    //Récupère le premier triangle
    list<shared_ptr<Shape>> l = image2.searchShape(Shapes::TRIANGLE);
    l.front()->centralSymmetry();
    MLV_clear_window(MLV_COLOR_BLACK);
    image.drawMLV();
    image2.drawMLV();
    MLV_actualise_window();
     
    cout << "Image 1 : symetrie axial" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    image.axialSymmetryX();  
    MLV_clear_window(MLV_COLOR_BLACK);
    image.drawMLV();
    image2.drawMLV();
    MLV_actualise_window();
     
    cout << "Image 2 : Triangle : rotation 90°" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    l.front()->rotation(90); 
    MLV_clear_window(MLV_COLOR_BLACK);
    image.drawMLV();
    image2.drawMLV();
    MLV_actualise_window();
     
 
    cout << "Appuyez sur une touche pour terminer" << endl;
    MLV_wait_keyboard( &touche, NULL, NULL );
    MLV_free_window();
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
        cout << "7 : Demonstration " << endl;
        cout << "Votre choix : ";
        cin >> choix;
    }
    while (choix < 1 || choix > 7);
 
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
    case 7 :
        demo();
        break;
    default :
        cout << "Choix invalide " << endl;
        break;
    }
 
    return 0;
} 