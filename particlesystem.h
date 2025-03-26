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
//	int ROWS = 0;
//	int COLS = 0;
   // [auto [rows,cols] =  get_terminal_size()];
   public:
	int ROWS = 0;
	int COLS = 0;
	ParticleSystem();
	~ParticleSystem();
	void add(int amount);
	void pop_back();
	void drawParticles();
	void moveParticles();
	int get_Size();
};
    //auto [rows,cols] =  get_terminal_size();
	//rows--;
//	cols--;
	//  ROWS = rows;
//	COLS = COLS;
	// Top left (0,0) Top Right (0, Cols)
	// Bottom Left ( Rows,0) Bottom Right ( Rows Cols)
	// Added screenSize function & stub - Mar 20 7:50 PM
	
		//int rows = rows;
		//int cols = cols;
		
		//std::cout << "rows " << rows << std::endl;
		//std::cout << "cols " << cols << std::endl;
	
/*
    // Destructor-FM
	~ParticleSystem() {
	//	Cell  *current = head;
	//	while(current) {
	//	Cell *temp = current;
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
	void pop_back() {
		//Cell* temp = tail; 
		tail->set_prev() = nullptr; 
		delete tail;
		size--;
	}
	int numParticle(){
	// Stub numParticle 
	return 1;
	};
	void drawParticles(){
		// Added loop that iteration throught loops for Project Milestone #2-FM
		for (Cell* temp = head; temp; temp = temp->get_next()) {
			temp->get_particle().drawParticle();	
		}
	};
	void  moveParticles(){
		// Added loop that iteration throught loops for Project Milestone #2-FM
		for (Cell* temp = head; temp; temp = temp->get_next()) {	
			temp->get_particle().physics();	
		}
		//return 1; 
	};
	// Get size function-FM 
	int get_Size() {
		return size; 
	};

};*/
#endif

