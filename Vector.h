#ifndef VECTOR_BB
#define VECTOR_BB
#include "Planet.h"

class Vector {
	// Private Variables
public:
	Vector();
	~Vector();
	void insert(int,Planet *);
	Planet * read(int);
	bool remove(int);
	unsigned size();
}

#endif
