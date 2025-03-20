#include "ParticleGraphics.h"

int main() {
	ParticleGraphics pg;

	pg.setColor("red");
	cout << "Current color is: " << pg.getColor() << endl;
	
	pg.drawPoint(10, 15);
	pg.drawLine(0, 0, 11, 11);
	pg.drawOval(10, 10, 30, 40);
	pg.drawRectangle(5, 5, 20, 20);

	vector<pair<double, double>> polygonPoints = {{0,0}, {10,10}, {20,5}, {30,15}};
	pg.drawPolygon(polygonPoints);
	return 0;
}
