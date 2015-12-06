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
	_tick_count++;
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
	getline(cin, message_text); // Eat newline
	cin.clear(); // clear buffer
	fflush(stdin); // clear buffer
	getline(cin, message_text); // Get users msg
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
		// Init prev location to source...
		temp_packet.set_previous_location(&_graph.get_vertices().at(starting_vertex)); //traced crash with space to here
		// Init dest to ending vertex...
		temp_packet.set_destination(&_graph.get_vertices().at(ending_vertex));

		// Add new packet to the message's packet queue, _packets
		message_item.add_packet(temp_packet);

		// Increment order counter
		j++;
	}

	// Check validity of source and dest nodes and message.
	if (_graph.get_vertices().count(starting_vertex) && _graph.get_vertices().count(ending_vertex))
	{
		// While not done...
		while (!message_item.get_packets().empty() || !in_the_network.empty()) // While true that we are not finished (More packets to be sent, or more packets are in transmission...)
		{
			// If msg has more packets to send, queue the next packet for transmission at the starting location
			if (!message_item.get_packets().empty())
			{

				// Compute the shortest route
				distances =_graph.computeShortestPath(&_graph.get_vertices().at(starting_vertex));

				for (auto i : distances)
				{
					cout << endl << "I.first.get_id(): " << i.first.get_id() << " I.second: " << i.second;
				}

				// Determine next intermediary node
				  // Check path?
				temp_packet = message_item.pop_packet();

				//TEMPORARILY SETTING NEXT HOP TO DESTINATION!
				temp_packet.set_next_hop(&_graph.get_vertices().at(ending_vertex));

				// Queue the packets arrival at the proper time
				  // push onto queue?
				temp_packet.set_current_wait(1); // TEMPORARY INCORRECT HARDCODE

				// Increase the load factor of each node that communicated this tick
				  //nodes++

				in_the_network.push_back(temp_packet);
			}

			cout << in_the_network.size() << endl;
			system("PAUSE");

			// For each packet in the network...
			
			for (int i = 0; i < in_the_network.size(); i++)			//for (auto i : in_the_network)
			{
				// Decrement expected arrival time
				// Arrival --
				in_the_network[i].set_current_wait((in_the_network[i].get_current_wait() - 1)); // Not sure if this works

				// If time is <= 0, it arrived
				if (in_the_network[i].get_current_wait() <= 0) // Not sure if this works
				{
					// Decrement load factor source
					in_the_network[i].get_previous_location()->set_load_factor(in_the_network[i].get_previous_location()->get_load_factor() - 1);
					
					// Decrement load factor dest
					in_the_network[i].get_next_hop()->set_load_factor(in_the_network[i].get_next_hop()->get_load_factor() - 1);

					// If packet has not reached final dest, schedule another transmission using the first loop (Alter nodes transmitting packet)
					if (in_the_network[i].get_destination()->get_id() == ending_vertex)
					{
						// Schedule another transmission
						// Compute the shortest route
						distances = _graph.computeShortestPath(in_the_network[i].get_previous_location());

						for (auto j : distances) // changed to j in case the i loop within an i loop was casuing issues.
						{
							cout << endl << "J.first.get_id(): " << j.first.get_id() << " J.second: " << j.second;
						}

						// Determine next intermediary node
						// Check path?

						//TEMPORARILY SETTING NEXT HOP TO DESTINATION!
						in_the_network[i].set_next_hop(&_graph.get_vertices().at(ending_vertex));

						// Queue the packets arrival at the proper time
						// push onto queue?
						in_the_network[i].set_current_wait(1); // TEMPORARY INCORRECT HARDCODE
					}

					// If packet has reached destination, add to list of completed packets
					if (in_the_network[i].get_destination()->get_id() == ending_vertex)
					{
						// push this packet to completed packets
						completed_packets.push_back(in_the_network[i]);
						in_the_network.pop_back(); // I'm not sure, but i believe that what is popped and what is pushed should be the same. The idea is to push the completed node onto completed, and pop it from in the network...
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
