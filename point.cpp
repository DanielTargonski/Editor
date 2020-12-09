//File name: pointImp.cpp
//Statement of Purpose: Implementation file for point class
//Author: Daniel Targonski
//Date: 9/9/2020

#include"point.h"
using namespace std;

Point::Point() : mX(0), mY(0) //Initializers can only be used with constructors.
{
} // end point default constructor

Point::Point(int inX, int inY) : mX(inX), mY(inY)
{
} //end point

void Point::setX(int inX)
{
	mX = inX;
} //end setX

void Point::setY(int inY)
{
	mY = inY;
} //end setY

int Point::getX() const
{
	return mX;
} // end getX

int Point::getY() const
{
	return mY;
} //end getY

double Point::distance(const Point& p2)
{
	return sqrt(pow((p2.mY - mY), 2) + pow((p2.mX - mX), 2));
} //end distance

void Point::display()
{
	cout << "(" << getX() << ',' << getY() << ')';
} //end display

bool Point::operator==(const Point& p2) const
{
	return ((mX == p2.mX) &&
		(mY == p2.mY));
} // end operator==

ostream& operator<<(ostream& os, Point& point)
{
	os << '(' << point.getX() <<
		',' << point.getY() << ')';
	return os;
}
