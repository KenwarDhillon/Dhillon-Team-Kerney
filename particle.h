#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>

enum ParticleType {
	STREAMER,
	BALLISTIC,
	FIREWORK
};

class Particle {
	private:
		double x, y; // Position;-KD
		double dx, dy; // Velocity;-KD
		int lifetime; // How long the particle lives for;-KD
		ParticleType type; // The type of particle;-KD
	public:
		Particle() { // Default constructor;-KD
			x = 0.0;
			y = 0.0;
			dx = 0.0;
			dy = 0.0;
			lifetime = 0;
			type = ParticleType::STREAMER;
		}

		Particle(double new_x, double new_y, double new_dx, double new_dy, int new_lifetime, ParticleType new_type) : x(new_x), y(new_y), dx(new_dx), dy(new_dy), lifetime(new_lifetime), type(new_type) {} // Paramterized constructor;-KD

		// My getters are below;-KD

		double get_x() const { return x; }
		double get_y() const { return y; }
		double get_dx() const { return dx; }
		double get_dy() const { return dy; }
		int get_lifetime() const { return lifetime; }
		ParticleType get_type() const { return type; }

		// My setters are below;-KD

		void set_x(double new_x) {
			x = new_x;	
		}
		
		void set_y(double new_y) {
			y = new_y;	
		}
		
		void set_dx(double new_dx) {
			dx = new_dx;	
		}
		
		void set_dy(double new_dy) {
			dy = new_dy;	
		}
		
		void set_lifetime(int new_lifetime) {
			lifetime = new_lifetime;	
		}
		
		void set_type(ParticleType new_type) {
			type = new_type;	
		}

		// My stub methods are below;-KD

		// (Note: I commented out the drawParticle() method declaration because I am not supposed to be doing it;-KD)

		/* void drawParticle() const { // This draws the particles on the screen;-KD
			std::cout << "The current particle location is: " << "(" << x << "," << y << ")" << std::endl;	
		} */
		void physics();
};

#endif
