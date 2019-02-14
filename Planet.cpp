#include "Planet.h"
#include <iostream>
#include <cstdlib>

Planet::Planet(int distance){
	this->id = &this;
	this->distance = distance;
	this->type = this->getRandomType();
	this->pos = rand() % 360;
}

Planet::~Planet() {}

int Planet::orbit() {
	this->pos = (this->pos + 1) % 360;
	return this->pos;
}

char Planet::getRandomType() {
	char types[] = {'h', 'r', 'g'};
	int index = rand() % 3;
	return types[index];
}
