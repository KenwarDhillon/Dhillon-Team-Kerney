#include "ParticleGraphics.h"
#include "/public/colors.h"
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

  void ParticleGraphics::drawPoint(double x, double y, int r, int b, int g) const{ 		//draws single point at specified coordinates given in the paramter - RC
	resetcolor();																									//params take x&y of first corner and x&y of second corner
	setbgcolor(r,b, g);																			//int r = red int b = blue int g = green allows to set color
	movecursor(y,x);
    cout << "*";
    cout.flush();
	resetcolor();
      }
  void ParticleGraphics::drawLine(double x1, double y1, double x2, double y2, int r, int b, int g) const {			//draws line connecting two points
      int dx = abs(x2-x1), dy = abs(y2-y1);														//in order, the params take the x and y for starting pt & x and y for ending pt - RC
      int sx = (x1 < x2) ? 1 : -1;
      int sy = (y1 < y2) ? 1 : -1;
      int err = dx - dy;

      while (true) {
          resetcolor();																									//params take x&y of first corner and x&y of second corner
      setbgcolor(r,b, g);
 movecursor(y1, x1);
          cout << "*";
          cout.flush();
		resetcolor();
          if (x1==x2 and y1==y2) break;
          int e2 = err * 2;
          if (e2 > -dy) { err -= dy; x1+= sx; }
          if (e2 < dx) { err += dx; y1+= sy; }
      }
      }
  void ParticleGraphics::drawRectangle(double x1, double y1, double x2, double y2, int r, int b, int g) const { 	//draws rectangle using two corners
	 resetcolor();																									//params take x&y of first corner and x&y of second corner
      setbgcolor(r,b, g);																							//able to set color - RC
      for (int row = y1; row <= y2; row++) {
      for (int col = x1; col <= x2; col++) {
          movecursor(row, col);
          cout << " ";
      }
      }
      cout.flush();
      resetcolor();
      }







//  void ParticleGraphics::drawOval(double x1, double y1, double x2, double y2) const {
  //    double a = (x2 - x1) / 2.0;
  //    double b = (y2 - y1) / 2.0;
    //  double h = x1 + a;
      //double k = y1 + b;

//      for (double angle = 0; angle < 360; angle += 5) {
  //    double rad = angle * 3.14159 / 180;
   //   int x = h + a * cos(rad);
    //  int y = k + b * sin(rad);
    //  movecursor(y, x);
    //  cout << "O";
    //  }
    //  cout.flush();
    //  }
 // void ParticleGraphics::drawPolygon(const vector<pair<double, double>>& points) const {
   //   for (size_t i = 0; i < points.size(); i++) {
     // drawLine(points[i].first, points[i].second, points[(i + 1) % points.size()].first, points[(i + 1) % points.size()].second);
    //  }
     // }
