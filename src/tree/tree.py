class Node:

    def __init__(self, data: int, parent: Node | None = None) -> None:
        self.data = data
        self.left_node = None
        self.right_node = None
        self.parent = parent


class TreeComparator:

    def compare(self, node1, node2):

        if node1 is None and node2 is None:
            return True

        if node1 is None or node2 is None:
            return False

        if node1.data != node2.data:
            return False

        left_match = self.compare(node1.left_node, node2.left_node)
        right_match = self.compare(node1.right_node, node2.right_node)

        return left_match and right_match


class BinarySearchTree:

    def __init__(self) -> None:
        self.root = None

    def remove(self, data: int) -> None:
        if self.root:
            self.remove_node(data, self.root)

        return None

    def remove_node(self, data: int, node: Node) -> None:

        if node is None:
            return None

        if data < node.data:
            self.remove_node(data, node.left_node)
        elif data > node.data:
            self.remove_node(data, node.right_node)
        else:
            # Leaf node case
            if node.left_node is None and node.right_node is None:
                print(f"Removing the leaf node {node.data}")
                parent = node.parent

                if parent is not None and parent.left_node == node:
                    parent.left_node = None
                if parent is not None and parent.right_node == node:
                    parent.right_node = None

                if parent is None:
                    self.root = None

                del node

            # Single child case
            elif node.left_node is None and node.right_node is not None:
                print(f"Removing a node with a single child")
                parent = node.parent

                if parent is not None and parent.left_node == node:
                    parent.left_node = node.right_node
                if parent is not None and parent.right_node == node:
                    parent.right_node = node.right_node

                if parent is None:
                    self.root = node.right_node

                node.right_node.parent = parent

                del node

            elif node.left_node is not None and node.right_node is None:
                print(f"Removing a node with a single child")
                parent = node.parent

                if parent is not None and parent.left_node == node:
                    parent.left_node = node.left_node
                if parent is not None and parent.right_node == node:
                    parent.right_node = node.left_node

                if parent is None:
                    self.root = node.left_node

                node.left_node.parent = parent

                del node

            else:
                print(f"Removing a node with a two children")
                predecessor = self.get_predecessor(node.left_node)

                new_data = predecessor.data
                predecessor.data = node.data
                node.data = new_data

                self.remove_node(data, predecessor)

        return None

    def get_predecessor(self, node: Node) -> Node:
        if node.right_node:
            return self.get_predecessor(node.right_node)

        return node

    def insert(self, data: int) -> None:
        if self.root is None:
            self.root = Node(data)
        else:
            self.insert_node(data, self.root)

        return None

    def insert_node(self, data: int, node: Node) -> None:
        if data < node.data:
            if node.left_node is not None:
                self.insert_node(data, node.left_node)
            else:
                node.left_node = Node(data, parent=node)
        else:
            if node.right_node is not None:
                self.insert_node(data, node.right_node)
            else:
                node.right_node = Node(data, parent=node)

    def get_min(self) -> int | None:
        if self.root is not None:
            return self.get_min_value(self.root)

        return None

    def get_min_value(self, node: Node) -> int:
        if node.left_node:
            return self.get_min_value(node.left_node)

        return node.data

    def get_max(self) -> int | None:
        if self.root is not None:
            return self.get_max_value(self.root)

        return None

    def get_max_value(self, node: Node) -> int:
        if node.right_node:
            return self.get_max_value(node.right_node)

        return node.data

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
