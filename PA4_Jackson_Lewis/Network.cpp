// Includes
#include "Network.h"

// Constructors
network::network()
{
	//_graph = empty!
	_tick_count = 0;
	//_message = empty!
}
network::network(graph new_graph, int new_tick_count, message new_message)
{
	_graph = new_graph;
	_tick_count = new_tick_count;
	_message = new_message;
}

// Copy Consturctor

// Destructor

// Getters
const graph network::get_graph()
{
	return _graph;
}
const int network::get_tick_count()
{
	return _tick_count;
}
const message network::get_message()
{
	return _message;
}

// Setters
void network::set_graph(graph new_graph)
{
	_graph = new_graph;
}
void network::set_tick_count(int new_tick_count)
{
	_tick_count = new_tick_count;
}
void network::set_message(message new_message)
{
	_message = new_message;
}

// Methods
void network::tick()
{

}

void network::driver(string filename)
{
	string message_text;
	message message_item;
	packet temp_packet;
	int j = 0; // used to keep track of message order
	int starting_vertex;
	int ending_vertex;
	file_processor(filename);
	unordered_map<vertex, int> distances;

	cout << "Enter a message to send: ";
	cin >> message_text;
	cout << endl;
	cout << "Enter a starting vertex: ";
	cin >> starting_vertex;
	cout << endl;
	cout << "Enter a destination vertex: ";
	cin >> ending_vertex;

	// Turn message into message item
	for (auto i : message_text)
	{
		// Set packets char
		temp_packet.set_value(i);
		// Set packets order
		temp_packet.set_order(j);
		
		// Add new packet to the message's packet queue, _packets
		message_item.add_packet(temp_packet);

		// Increment order counter
		j++;
	}

	// Check validity of source and dest nodes and message.
	if (_graph.get_vertices().count(starting_vertex) && _graph.get_vertices().count(ending_vertex))
	{
		// While not done...
		while (!message_item.get_packets().empty() && !in_the_network.empty()) // Set to false to allow debug in current state, should be a while true loop -- while true that we are not finished (More packets to be sent, or more packets are in transmission...)
		{
			// If msg has more packets to send, queue the next packet for transmission at the starting location
			if (true)
			{

				// Compute the shortest route
				distances =_graph.computeShortestPath(temp_packet.get_previous_location());

				// Determine next intermediary node
				  // Check path?

				// Queue the packets arrival at the proper time
				  // push onto queue?

				// Increase the load factor of each node that communicated this tick
				  //nodes++

				in_the_network.push_back(temp_packet);
			}

			// For each packet in the network...
			if (true)
			{
				// Decrement expected arrival time
				// Arrival --

				// If time is <= 0, it arrived
				if (true)
				{
					// Decrease the load factor of the source and dest by 1
					  // Decrement load factor source
					  // Decrement load factor dest

					// If packet has not reached final dest, schedule another transmission using the first loop (Alter nodes transmitting packet)
					if (true)
					{
						// Schedule another transmission
					}

					// If packet has reached destination, add to list of completed packets
					if (true)	// current dest = ending dest
					{
						// push this packet to completed packets
					}
				}
			}
		}
	}


}

void network::file_processor(string filename)
{
	ifstream input_file{ filename };
	string line = "";
	vector<string> parsed;
	unordered_map<vertex*, int> temp_paths;
	int i = 0;
	int last_key = 0;
	int current_key = 0;

	while (input_file.good() == true)
	{
		getline(input_file, line);
		parsed = string_parser(line);
		parsed.shrink_to_fit();

		current_key = stoi(parsed[0]);
		if (last_key != current_key)
		{
			last_key = stoi(parsed[0]);
			temp_paths.clear();
		}

		if (parsed.size() == 1) //This should be a new node then. 
		{			
			_graph._vertices[stoi(parsed[0])].set_id(stoi(parsed[0]));
		}
		else // this is a path
		{
			temp_paths[&_graph._vertices[stoi(parsed[1])]] = stoi(parsed[2]);
			_graph._vertices[stoi(parsed[0])].set_edges(temp_paths);
		}
	}

	cout << "Graph Created." << endl;

	// Prints Vertex:Id:EdgeWeight
	for (auto i : _graph.get_vertices())
	{
		// Vertex (Header)
		cout << endl << i.first << endl << "____________" << endl;
		for (auto j : i.second.get_edges())
		{
			// Source
			cout << i.first << " ";
			// Dest ID
			cout << j.first->get_id() << " ";
			// Edge Weight
			cout << j.second << " ";
			cout << endl;
		}
	}

	/*
	for (auto i : _graph.get_vertices())
	{
		cout << "Vertex: " << i.first << endl;
		for (auto j : i.second.get_edges())
		{
			cout << "Edge: " << j.first->get_id() << endl;
			cout << "Weig: " << j.second << endl;
		}
	}	
	*/

	cout << endl;

}

vector<string> network::string_parser(string tobeparsed)
{
	vector<string> pieces{};
	string delimiter = " ";

	//keep track of starting location for substring
	int start = 0;
	int i = 0;

	//find the first instance of our delimiter
	int location = tobeparsed.find(delimiter);

	//go until we have no more delimiters
	while (location != string::npos)
	{
		//grab next piece
		string piece = tobeparsed.substr(start, location - start);
		if (piece[0] == '"')
		{
			start = location + 1;
			location = tobeparsed.find(delimiter, start);
			piece.append(tobeparsed.substr(start, location - start));
		}

		pieces.push_back(piece);//add to vector

		start = location + 1;
		location = tobeparsed.find(delimiter, start);
		i++;
	}

	//right here, we have a bit of text that still needs
	//to be taken care of
	string piece = tobeparsed.substr(start);

	//it's possible that our final piece is empty
	//(optional, could always add the piece regardless of state)
	if (piece.length() > 0)
	{
		pieces.push_back(piece);
	}

	//finally, all done
	return pieces;
}
