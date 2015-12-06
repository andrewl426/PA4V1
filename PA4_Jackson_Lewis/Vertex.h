#ifndef VERTEX_H
#define VERTEX_H

// Includes
#include "Includes.h"

// Class definition
class vertex
{
public:
	// Public vars
	int _id;
	unordered_map<int, int> _edges;
	int _load_factor;
	int _path_weight;
	static int _id_counter;
	// Constructors
	vertex();
	vertex(int new_id, unordered_map<int, int> new_edges, int new_load_factor);

	// Copy Constructor

	// Destructor

	// Getters
	int vertex::get_id() const;
	unordered_map<int, int> get_edges();
	int vertex::get_load_factor() const;
	int getPathWeight() const;

	// Setters
	void set_id(int new_id);
	void set_edges(unordered_map<int, int> new_edges);
	void set_load_factor(int new_load_factor);
	void setPathWeight(int weight);

	// Methods
private:
	
};

#endif