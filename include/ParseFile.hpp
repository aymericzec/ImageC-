#ifndef __PARSEFILE__
#define __PARSEFILE__
#include <iostream>
#include <memory>
#include "Shape.hpp"
#include "Image.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Line.hpp"
#include "Triangle.hpp"

using namespace std;

class ParseFile {
private:
	static shared_ptr<Image> getImage (stringstream & ss, const Image & parent = Image(Point(0,0)));
	static shared_ptr<Circle> getCircle(stringstream & ss);
	static shared_ptr<Rectangle> getRectangle (stringstream & ss);
	static shared_ptr<Line> getLine (stringstream & ss);
	static shared_ptr<Triangle> getTriangle (stringstream & ss);
	
public:
	static shared_ptr<Shape> parseFile(string name);	
};

#endif
