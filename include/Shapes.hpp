/**
 * \file Shapes.hpp
 * \brief Classe représentant une Enum de Figure
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Stocke des constantes de Figures ainsi qu'une méthode statique pour convertir un nom en Enum
 *
 */
#ifndef __SHAPESENUM__
#define __SHAPESENUM__

#include <algorithm>
#include <string>

namespace enumShapes {
	
	/**
	 * \enum Shapes
	 * \brief Constantes de Figure
	 *
	 * Suite de Figures: IMAGE, CIRCLE, RECTANGLE? LINE, TRIANGLE, NONE
	 */
	enum class Shapes { 
		IMAGE, CIRCLE, RECTANGLE, LINE, TRIANGLE, NONE
	};
	
	class ShapesManager {
		public:
			static Shapes convertStringtoEnum (string s) {
				std::transform(s.begin(), s.end(), s.begin(), ::tolower);
				if (s.compare("image") == 0) {
					return Shapes::IMAGE;
				} else if (s.compare("circle") == 0) {
					return Shapes::CIRCLE;
				} else if (s.compare("rectangle") == 0) {
					return Shapes::RECTANGLE;
				} else if (s.compare("line") == 0) {
					return Shapes::LINE;
				} else if (s.compare("triangle") == 0) {
					return Shapes::TRIANGLE;
				} else {
					return Shapes::NONE;
				}
			}
	};
}



#endif
