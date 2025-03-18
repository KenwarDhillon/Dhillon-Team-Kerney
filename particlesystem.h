#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include <iostream>
class ParticleSystem{
	void add(Particle particle){}
	int numParticle(){
	return 1;
	};
	void drawParticles(){
		std::cout << "Calling drawParticles method" <<std:: endl;
	};
	int moveParticles(){
		return 1; 
	};

};
#endif

