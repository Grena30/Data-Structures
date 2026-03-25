class Color:
    RED = 1
    BLACK = 2


class Node:

    def __init__(self, data, parent=None, color=Color.RED) -> None:
        self.data = data
        self.left_node = None
        self.right_node = None
        self.parent = parent
        self.color = color


class RedBlackTree:

    def __init__(self) -> None:
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self.insert_node(data, self.root)

    def insert_node(self, data, node):
        if data < node.data:
            if node.left_node:
                self.insert_node(data, node.left_node)
            else:
                node.left_node = Node(data, node)
                self.settle_violation(node.left_node)
        else:
            if node.right_node:
                self.insert_node(data, node.right_node)
            else:
                node.right_node = Node(data, node)
                self.settle_violation(node.right_node)

    def settle_violation(self, node):
        pass

    def rotate_right(self, node):
        if node is None or node.left_node is None:
            return None

        print(f"Rotating to the right on node {node.data}")

        temp_left_node = node.left_node
        t = temp_left_node.right_node

        temp_left_node.right_node = node
        node.left_node = t

        if t is not None:
            t.parent = node

        temp_parent = node.parent
        temp_left_node.parent = temp_parent
        node.parent = temp_left_node

        if temp_parent is None:
            self.root = temp_left_node
        elif temp_parent.left_node == node:
            temp_parent.left_node = temp_left_node
        else:
            temp_parent.right_node = temp_left_node

    def traverse(self) -> None:
        if self.root:
            return self.traverse_in_order(self.root)

        return None

    def traverse_in_order(self, node: Node) -> None:
        if node.left_node:
            self.traverse_in_order(node.left_node)

        print(node.data)

        if node.right_node:
            self.traverse_in_order(node.right_node)

        return None
