#ifndef MESSAGE_H
#define MESSAGE_H

// Includes
#include "Includes.h"
#include "Vertex.h"
#include "Packet.h"

// Class definition
class message
{
public:
	// Public vars
	std::queue<packet> _packets;
	vertex* _starting_vertex;
	vertex* _ending_vertex;
	
	// Constructors
	message();
	message(std::queue<packet> new_packets, vertex* new_starting_vertex, vertex* new_ending_vertex);

	// Copy Constructor

	// Destructor

	// Getters
	const std::queue<packet> get_packets();
	const vertex* get_starting_vertex();
	const vertex* get_ending_vertex();

	// Setters
	void set_packets(std::queue<packet> new_packets);
	void set_starting_vertex(vertex* new_starting_vertex);
	void set_ending_vertex(vertex* new_ending_vertex);

	// Methods

private:
};

#endif