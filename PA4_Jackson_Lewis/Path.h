#ifndef PATH_H
#define PATH_H

// Includes
#include "Includes.h"
#include "Vertex.h"

// Class definition
class path
{
public:
	// Public vars
	std::stack<vertex*> _vertices;
	int _distance_traveled = 0;

	// Constructors
	path();
	path(std::stack<vertex *> new_vertices, int new_distance_traveled);

	// Copy Constructor

	// Destructor

	// Getters
	const std::stack<vertex*> get_vertices();
	const int get_distance();

	// Setters
	void set_vertices(std::stack<vertex*> _vertices);
	void set_distance_traveled(int new_distance_traveled);

	// Methods

private:
};

#endif