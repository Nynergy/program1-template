#include "Vector.h"

Vector::Vector() {
	// Construct a vector
}

Vector::~Vector() {
	// Destruct a vector
}

void Vector::insert(int index, Planet * p) {
	// Insert element at index, increase vector size by 1
	// Check if index is out of bounds, and if it is, increase the capacity to the size of the index + 1
}

Planet * Vector::read(int index) {
	// Return a pointer to the Planet at index
	// If index is out of bounds, return NULL
}

bool Vector::remove(int index) {
	// Remove Planet object at index, decrease vector size by 1
}

unsigned Vector::size() {
	// Return current size of the vector (Keep in mind that the size of the vector may not always be the same as the number of elements)
}
