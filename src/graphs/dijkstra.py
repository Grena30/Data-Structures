import heapq


class Edge:

    def __init__(self, weight, start_vertex, target_vertex) -> None:
        self.weight = weight
        self.start_vertex = start_vertex
        self.target_vertex = target_vertex


class Node:

    def __init__(self, name) -> None:
        self.name = name
        self.visited = False
        self.predecessor = None
        self.adjacency_list = []
        self.min_distance = float("inf")

    def __lt__(self, other_node):
        return self.min_distance < other_node.min_distance


class DijkstraAlgorithm:

    def __init__(self) -> None:
        self.heap = []

    def calculate(self, start_vertex):

        start_vertex.min_distance = 0
        heapq.heappush(self.heap, start_vertex)

        while self.heap:
            pass
