#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ParticleGraphics {
private:
	string currentColor;
public:
	ParticleGraphics() : currentColor() {} 										 //default constructor

	void setColor(const string& color) {currentColor = color;}  
	string getColor () const {return currentColor;}								//getter & setter

	void drawPoint(double x, double y, int r, int b, int g) const;
	void drawLine(double x1, double y1, double x2, double y2, int r, int b, int g) const;
	void drawRectangle(double x1, double y1, double x2, double y2, int r, int b, int g) const;
//	void drawOval(double x1, double y1, double x2, double y2) const;
//	void drawPolygon(const vector<pair<double,double>>& points) const; 			//stubbed drawing methods
};

