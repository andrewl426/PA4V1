#ifndef NETWORK_H
#define NETWORK_H

// Includes
#include "Includes.h"
#include "Graph.h"
#include "Message.h"

// Class definition
class network
{
public:
	// Public vars
	graph _graph;
	int _tick_count = 0;
	message _message;

	// Constructors
	network();
	network(graph new_graph, int new_tick_count, message new_message);

	// Copy Constructor

	// Destructor

	// Getters
	const graph get_graph();
	const int get_tick_count();
	const message get_message();

	// Setters
	void set_graph(graph new_graph);
	void set_tick_count(int new_tick_count);
	void set_message(message new_message);

	// Methods
	void tick();

private:
};

#endif