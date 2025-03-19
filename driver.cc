#include <iostream>
#include "cell.h"
#include "particle.h"
#include "particlesystem.h"


using namespace std;


int main() {
	cout << " Hello world" << endl;
	ParticleSystem PS;
	Particle P;
	
	PS.add(P);

	cout << PS.get_Size() << endl;


}



