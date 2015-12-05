// Includes
#include "Path.h"

// Constructors
path::path()
{
	//_vertices = empty!
	_distance_traveled = 0;
}
path::path(std::stack<vertex*> new_vertices, int new_distance_traveled)
{
	_vertices = new_vertices;
	_distance_traveled = new_distance_traveled;
}

// Copy Consturctor

// Destructor

// Getters
const stack<vertex*> path::get_vertices()
{
	return stack<vertex*>();
}
const int path::get_distance()
{
	return 0;
}

// Setters
void path::set_vertices(std::stack<vertex*> _vertices)
{

}
void path::set_distance_traveled(int new_distance_traveled)
{

}

// Methods