#ifndef PLANET_BB
#define PLANET_BB
class Planet{
	private:
		int id;
		int pos;
		int distance;
		char type;
	public:
		Planet(){this->id=-1;};
		Planet(int);
		~Planet();
	        int orbit();
		long int getID() { return this->id; };
        	int getDistance() { return this->distance; };
        	int getPos() { return this->pos; };
		char getType() { return this->type; };
		char getRandomType();
		//you may add any additional methods you may need.
};
#endif
