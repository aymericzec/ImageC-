/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de cr�ation : 2013-12-21
 * description      : classe d�crivant un point
 */

#ifndef __POINT__
#define __POINT__
#include <iostream>

using namespace std;

class Point
{
public:
    Point(int a = 0, int b = 0);

    int getX () const;
    void setX (int a);
    int getY () const;
    void setY (int b);

    Point operator+ (const Point & p) const;
    Point & operator+= (const Point & p);
    Point & operator= (const Point & p);

    friend ostream & operator<< (ostream & os, const Point & p);
private:
   int x;
   int y;
};
#endif