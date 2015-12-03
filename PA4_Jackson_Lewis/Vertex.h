#ifndef VERTEX_H
#define VERTEX_H

// Includes
#include "Includes.h"

// Class definition
class vertex
{
public:
	// Public vars
	int _id = 0;
	std::unordered_map<vertex*, int> _edges;
	int _load_factor = 0;

	// Constructors
	vertex();
	vertex(int new_id, std::unordered_map<vertex*, int> new_edges, int new_load_factor);

	// Copy Constructor

	// Destructor

	// Getters
	const int vertex::get_id();
	const std::unordered_map<vertex*, int> vertex::get_edges();
	const int vertex::get_load_factor();

	// Setters
	void set_id(int new_id);
	void set_edges(std::unordered_map<vertex*, int> new_edges);
	void set_load_factor(int new_load_factor);

	// Methods

private:
};

#endif