#include "List.h"

List::List() {
	// Construct lists
}

List::~List() {
	// Destruct lists
}

void List::insert(int index) {
	// Insert element at index, increase list size by 1
	// If index is out of bounds, simply append it to the end of the list and increase size
}

Planet * List::read(int index) {
	// Return a pointer to the Planet at index
	// If index is out of bounds, return NULL
}

bool List::remove(int index) {
	// Remove Planet object at index, decrease vector size by 1
	// Return false if index out of bounds, otherwise true on successful deletion
}

unsigned List::size() {
	// Return the current size of the list
}
