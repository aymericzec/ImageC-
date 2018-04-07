/**
 * \file ParseFile.hpp
 * \brief Classe permettant de parser un fichier en une Figure
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui offre une méthode de parsage pour générer une Figure
 *
 */
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

	/**
	 * \fn static shared_ptr<Image> getImage (stringstream & ss, const Image & parent = Image(Point(0,0)))
	 * \brief Méthode privé qui renvoie une image à partir d'un flux d'entrée
	 *
	 * \param stringstream &, const Image &
	 * \return shared_ptr<Image> 
	 */
	static shared_ptr<Image> getImage (stringstream & ss, const Image & parent = Image(Point(0,0)));
	
	/**
	 * \fn static shared_ptr<Circle> getCircle(stringstream & ss)
	 * \brief Méthode privé qui renvoie un Cercle à partir d'un flux d'entrée
	 *
	 * \param stringstream &
	 * \return shared_ptr<Circle>  
	 */	
	static shared_ptr<Circle> getCircle(stringstream & ss, const Image & parent = Image(Point(0,0)));

	/**
	 * \fn static shared_ptr<Rectangle> getRectangle (stringstream & ss)
	 * \brief Permet de renvoyer un rectangle à partir d'un flux d'entrée
	 *
	 * \param stringstream &
	 * \return shared_ptr<Rectangle>
	 */
	static shared_ptr<Rectangle> getRectangle (stringstream & ss, const Image & parent = Image(Point(0,0)));

	/**
	 * \fn shared_ptr<Line> getLine (stringstream & ss)
	 * \brief Permet de renvoyer une ligne à partir d'un flux d'entrée
	 *
	 * \param stringstream &
	 * \return shared_ptr<Line>
	 */
	static shared_ptr<Line> getLine (stringstream & ss, const Image & parent = Image(Point(0,0)));

	/**
	 * \fn static shared_ptr<Triangle> getTriangle (stringstream & ss)
	 * \brief Permet de renvoyer un Triangle à partir d'un flux d'entree
	 *
	 * \param stringstream &
	 * \return shared_ptr<Triangle>
	 */
	static shared_ptr<Triangle> getTriangle (stringstream & ss, const Image & parent = Image(Point(0,0)));
	
public:

	/**
	 * \fn static shared_ptr<Shape> parseFile(string name)
	 * \brief Parse un fichier avec une structure bien définie
	 *
	 * \param string
	 * \return shared_ptr<Shape>
	 */
	static shared_ptr<Shape> parseFile(string name);	
};

#endif
