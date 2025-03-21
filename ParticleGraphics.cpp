#include "ParticleGraphics.h"
#include "/public/colors.h"
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <iostream>

using namespace std;

  void ParticleGraphics::drawPoint(double x, double y) const{
      movecursor(y,x);
      cout << "*";
      cout.flush();
      }
  void ParticleGraphics::drawLine(double x1, double y1, double x2, double y2) const {
      int dx = abs(x2-x1), dy = abs(y2-y1);
      int sx = (x1 < x2) ? 1 : -1;
      int sy = (y1 < y2) ? 1 : -1;
      int err = dx - dy;

      while (true) {
          movecursor(y1, x1);
          cout << "*";
          cout.flush();
          if (x1==x2 and y1==y2) break;
          int e2 = err * 2;
          if (e2 > -dy) { err -= dy; x1+= sx; }
          if (e2 < dx) { err += dx; y1+= sy; }
      }
      }
  void ParticleGraphics::drawRectangle(double x1, double y1, double x2, double y2, int r, int b, int g) const {
      resetcolor();
      setbgcolor(r,b, g);
      for (int row = y1; row <= y2; row++) {
      for (int col = x1; col <= x2; col++) {
          movecursor(row, col);
          cout << "#";
      }
      }
      cout.flush();
      resetcolor();
      }
  void ParticleGraphics::drawOval(double x1, double y1, double x2, double y2) const {
      double a = (x2 - x1) / 2.0;
      double b = (y2 - y1) / 2.0;
      double h = x1 + a;
      double k = y1 + b;

      for (double angle = 0; angle < 360; angle += 5) {
      double rad = angle * 3.14159 / 180;
      int x = h + a * cos(rad);
      int y = k + b * sin(rad);
      movecursor(y, x);
      cout << "O";
      }
      cout.flush();
      }
  void ParticleGraphics::drawPolygon(const vector<pair<double, double>>& points) const {
      for (size_t i = 0; i < points.size(); i++) {
      drawLine(points[i].first, points[i].second, points[(i + 1) % points.size()].first, points[(i + 1) % points.size()].second);
      }
      }
