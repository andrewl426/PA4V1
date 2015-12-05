// Includes
#include "Graph.h"

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
	return unordered_map<int, vertex>();
}

// Setters
void graph::set_vertices(unordered_map<int, vertex> new_vertices)
{

}

// Methods
unordered_map<vertex, int> graph::computeShortestPath(vertex* start)
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

	//underlying heap
	priority_queue<vertex, vector<vertex>, PathWeightComparer> dijkstra_queue{};

	//reset start's path weight
	start->setPathWeight(0);

	//make sure that the starting vertex is in the graph
	if (_vertices.find(start->get_id()) != _vertices.end())
	{
		//push on starting vertex
		dijkstra_queue.push(*start);

		//while queue not empty
		while (dijkstra_queue.empty() == false)
		{
			//push on outgoing edges that haven't been discovered
			vertex top = dijkstra_queue.top();
			dijkstra_queue.pop();

			//Top of heap not known (in distances)?
			if (distances.find(top) == distances.end())
			{
				//make known
				int current_path_weight = top.getPathWeight();
				distances[top] = current_path_weight;

				//push on outgoing edges
				for (auto item : top.get_edges())
				{
					vertex *next = item.first;
					int weight = item.second;
					next->setPathWeight(weight + current_path_weight);

					//not known?  add to heap
					if (distances.find(*next) == distances.end())
					{
						dijkstra_queue.push(*next);
					}
				}
			}
		}


	}
	return distances;
}