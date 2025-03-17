#include "ParticleGraphics.h"
#include <iostream>

using namespace std;

void ParticleGraphics::drawPoint(double x, double y) const{
	cout << "Drawing point at (" << x << ", " << y << ")" << endl;
}
void ParticleGraphics::drawLine(double x1, double y1, double x2, double y2) const {
	cout << "Drawing line from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
	}
void ParticleGraphics::drawRectangle(double x1, double y1, double x2, double y2) const {
	cout << "Drawing rectangle with corners (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")" << endl;
	}
void ParticleGraphics::drawOval(double x1, double y1, double x2, double y2) const {
	cout << "Drawing oval inside a rectangle with corners (" << x1 << ", " << y1 << ") and (" << x2 << ", " << y2 << ")" << endl;
	}
void ParticleGraphics::drawPolygon(const vector<pair<double, double>>& points) const {
	cout << "Drawing polygon with points: ";
		for (const auto& point : points) {
			cout << "(" << point.first << ", " << point.second << ") ";
		} cout << endl;
	}


