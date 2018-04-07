/**
 * \file Point.cpp
 * \brief Implémentation d'une classe représentant un Point
 * \author Zecchini.A Moreau.A Vieira Noro.K
 * \version 1.0
 * \date 23 Mars 2018
 *
 * Classe qui permet de représenter un Point.
 *
 */
#include "Point.hpp"

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

