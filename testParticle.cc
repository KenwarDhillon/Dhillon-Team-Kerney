#include "particle.h"
#include <iostream>
#include <cassert>
using namespace std;

void run_tests() {
	cout << "Running the Particle Tests..." << endl;

	Particle p1;
	assert(p1.get_x() == 0.0);
	assert(p1.get_y() == 0.0);

	cout << "All your Particle Tests passed." << endl;
}

int main() {
	run_test();

	return 0;
}
