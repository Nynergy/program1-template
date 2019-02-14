#ifndef STAR_BB
#define STAR_BB

#include "Planet.h"

class Star{
private:
        int current_planets;
        int next_id;
public:
        Planet ** planets;
        Star();
	~Star();
        int addPlanet();
	bool removePlanet(int);
        Planet * getFurthest();
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets() { return this->current_planets; };
	Planet * getPlanet(int);
        //you may add any additional methodas you may need.
};
#endif
