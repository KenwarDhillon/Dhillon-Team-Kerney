#include "particle.h"
#include <iostream>
using namespace std;

void Particle::physics() {
	x = x + dx;
	y = y + dy;

	if (type == ParticleType::BALLISTIC) {
		dy = dy + 1.0;
	}
	else if (type == ParticleType::FIREWORK) {
		if (lifetime <= 0) {
			cout << "💥 Firework exploded at the spot: " << x << "," << y << ") 💥" << endl;
		}
		// (Note: I think that the actual particle explosion code has to be done in particlesystems;-KD)
	}

	lifetime--;
}

// int main() {
	// cout << "Hello World. Testing git push.-KD" << endl;

	// return 0;
// }
