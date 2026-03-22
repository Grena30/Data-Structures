class Node:

    def __init__(self, data: int, parent: Node | None) -> None:
        self.data = data
        self.left_node = None
        self.right_node = None
        self.parent = parent
        self.height = 0


class AVLTree:

    def __init__(self) -> None:
        self.root = None

    def remove(self, data):
        if self.root:
            self.remove_node(data, self.root)

    def remove_node(self, data: int, node):

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

                # Check AVL properties
                self.handle_violation(parent)

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

                # Check AVL properties
                self.handle_violation(parent)

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

                # Check AVL properties
                self.handle_violation(parent)

            # Double child case
            else:
                print(f"Removing a node with a two children")
                predecessor = self.get_predecessor(node.left_node)

                new_data = predecessor.data
                predecessor.data = node.data
                node.data = new_data

                self.remove_node(data, predecessor)

        return None

    def get_predecessor(self, node):
        if node.right_node:
            return self.get_predecessor(node.right_node)

        return node

    def insert(self, data: int):
        if self.root is None:
            self.root = Node(data, None)
        else:
            self.insert_node(data, self.root)

    def insert_node(self, data, node):

        if data < node.data:
            if node.left_node:
                self.insert_node(data, node.left_node)
            else:
                node.left_node = Node(data, node)
                node.height = (
                    max(
                        self.calculate_height(node.left_node),
                        self.calculate_height(node.right_node),
                    )
                    + 1
                )
        else:
            if node.right_node:
                self.insert_node(data, node.right_node)
            else:
                node.right_node = Node(data, node)
                node.height = (
                    max(
                        self.calculate_height(node.left_node),
                        self.calculate_height(node.right_node),
                    )
                    + 1
                )

        # Checking AVL properties
        self.handle_violation(node)

    def handle_violation(self, node):
        while node is not None:
            node.height = (
                max(
                    self.calculate_height(node.left_node),
                    self.calculate_height(node.right_node),
                )
                + 1
            )

            self.violation_helper(node)
            node = node.parent

    def violation_helper(self, node):
        balance = self.calculate_balance(node)

        if balance > 1:
            # left-right case
            if self.calculate_balance(node.left_node) < 0:
                self.rotate_left(node.left_node)

            # left-left case
            self.rotate_right(node)

        elif balance < -1:
            # right-left case
            if self.calculate_balance(node.right_node) > 0:
                self.rotate_right(node.right_node)

            # right-right case
            self.rotate_left(node)

    def rotate_left(self, node):
        if node is None or node.right_node is None:
            return None

        print(f"Rotating to the left on node {node.data}")

        temp_right_node = node.right_node
        t = temp_right_node.left_node

        temp_right_node.left_node = node
        node.right_node = t

        if t is not None:
            t.parent = node

        temp_parent = node.parent
        temp_right_node.parent = temp_parent
        node.parent = temp_right_node

        if temp_parent is None:
            self.root = temp_right_node
        elif temp_parent.left_node == node:
            temp_parent.left_node = temp_right_node
        else:
            temp_parent.right_node = temp_right_node

        node.height = (
            max(
                self.calculate_height(node.left_node),
                self.calculate_height(node.right_node),
            )
            + 1
        )
        temp_right_node.height = (
            max(
                self.calculate_height(temp_right_node.left_node),
                self.calculate_height(temp_right_node.right_node),
            )
            + 1
        )

        return None

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

        node.height = (
            max(
                self.calculate_height(node.left_node),
                self.calculate_height(node.right_node),
            )
            + 1
        )
        temp_left_node.height = (
            max(
                self.calculate_height(temp_left_node.left_node),
                self.calculate_height(temp_left_node.right_node),
            )
            + 1
        )

        return None

    def calculate_height(self, node):
        if node is None:
            return -1

        return node.height

    # |h_left - h_right| > 1, cannot differ more than 1, otherwise imbalanced
    def calculate_balance(self, node):
        if node is None:
            return 0

        return self.calculate_height(node.left_node) - self.calculate_height(
            node.right_node
        )

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
