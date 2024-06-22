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
    std::unordered_map<Vertex, std::vector<Vertex>> adj_matrix;
  

  void AddEdge(Vertex u, Vertex v) {

  }


  Vertex GetVertex(int id) {

  }

  std::vector<Vertex> GetListFor(Vertex u) {


  }
};


void BFS(Graph graph, int start_id) {

}


int main() {


  return 0;
}