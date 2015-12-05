// Includes
#include "Path.h"

// Constructors
path::path()
{
	//_vertices = empty!
	_distance_traveled = 0;
}
path::path(stack<vertex*> new_vertices, int new_distance_traveled)
{
	_vertices = new_vertices;
	_distance_traveled = new_distance_traveled;
}

// Copy Consturctor

// Destructor

// Getters
stack<vertex*> path::get_vertices() const
{
	return _vertices;
}
int path::get_distance_traveled() const
{
	return _distance_traveled;
}

// Setters
void path::set_vertices(stack<vertex*> new_vertices)
{
	_vertices = new_vertices;
}
void path::set_distance_traveled(int new_distance_traveled)
{
	_distance_traveled = new_distance_traveled;
}

// Methods