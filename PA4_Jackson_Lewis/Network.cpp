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
	return graph();
}
const int network::get_tick_count()
{
	return 0;
}
const message network::get_message()
{
	return message();
}

void network::file_processor(string filename)
{
	ifstream input_file{filename};
	int node_check = 0;



	while (input_file.good() == true)
	{
		vector<string> parsed;

		if (parsed.size() == 1) //This should be a new node then. 
		{

			_graph._vertices[stoi(parsed[0])].set_id(stoi(parsed[0]));


		}
		else // this is a path
		{

		}


	}

}

// Setters
void network::set_graph(graph new_graph)
{

}
void network::set_tick_count(int new_tick_count)
{
	_tick_count = new_tick_count;
}
void network::set_message(message new_message)
{

}


// Methods
void network::tick()
{

}

vector<string> network::string_parser(string tobeparsed)
{
	vector<string> pieces{};
	string delimiter = "\n";

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
