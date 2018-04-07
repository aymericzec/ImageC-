/**
 * \file ParseFile.cpp
 * \brief Implémentation d'une classe permettant de parser un fichier contenant des figures.
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un parser.
 *
 */
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include "Shape.hpp"
#include "Shapes.hpp"
#include "Circle.hpp"
#include "Image.hpp"
#include "ParseFile.hpp"

using namespace std;
using namespace enumShapes;

shared_ptr<Image> ParseFile::getImage (stringstream & ss, const Image & parent) {
	int x = 0, y = 0;
	ss >> x >> y;
	
	x += parent.getOrigin().getX();
	y +=  parent.getOrigin().getY();
	
	return make_shared<Image>(Image(Point(x, y)));
}

shared_ptr<Circle> ParseFile::getCircle (stringstream & ss, const Image & parent) {
	int x1 = 0, y1 = 0, x2, y2;
	ss >> x1 >> y1 >> x2 >> y2;
	
	x1 += parent.getOrigin().getX();
	y1 +=  parent.getOrigin().getY();
	
	x2 += parent.getOrigin().getX();
	y2 +=  parent.getOrigin().getY();
	
	cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << endl;
	return make_shared<Circle>(Circle(Point(x1,y1), Point(x2, y2)));
}

shared_ptr<Rectangle> ParseFile::getRectangle (stringstream & ss, const Image & parent) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	ss >> x1 >> y1 >> x2 >> y2;
	
	x1 += parent.getOrigin().getX();
	y1 +=  parent.getOrigin().getY();
	
	x2 += parent.getOrigin().getX();
	y2 +=  parent.getOrigin().getY();
	
	return make_shared<Rectangle>(Rectangle(Point(x1, y1), Point(x2,y2)));
}

shared_ptr<Line> ParseFile::getLine (stringstream & ss, const Image & parent) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	ss >> x1 >> y1 >> x2 >> y2;
	
	x1 += parent.getOrigin().getX();
	y1 +=  parent.getOrigin().getY();
	
	x2 += parent.getOrigin().getX();
	y2 +=  parent.getOrigin().getY();
	
	return make_shared<Line>(Line(Point(x1, y1), Point(x2,y2)));
}

shared_ptr<Triangle> ParseFile::getTriangle (stringstream & ss, const Image & parent) {
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0;
	ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	x1 += parent.getOrigin().getX();
	y1 +=  parent.getOrigin().getY();
	
	x2 += parent.getOrigin().getX();
	y2 +=  parent.getOrigin().getY();
	
	return make_shared<Triangle>(Triangle(Point(x1, y1), Point(x2,y2), Point(x3,y3)));
}

shared_ptr<Shape> ParseFile::parseFile(string name)
{	
	string line;
	shared_ptr<Image> imageHead = nullptr;
	shared_ptr<Image> currentImage = nullptr;
	list<shared_ptr<Image>> fifo;
	ifstream myfile(name);
    
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			stringstream ss(line);
			string s;
			ss >> s;
			
			Shapes enumShape = enumShapes::ShapesManager::convertStringtoEnum(s);
			switch (enumShape) {
				case Shapes::IMAGE:
					cout << "Ajout d'une Image" << endl;
					cout << "Empilement" << endl;
					/*Si c'est la première image*/
					if (nullptr == imageHead) {
						imageHead = getImage(ss);
						currentImage = imageHead;
						fifo.push_back(currentImage);
					} else {
						fifo.push_back(getImage(ss, *currentImage));
						currentImage->add(*fifo.back());
					}
					break;
				case Shapes::CIRCLE:
					cout << "Ajout d'un cercle" << endl;
					imageHead->add(*getCircle(ss, *currentImage));
					break;
				case Shapes::TRIANGLE:
					cout << "Ajout d'un Triangle" << endl;
					imageHead->add(*getTriangle(ss, *currentImage));
					break;
				case Shapes::LINE:
					cout << "Ajout d'une Ligne" << endl;
					imageHead->add(*getLine(ss, *currentImage));
					break;
				case Shapes::RECTANGLE:
					cout << "Ajout d'un Rectangle" << endl;
					imageHead->add(*getRectangle(ss, *currentImage));
					break;
				case Shapes::NONE:
					if (fifo.size() > 0) {
						cout << "Depilement, mis dans header tête" << endl;
						currentImage = fifo.front();
						fifo.pop_front();
					}

					break;
				default:
					cout << "ERROR" << endl;
					break;
			}
		}
		
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}
	
	return imageHead;
}
