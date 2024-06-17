from typing import List

class Vertex:
  def __init__(self, id: int) -> None:
    self.id = id
    self.color = ""
    self.distance = 0 # distance of this vertex from the source (s)
    self.parent = None

  # Adding the hash func and eq func to allow 
  def __hash__(self):
    return hash(self.id)

  def __eq__(self, other):
    return isinstance(other, Vertex) and self.id == other.id    


class Graph:
  def __init__(self) -> None:
    # dict to store vertex : -> [ neighbor vertices ]
    self.adj_list = {}

  
  # add edge to graph from u to v, assume directed for now
  def add_edge(self, u: Vertex, v: Vertex) -> None:
    if u not in self.adj_list:
      self.adj_list[u] = []  # initialize, the vertex to have an empty list
    if v not in self.adj_list:
      self.adj_list[v] = []  # initialize, the vertex to have an empty list

    self.adj_list[u].append(v)
    # self.graph[v].append(u) # for the case of undirected , but comment for now

  def get_vertex(self, id: int) -> Vertex:
    for vertex in self.adj_list:
      if vertex.id == id:
        return vertex
    return None
  
  def get_list_for(self, u: Vertex) -> List[Vertex]:
    if u in self.adj_list:
        return self.adj_list[u]
    return []
    

from collections import deque

def BFS(graph, start_id):
  # get the source vertex
  source = graph.get_vertex(start_id)

  # for each vertext in the graph, mark
  # WHITE(unseen),
  # distance from source (inf),
  # parent (None)
  for vertex in graph:
    if vertex.id != start_id:
      vertex.color = "WHITE"
      vertex.distance = float('inf')
      vertex.parent = None

  # Mark source GRAY(seen, but not explored)
  # distance from source = 0
  # the source has no parent since it serves as the root
  source.color = "GRAY"
  source.distance = 0
  source.parent = None

  # initialize the queue with just the source vertex
  queue = deque([source])

  # while the queue isn't empty(i.e. we have some GRAY vertices)
  while queue:
    # Pop from front of Queue
    u = queue.pop()

    # Get the neighbors for the vertex
    u_neighbors = graph.get_list_for(u)

    # for all of u's neighbors ...
    for v in u_neighbors:
      # if the neighbor is unseen
      if v.color == "WHITE":
        v.color = "GRAY" # mark the neighbor as GRAY (seen but not explored)
        v.distance = u.distance + 1  ## distance is parent's distance + 1 
        v.parent = u  # parent of neighbor is u(originating vertex / predecessor)
        queue.append(v)  # add neighbor to the queue
    
    # Mark u as fully seen and explored 
    u.color = "BLACK"

