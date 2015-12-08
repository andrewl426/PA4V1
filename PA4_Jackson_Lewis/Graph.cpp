// Includes
#include "Graph.h"

// Overloaders
int operator==(const vertex &lhs, const vertex &rhs)
{
	return lhs.get_id() == rhs.get_id();
}
bool operator<(const vertex &lhs, const vertex &rhs)
{
	return lhs.get_id() < rhs.get_id();
}
bool operator>(const vertex &lhs, const vertex &rhs)
{
	return lhs.get_id() > rhs.get_id();
}

// Constructors
graph::graph()
{
	//_vertices = empty!
}
graph::graph(unordered_map<int, vertex> new_vertices)
{
	_vertices = new_vertices;
}

// Copy Consturctor

// Destructor

// Getters
unordered_map<int, vertex> graph::get_vertices() const
{
	return _vertices;
}

// Setters
void graph::set_vertices(unordered_map<int, vertex> new_vertices)
{
	_vertices = new_vertices;
}

// Methods
unordered_map<vertex, int> graph::computeShortestPath(vertex start)
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
	
	//holds known distances
	unordered_map<vertex, int> distances;

	path for_the_stack;
	//underlying heap
	priority_queue<vertex, vector<vertex>, PathWeightComparer> dijkstra_queue{};

cout << endl << endl << "*****STA DIJKSTRAS*****";

	//reset start's path weight
	start.set_path_weight(0);
cout << endl << "start.path_weight: " << start.getPathWeight();

	//make sure that the starting vertex is in the graph
	if (_vertices.find(start.get_id()) != _vertices.end())
	{
		//push on starting vertex
		dijkstra_queue.push(start);
		//for_the_stack.push_vertex(start); //testing
cout << endl << "Push on start(id): " << start.get_id();

		//while queue not empty
		while (dijkstra_queue.empty() == false)
		{
			//push on outgoing edges that haven't been discovered
			vertex top = dijkstra_queue.top();
			dijkstra_queue.pop();
			//for_the_stack.pop_vertex(); //testing

			//Top of heap not known (in distances)?
			if (distances.find(top) == distances.end())
			{

				//cout << top.get_load_factor() << endl;
				//make known
				int current_path_weight = top.getPathWeight() * top.get_load_factor();
				//cout << "Current path weight: " << current_path_weight << endl;
				distances[top] = current_path_weight;
				
cout << endl << endl << "vertex top(id): " << top.get_id();
cout << endl << "vertex top(PW): " << top.getPathWeight();
cout << endl << "vertex top(LF): " << top.get_load_factor();

				//push on outgoing edges
				for (auto item : top.get_edges())
				{
					vertex *next = item.first;
					int weight = item.second * top.get_load_factor();
// Prints the wight equation..	//cout << endl << "Weight = " << item.second << " * " << top.get_load_factor();

					next->set_path_weight(weight + current_path_weight);

					//not known?  add to heap
					if (distances.find(*next) == distances.end())
					{
						dijkstra_queue.push(*next);
						//for_the_stack.push_vertex(top);
					}
				}
			}
		}
	}
	cout << endl << endl << "*****END DIJKSTRAS*****" << endl << endl;

	cout << endl << endl << "*****DISTANCES*****" << endl;
	for (auto i : distances)
	{
		cout << " -> V" << i.first.get_id() << ", W" << i.second;
	}
	cout << endl << endl << "*****END DISTS*****" << endl;

	return distances;
}