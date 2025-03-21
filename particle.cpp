#include "particle.h"
#include <iostream>
using namespace std;

void Particle::physics() {
	x = x + dx;
	y = y + dy;

	if (type == ParticleType::BALLISTIC) {
		dy = dy - 2.0;
	}
	else if (type == ParticleType::FIREWORK) {
		if (lifetime <= 0) {
			cout << "Firework exploded at the spot: " << x << "," << y << ")" << endl;
		}
	}

	lifetime--;
}

int main() {
	cout << "Hello World. Testing git push.-KD" << endl;

	return 0;
}
