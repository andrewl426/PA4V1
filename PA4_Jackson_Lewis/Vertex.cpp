// Includes
#include "Vertex.h"

// Constructors
vertex::vertex()
{
	_id = 0;
	//_edges = empty!
	_load_factor = 0;
	_path_weight = 0;
}
vertex::vertex(int new_id, unordered_map<vertex*, int> new_edges, int new_load_factor)
{
	_id = new_id;
	_edges = new_edges;
	_load_factor = new_load_factor;
	_path_weight = 0;
}

// Copy Consturctor

// Destructor

// Getters
int vertex::get_id() const
{
	return _id;
}
unordered_map<vertex*, int> vertex::get_edges()
{
	return _edges;
}
int vertex::get_load_factor()
{
	return _load_factor;
}
int vertex::getPathWeight() const
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
void vertex::set_path_weight(int new_weight)
{
	_path_weight = new_weight;
}

// Methods