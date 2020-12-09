//File: point.h
//Author: Daniel Targonski
//Date: 9/9/2020

#pragma once
#include<iostream>

using namespace std;

class Point {
public:
	Point();

	Point(int inX, int inY);

	void setX(int inX);

	void setY(int inY);

	int getX() const;

	int getY() const;

	// Calculates the distance between two object's coordinate points of class "point"
	// Precondition: p2 is an object of class "point"
	// Postcondition: The distance between the two coordinate pairs is returned as a double.
	// The coordinate are unchanged.
	double distance(const Point &p2);

	// Displays the objects pair of (x,y) coordinates to cout.
	// Precondition: none.
	// Postcondition: Coordinate pair is output to console.
	void display();

	// Compares two pairs of points for equality.
	// Precondition: Both points be initialized.
	// Postcondition: If both pairs are equal, returns true, otherwise, returns false.
	// The points are unchanged.
	bool operator==(const Point&) const;
	friend ostream& operator<<(ostream& os, Point& point);

private:
	int mX, mY;
}; // end point