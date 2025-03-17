#include "particle.h"
#include <iostream>
#include <cassert>
using namespace std;

void run_tests() {
	cout << "Running the Particle Tests..." << endl;

	cout << endl;

	// This is testing the default constructor and creates a default particle;-KD

	Particle p1;
	assert(p1.get_x() == 0.0);
	assert(p1.get_y() == 0.0);
	assert(p1.get_dx() == 0.0);
	assert(p1.get_dy() == 0.0);
	assert(p1.get_lifetime() == 0);
	assert(p1.get_type() == ParticleType::BALLISTIC);
	cout << "All default constructor tests passed." << endl;

	// This is testing the paramterized constructor and creates a particle with values;-KD

	Particle p2(4.5, 6.5, 1.0, -3.0, 85, ParticleType::FIREWORK);
	assert(p2.get_x() == 4.5);
	assert(p2.get_y() == 6.5);
	assert(p2.get_dx() == 1.0);
	assert(p2.get_dy() == -3.0);
	assert(p2.get_lifetime() == 85);
	assert(p2.get_type() == ParticleType::FIREWORK);
	cout << "All paramterized constructor tests passed." << endl;

	// This is testing the setters;-KD

	p1.set_x(8.6);
	p1.set_y(12.5);
	p1.set_dx(3.5);
	p1.set_dy(-4.1);
	p1.set_lifetime(95);
	p1.set_type(ParticleType::STREAMER);

	assert(p1.get_x() == 8.6);
	assert(p1.get_y() == 12.5);
	assert(p1.get_dx() == 3.5);
	assert(p1.get_dy() == -4.1);
	assert(p1.get_lifetime() == 95);
	assert(p1.get_type() == ParticleType::STREAMER);
	cout << "All setter tests passed." << endl;

	cout << "Good job, all your Particle Tests passed!" << endl;
}

int main() {
	run_tests();

	return 0;
}
