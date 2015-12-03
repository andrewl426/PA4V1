// Includes
#include "Vertex.h"

// Constructors
vertex::vertex()
{
	_id = 0;
	//_edges = empty!
	_load_factor = 0;
}
vertex::vertex(int new_id, std::unordered_map<vertex*, int> new_edges, int new_load_factor)
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
	return 0;
}
const std::unordered_map<vertex*, int> vertex::get_edges()
{
	return std::unordered_map<vertex*, int>();
}
const int vertex::get_load_factor()
{
	return 0;
}

// Setters
void vertex::set_id(int new_id)
{

}
void vertex::set_edges(std::unordered_map<vertex*, int> new_edges)
{

}
void vertex::set_load_factor(int new_load_factor)
{

}

// Methods