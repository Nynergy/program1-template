#include "Star.h"
#include "Planet.h"
#include <cstdlib>
#include <iostream>

Star::Star() {
	this->current_planets = 0;
	this->planets = NULL;
}

Star::~Star() {
	for(int i = 0; i < this->current_planets; i++) {
		delete this->planets[i];
		this->planets[i] = NULL;
	}

	delete[] this->planets;
}

int Star::addPlanet() {
	// Create new planet with random distance, increment ID
	int new_distance = rand() % 3000;
	Planet * new_planet = new Planet(new_distance);

	// Calculate new array size and allocate space
	int new_size = this->current_planets + 1;
	Planet ** new_planets = new Planet * [new_size];

	// Copy planets over to new array and set old pointers to NULL
	for(int i = 0; i < this->current_planets; i++) {
		new_planets[i] = this->planets[i];
		this->planets[i] = NULL;
	}

	// Put new planet into adjusted array and update current_planets
	new_planets[this->current_planets] = new_planet;
	this->current_planets = this->current_planets + 1;

	// Free the old planets array and redirect pointer to new planets array
	Planet ** old_planets = this->planets;
	this->planets = new_planets;
	delete[] old_planets;

	// Return the id of the newly added planet
	return new_planet->getID();
}

bool Star::removePlanet(int index) {
	// Determine if this planet exists
	bool foundPlanet = false;
	for(int i = 0; i < this->current_planets; i++) {
		if(this->planets[i]->getID() == index) {
			foundPlanet = true;
			break;
		}
	}

	// Return prematurely if the planet was not found
	if(!foundPlanet) {
		return foundPlanet;
	}

	// Calculate new array size and allocate space
	int new_size = this->current_planets - 1;
	Planet ** new_planets = new Planet * [new_size];

	// Copy all pointers into new array, deleting planet with matching ID
	int j = 0;
	bool deletedPlanet = false;
	for(int i = 0; i < this->current_planets; i++) {
		if(this->planets[i]->getID() == index) {
			delete this->planets[i];
			this->planets[i] = NULL;
			deletedPlanet = true;
		} else {
			new_planets[j] = this->planets[i];
			this->planets[i] = NULL;
			j++;
		}
	}

	// Update current_planets
	this->current_planets = this->current_planets - 1;

	// Free the old planets array and redirect to the new planets array
	Planet ** old_planets = this->planets;
	this->planets = new_planets;
	delete[] old_planets;

	// Return true on success, false on failure
	return deletedPlanet;
}

Planet * Star::getFurthest() {
	Planet * furthest = this->planets[0];
	for(int i = 1; i < this->current_planets; i++) {
		if(this->planets[i]->getDistance() > furthest->getDistance()) {
			furthest = this->planets[i];
		}
	}

	return furthest;
}

void Star::orbit() {
	for(int i = 0; i < this->current_planets; i++) {
		this->planets[i]->orbit();
	}

	return;
}

void Star::printStarInfo() {
	std::cout << "\tThe star has " << this->current_planets << " planets." << std::endl;
	std::cout << "\tPlanets:" << std::endl;
	for(int i = 0; i < this->current_planets; i++) {
		std::cout << "\tPlanet " << this->planets[i]->getType() << this->planets[i]->getID()  << " is " << this->planets[i]->getDistance() << " miles away at position " << this->planets[i]->getPos() << " around the star." << std::endl;
	}

	return;
}

Planet * Star::getPlanet(int index) {
	Planet * ret;
	bool foundPlanet = false;
	for(int i = 0; i < this->current_planets; i++) {
		if(this->planets[i]->getID() == index) {
			ret = this->planets[i];
			foundPlanet = true;
			break;
		}
	}

	if(foundPlanet) {
		return ret;
	} else {
		return NULL;
	}
}
