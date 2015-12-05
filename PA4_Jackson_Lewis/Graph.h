#ifndef GRAPH_H
#define GRAPH_H

// Includes
#include "Includes.h"
#include "Vertex.h"
#include "Path.h"

// Class definition
class graph
{


public:
	// Public vars
	unordered_map<int, vertex> _vertices;

	// Constructors
	graph();
	graph(unordered_map<int, vertex> new_vertices);

	// Copy Constructor

	// Destructor

	// Getters --- ADDITIONAL GETTERS ARE NEEDED FOR MANIPULATION OF INDIVIDUAL VERTICES probably - get_vertex_at(key), returning value
	 unordered_map<int, vertex> get_vertices() const;

	// Setters --- ADDITIONAL SETTERS ARE NEEDED FOR MANIPULATION OF INDIVIDUAL VERTICES probably - set_vertex_at(key, value)
	void set_vertices(unordered_map<int, vertex> new_vertices);

	// Methods
	unordered_map<vertex, int> computeShortestPath(vertex* start);



private:
};

#endif