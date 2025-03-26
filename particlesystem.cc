#include "particlesystem.h"
#include <iostream>
#include "particle.h"
#include "cell.h"
#include "/public/colors.h"

using namespace std;
//cout << "Rows " << ROWS << endl;
//cout << "Cols " << COLS << endl;
ParticleSystem::ParticleSystem() {
	head = nullptr;
	tail = nullptr;
	size = 0;
   auto [rows,cols] = get_terminal_size();
	ROWS = rows;
	COLS = cols;

}

ParticleSystem::~ParticleSystem() {
	Cell* current = head;
	while (current) {
		Cell* temp = current;
		current = current->get_next();
		delete temp;	
	}
}


void ParticleSystem::add(int amount){
	for (int i = 0; i < amount; i++) {
	Cell* temp  = new Cell();
	temp->set_prev(tail);
	if (tail) {
		tail->set_next(temp);
		tail=temp;
	} else {
		head = temp;
		tail = temp;
	}
	size++;
	}
	/*
	Cell* temp = new Cell{nullptr, nullptr, particle};
	if (size == 0) {
		head = tail = temp;
	} else {
		temp->set_prev(tail);
		if (tail) {
			tail->set_next(temp);
			tail = temp;
		} else {
			head = tail = temp;
		}
	}
	size++;
*/
	}

void ParticleSystem::pop_back() {
	if (!tail) return;
	Cell* temp = tail;
	tail = tail->get_prev();
	if (tail) tail->set_next(nullptr);
	else head = nullptr;
	delete temp;
	size--;
}

void ParticleSystem::drawParticles() {
	for (Cell* temp = head; temp; temp = temp->get_next()) {
		temp->get_particle()->drawParticle();
	}
}

void ParticleSystem::moveParticles() {
	for (Cell* temp = head; temp; temp = temp->get_next()) {
	temp->get_particle()->physics();
// Cou;ldn't get out of bounds system to work yet 
	}

	Particle* p = tail->get_particle();
	if ( p->get_x() < 0 || p->get_x() >= COLS || p->get_y() < 0 || p->get_y() >= ROWS || p->get_lifetime()) {
	pop_back();
	}

}
int ParticleSystem::get_Size() {
	return size;
}
