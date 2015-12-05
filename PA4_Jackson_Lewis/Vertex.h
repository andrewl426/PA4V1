#ifndef VERTEX_H
#define VERTEX_H

// Includes
#include "Includes.h"

// Class definition
class vertex
{
public:
	// Public vars
	int _id = 0;
	unordered_map<vertex*, int> _edges;
	int _load_factor = 0;
	int _path_weight = 0;
	static int _id_counter;
	// Constructors
	vertex();
	vertex(int new_id, unordered_map<vertex*, int> new_edges, int new_load_factor);

	// Copy Constructor

	// Destructor

	// Getters
	int vertex::get_id() const;
	unordered_map<vertex*, int> vertex::get_edges();
	int vertex::get_load_factor() const;
	int getPathWeight() const;

	// Setters
	void set_id(int new_id);
	void set_edges(unordered_map<vertex*, int> new_edges);
	void set_load_factor(int new_load_factor);
	void setPathWeight(int weight);

	// Methods
private:
	
};



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

class PathWeightComparer
{
public:
	bool operator()(const vertex lhs, const vertex rhs)
	{
		return (lhs.getPathWeight() > rhs.getPathWeight());
	}
};

//hashing algorithm must exist in STD namespace
namespace std {

	template <>
	struct hash<vertex>
	{
		//provide a hash (convert grocery item into integer)
		size_t operator()(const vertex& item) const
		{
			size_t hash_val = 0;

			//to hash INTs using the STL
			hash<int> int_hash{};

			//define hashing algorithm.  Ours is pretty easy...
			hash_val = int_hash(item.get_id());

			//add others as necessary
			return hash_val;
		}
	};
}



#endif