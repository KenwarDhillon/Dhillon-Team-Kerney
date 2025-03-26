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
	for (Cell* temp = head; temp; temp = temp->get_next()) { // (Note: This part of the code should be correct;-KD)
	temp->get_particle()->physics();
// Cou;ldn't get out of bounds system to work yet 
	}

	// IMPORTANT: NOTE: I commented out this section of Fabian's code;-KD)
	/* Particle* p = tail->get_particle();
	if ( p->get_x() < 0 || p->get_x() >= COLS || p->get_y() < 0 || p->get_y() >= ROWS || p->get_lifetime()) {
	pop_back();
	} */

	// Cull particles and handle FIREWORKS is below;-KD
	Cell* current = head;
	while (current) {
		Cell* next = current->get_next();
		Particle* p = current->get_particle();

		// We handle the FIREWORK explosion here;-KD
		if (p->get_type() == Particle::FIREWORK && p->get_lifetime() <= 0) {
			double x = p->get_x();
			double y = p->get_y();

			for (int i = 0; i < 8; ++i) {
				double angle = i * (3.14159 * 2 / 8);
				double dx = cos(angle);
				double dy = sin(angle);

				Particle* newP = new Particle(x, y, dx, dy, 20, ParticleType::STREAMER);
				Cell* newCell = new Cell(nullptr, tail, newP);
				if (tail) tail->set_next_(newCell);
				else head = newCell;
				size++;
			}
		}
		// We handle culling particles here;-KD
		bool outOfBounds = p->get(x) < 0 || p->get_x() >= COLS || p->get_y() < 0 || p->get_y() >= ROWS;
		if (outOfBounds || p->get_lifetime() <= 0) {
			if (current == head) head = current->get_next();
			if (current == tail) tail = current->get_prev();
			if (current->get_prev()) current->get_prev()->set_next(current->get_next());
			if (current->get_next()) current->get_next()->set_prev(current->get_prev());
			delete p;
			delete current;
			size--;
		}
		current = next;
	}

}
int ParticleSystem::get_Size() {
	return size;
}
