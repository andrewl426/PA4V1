// Includes
#include "Vertex.h"

// Constructors
vertex::vertex()
{
	_id = 0;
	//_edges = empty!
	_load_factor = 0;
}
vertex::vertex(int new_id, unordered_map<vertex*, int> new_edges, int new_load_factor)
{
	_id = new_id;
	_edges = new_edges;
	_load_factor = new_load_factor;
}

// Copy Consturctor

// Destructor

// Getters
const int vertex::get_id()
{
	return _id;
}
const unordered_map<vertex*, int> vertex::get_edges()
{
	return _edges;
}
const int vertex::get_load_factor()
{
	return _load_factor;
}
const int vertex::getPathWeight()
{
	return _path_weight;
}

// Setters
void vertex::set_id(int new_id)
{
	_id = new_id;
}
void vertex::set_edges(unordered_map<vertex*, int> new_edges)
{
	_edges = new_edges;
}
void vertex::set_load_factor(int new_load_factor)
{
	_load_factor = new_load_factor;
}
void vertex::setPathWeight(int weight)
{
	_path_weight = weight;
}

// Methods