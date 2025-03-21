#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include <iostream>
#include "particle.h"
#include "cell.h"
#include "/public/colors.h"
class ParticleSystem{
	// Head and Tail Pointers-FM
	Cell  *head = nullptr;
	Cell *tail = nullptr;
	// Size-FM
	int size = 0;
   public:
	// Added screenSize function & stub - Mar 20 7:50 PM
	void screenSize() {
		const  auto [rows,cols] = get_terminal_size();
		
		std::cout << "rows " << rows << std::endl;
		std::cout << "cols " << cols << std::endl;
	
	}
    // Destructor-FM
	~ParticleSystem() {
		Cell  *current = head;
		while(current) {
		Cell *temp = current;
		current = current->get_next();
		delete temp;
		}
	}
	// Add Function-FM
	void add(Particle particle){
	Cell *temp = new Cell{nullptr,nullptr,particle};
	// Checking invariants-FM
	if ( size == 0) {
		head = temp; 
		tail = temp;
	} else {
   	temp->set_prev(tail);
	if (tail) {
	tail->set_next(temp);
	tail = temp;
	} else {
		head = temp;
		tail = temp;
	} }
	size++;
	};
	int numParticle(){
	// Stub numParticle 
	return 1;
	};
	void drawParticles(){
		//Stub drawParticles 
		std::cout << "Calling drawParticles method" <<std:: endl;
	};
	int moveParticles(){
		return 1; 
	};
	// Get size function-FM 
	int get_Size() {
		return size; 
	};

};
#endif

