#ifndef PACKET_H
#define PACKET_H

// Includes
#include "Includes.h"
#include "Vertex.h"

// Class definition
class packet
{
public:
	// Public vars
	char _value = '\0';
	int _order = 0;
	int _current_wait = 0;
	vertex* _destination;
	vertex* _previous_location;
	vertex* _next_hop;

	// Constructors
	packet();
	packet::packet(char new_value, int new_order);
	packet(char new_value, int new_order, int new_current_wait, vertex* new_destination, vertex* new_previous_location, vertex* new_next_hop);

	// Copy Constructor

	// Destructor

	// Getters
	const char get_value();
	const int get_order();
	const int get_current_wait();
	const vertex* get_destination();
	const vertex* get_previous_location();
	const vertex* get_next_hop();

	// Setters
	void set_value(int new_value);
	void set_order(int new_order);
	void set_current_wait(int new_current_wait);
	void set_destination(vertex* new_destination);
	void set_previous_location(vertex* new_previous_location);
	void set_next_hop(vertex* new_next_hop);

	// Methods

private:
};

#endif