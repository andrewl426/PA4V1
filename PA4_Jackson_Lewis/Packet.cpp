// Includes
#include "Packet.h"

// Constructors
packet::packet()
{
	_value = '\0';
	_order = 0;
	_current_wait = 0;
	//_destination = empty!
	//_previous_location = empty!
	//_next_hop = empty!
}
packet::packet(char new_value, int new_order)
{
	_value = new_value;
	_order = new_order;
	_current_wait = 0;
	//_destination = empty!
	//_previous_location = empty!
	//_next_hop = empty!
}
packet::packet(char new_value, int new_order, int new_current_wait, vertex* new_destination, vertex* new_previous_location, vertex* new_next_hop)
{
	_value = new_value;
	_order = new_order;
	_current_wait = new_current_wait;
	_destination = new_destination;
	_previous_location = new_previous_location;
	_next_hop = new_next_hop;
}

// Copy Consturctor

// Destructor

// Getters
const char packet::get_value()
{
	return _value;
}
const int packet::get_order()
{
	return _order;
}
const int packet::get_current_wait()
{
	return _current_wait;
}
const vertex* packet::get_destination()
{
	return _destination;
}
 vertex* packet::get_previous_location() const
{
	return _previous_location;
}
const vertex* packet::get_next_hop()
{
	return _next_hop;
}

// Setters
void packet::set_value(int new_value)
{
	_value = new_value;
}
void packet::set_order(int new_order)
{
	_order = new_order;
}
void packet::set_current_wait(int new_current_wait)
{
	_current_wait = new_current_wait;
}
void packet::set_destination(vertex * new_destination)
{
	_destination = new_destination;
}
void packet::set_previous_location(vertex * new_previous_location)
{
	_previous_location = new_previous_location;
}
void packet::set_next_hop(vertex * new_next_hop)
{
	_next_hop = new_next_hop;
}

// Methods