/**
 * auteurs          : Michel Landschoot
 * mail             : direction@landsnet.com
 * date de création : 2013-12-21
 * description      : impléméntation d'une classe décrivant un point
 */

#include "Point.hpp"

Point::Point(int a, int b) : x(a), y(b)
{
}

int Point::Point::getX() const
{
    return x;
}

void Point::Point::setX(int a)
{
    x = a;
}

int Point::Point::getY() const
{
    return y;
}

void Point::Point::setY(int b)
{
    y = b;
}

Point Point::operator+ (const Point & p) const
{
    return Point(x + p.x, y + p.y);
}

Point & Point::operator+= (const Point & p)
{
    x += p.x;
    y += p.y;
    return *this;
}

Point & Point::operator= (const Point & p)
{
    if (this == &p)
        return *this;

    x = p.x;
    y = p.y;

    return *this;
}

ostream & operator<< (ostream & os, const Point & p)
{
    os << '(' << p.x << ',' << p.y << ')';
    return os;
}

