#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>

class Particle {
	private:
		double x, y; // Position;-KD
		double velocity;
		double lifetime;
	public:
		void draw() const;
		void physics() const;
};

#endif
