#ifndef CELL_H
#define CELL_H
#include "particle.h"
class Cell{
	Cell *next = nullptr;
	Cell *prev = nullptr;
	
	Particle* particle;
   public:
    // Default Con 
	Cell() {
	next = nullptr;
	prev = nullptr;
	
	}

	Cell( Cell *new_next, Cell *new_prev, Particle* new_Particle) {
		next = new_next;
		prev = new_prev;
		particle = new_Particle;
	}

	// Setters 
	void set_next (Cell *new_next) {
		next = new_next;
	}

	void set_prev (Cell *new_prev) {
		prev = new_prev;
	}
	void set_particle (Particle* new_particle) {
		particle = new_particle;
	}
	// Getters 
	Cell  *get_next () {
		return next;
	}
	Cell *get_prev () {
		return prev;
	}
	Particle* get_particle () {
		return particle;
	}
};

#endif
