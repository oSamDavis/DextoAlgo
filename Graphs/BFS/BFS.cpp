#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Vertex {
  // TODO(oSamDavis): Making everything public for now, might be nice to modularize later on
  public:

  int id;  // id of this vertex(e.g. A, B, C, D)
  
  // Color that marks the state TODO(oSamDavis): this could possibly be an enum
  // States: UNVISITED, VISITED(but not explored), VISITED AND EXPLORED
  std::string color;

  // distance of this vertex from source {s}
  int distance;

  // predecessor or parent of this Vertex
  Vertex* parent;

  Vertex(int id) {
    this->id = id;
    color = "";
    distance = 0;
    parent = nullptr;
  }

  // Overload the eq operator for use of this class as a Key in std::unordered_map
  bool operator==(const Vertex& other) const {
    return id == other.id;
  }  

};

// Implemented std::hash<T> for Vertex so I can use as Key in std::unordered_map
// See discussion: https://shorturl.at/0a5jI
// This block of code is called: Specialization of the std::hash template for the Vertex class
// Read more: https://www.geeksforgeeks.org/template-specialization-c/
namespace std {
  template <>
  struct hash<Vertex> {
    std::size_t operator()(const Vertex& vertex) const  {
      return std::hash<int>()(vertex.id);
    }
  };
}

class Graph {
  public:
  // unordered_map to store Vertex : -> [ neighbor vertices ]
  std::unordered_map<Vertex*, std::vector<Vertex*>> adj_list_;
  
  // Add edge to graph from u to v, assume directed for now
  void AddEdge(Vertex* u, Vertex* v) {
    // if the vertex u is not in the adj list ...
    if(adj_list_.find(u) == adj_list_.end()) {
      // ... start a list for that vertex u 
      adj_list_.insert({u, std::vector<Vertex*>()});
    }

    // if the vertex v is not in the adj list ...
    if(adj_list_.find(v) == adj_list_.end()) {
      // ... start a list for that vertex v
      adj_list_.insert({v, std::vector<Vertex*>()});
    }

    // add the edge v to u
    adj_list_[u].push_back(v);
    // adj_list[u].push_back(u);  // for the case of undirected, but comment for noq
  }


  Vertex* GetVertex(int id) {

    // use an iterator to loop through the keys
    for(auto it=adj_list_.begin(); it != adj_list_.end(); ++it) {

      // if the vertex's id is equal to id passed 
      if (it->first->id == id) {
        return it->first; // return vertex
      }
    }
    return nullptr;
  }

  std::vector<Vertex*> GetListFor(Vertex* u) {
    if(adj_list_.find(u) != adj_list_.end()) {
      return adj_list_[u];
    }
    return std::vector<Vertex*>();
  }
};


void BFS(Graph graph, int start_id) {

}


int main() {


  return 0;
}