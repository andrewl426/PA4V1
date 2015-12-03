// Includes
#include "Graph.h"
#include "Vertex.h"

// Constructors
graph::graph()
{
	//_vertices = empty!
}
graph::graph(std::unordered_map<int, vertex> new_vertices)
{
	_vertices = new_vertices;
}

// Copy Consturctor

// Destructor

// Getters
const std::unordered_map<int, vertex> graph::get_vertices()
{
	return std::unordered_map<int, vertex>();
}

// Setters
void graph::set_vertices(std::unordered_map<int, vertex> new_vertices)
{

}

// Methods
path graph::computeShortestPath(vertex* start)
{
	/*
	A note on Dijkstra's Algorithm
	__________________________________________________________________________________________
	We are using a node's "load factor" to indicate the speed at which a given node operates.
	As a node becomes more saturated with network traffic, it likely will take the node longer
	to respond to any given message. To model this behavior, calculate an edge's weight to be 
	the product of the edge's unadjusted weight and the node's load factor;
	
		(weight = vertex.getWeight() * vertext.getLoadFactor()).
	*/

	return path();
}