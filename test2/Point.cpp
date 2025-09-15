#include "Point.h"
#include<iostream>
using namespace std;
int Point::a = 1;
Point::Point()
{
	this->x = 1;
	this->y = 1;
}
Point::Point(const float &x = 1,const  float &y = 1)
{
	this->x = x;
	this->y = y;
}
void Point::show()
{
	cout << x << " " << this->y << endl;
}
Point::~Point()
{
	cout << "ham huy" << endl; 
}
void Point::TT(const float &x)
{
	this->x = x + this->x;
	this->y = x + this->y;
}
int Point ::Getx()
{
	return this->x;
}

int Point::Gety(){
	return this->y;
}
void Point::SetPoint(const int& x, const int& y)
{
	this->x = x;
	this->y = y;
}
void Point::Showa()
{
	cout << Point::a << endl;
}