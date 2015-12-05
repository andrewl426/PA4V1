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
	unordered_map<vertex*, int> _edges;
	int _load_factor = 0;
	int _path_weight = 0;
	static int _id_counter;
	// Constructors
	vertex();
	vertex(int new_id, unordered_map<vertex*, int> new_edges, int new_load_factor);

	// Copy Constructor

	// Destructor

	// Getters
	int vertex::get_id() const;
	unordered_map<vertex*, int> vertex::get_edges();
	int vertex::get_load_factor() const;
	int getPathWeight() const;

	// Setters
	void set_id(int new_id);
	void set_edges(unordered_map<vertex*, int> new_edges);
	void set_load_factor(int new_load_factor);
	void setPathWeight(int weight);

	// Methods
private:
	
};

#endif