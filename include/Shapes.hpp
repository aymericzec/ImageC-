#ifndef __SHAPESENUM__
#define __SHAPESENUM__

#include <algorithm>
#include <string>

namespace enumShapes {
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
