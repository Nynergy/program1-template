#ifndef LIST_BB
#define LIST_BB
#include "Planet.h"

class List {
	// Private Variables
public:
	List();
	~List();
	void insert(int,Planet *);
	Planet * read(int);
	bool remove(int);
	unsigned size();
}

#endif
