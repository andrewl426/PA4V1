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
	string message;
	int starting_vertex;
	int ending_vertex;
	file_processor(filename);

	cout << "Enter a message to send: ";
	cin >> message;
	cout << endl;
	cout << "Enter a starting vertex: ";
	cin >> starting_vertex;
	cout << endl;
	cout << "Enter a destination vertex: ";
	cin >> ending_vertex;


	// Check validity of source and dest nodes and message.

	// While not done...
		// If msg has more packets to send, queue the next packet for transmission at the starting location
			// Compute the shortest route
			// Determine next intermediary node
			// Queue the packets arrival at the proper time
			// Increase the load factor of each node that communicated this tick

		// For each packet in the network...
			// Decrement expected arrival time
			// If time is <= 0, it arrived
				// Decrease the load factor of the source and dest by 1
				// If packet has not reached final dest, schedule another transmission using the first loop (Alter nodes transmitting packet)
				// If packet has reached destination, add to list of completed packets


}

void network::file_processor(string filename)
{
	ifstream input_file{ filename };
	string line = "";
	vector<string> parsed;
	unordered_map<vertex*, int> temp_paths;
	int i = 0;

	while (input_file.good() == true)
	{
		getline(input_file, line);
		parsed = string_parser(line);
		parsed.shrink_to_fit();

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

	for (auto i : _graph.get_vertices())
	{
		cout << i.first << " ";
		for (auto j : i.second.get_edges())
		{
			cout << j.second << endl;
		}
	}
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
