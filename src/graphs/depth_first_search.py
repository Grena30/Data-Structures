class Node:

    def __init__(self, name) -> None:
        self.name = name
        self.adjacency_list = []
        self.visited = False


def depth_first_search(start_node):

    stack = [start_node]

    while stack:
        actual_node = stack.pop()
        print(actual_node.name)

        for n in actual_node.adjacency_list:
            if not n.visited:
                n.visited = True
                stack.append(n)


if __name__ == "__main__":

    node1 = Node("A")
    node2 = Node("B")
    node3 = Node("C")

    node1.adjacency_list.append(node2)
    node2.adjacency_list.append(node3)

    depth_first_search(node1)
