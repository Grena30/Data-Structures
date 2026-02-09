

class Node:

    def __init__(self, data) -> None:
        self.data = data
        self.next = None
        self.previous = None

    def __repr__(self) -> str:
        return str(self.data)


class DoublyLinkedList:

    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.num_of_nodes = 0

        return None

    def insert(self, data) -> None:
        new_node = Node(data=data) 
        
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            new_node.previous = self.tail
            self.tail.next = new_node
            self.tail = new_node 
        
        return None

    def remove(self, data) -> None:
        if self.head is None:
            return None

        current_node = self.head
        previous_node = None

        while current_node is not None and current_node.data != data:
            previous_node = current_node
            current_node = current_node.next

        if current_node is None:
            return None

        if previous_node is None:
            self.head = current_node.next
        else:
            previous_node.next = current_node.next
            self.tail = current_node.previous

        return None

    def size_of_list(self) -> int:
        return self.num_of_nodes

    def traverse_forward(self) -> None:
        current_node = self.head
        print("\nSTART", end="")

        while current_node is not None:
            print(f" -> {current_node}", end="")
            current_node = current_node.next

        return None
    
    def traverse_backward(self) -> None:
        current_node = self.tail
        print("\nEND", end="")

        while current_node is not None:
            print(f" -> {current_node}", end="")
            current_node = current_node.previous

        return None
