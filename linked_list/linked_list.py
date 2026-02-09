

class Node:

    def __init__(self, data) -> None:
        self.data = data
        self.next = None

    def __repr__(self) -> str:
        return str(self.data)


class LinkedList:

    def __init__(self) -> None:
        self.head = None
        self.num_of_nodes = 0

        return None

    def insert_start(self, data) -> None:
        self.num_of_nodes += 1
        new_node = Node(data=data)

        if self.head == None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node

        return None

    def insert_end(self, data) -> None:
        self.num_of_nodes += 1
        new_node = Node(data=data)

        if self.head is None:
            self.head = new_node
        else:
            current_node = self.head

            while current_node.next is not None:
                current_node = current_node.next

            current_node.next = new_node

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

        return None

    def size_of_list(self) -> int:
        return self.num_of_nodes

    def traverse_list(self) -> None:
        current_node = self.head
        print("\nSTART", end="")

        while current_node is not None:
            print(f" -> {current_node}", end="")
            current_node = current_node.next
        
        return None
    
    def get_middle_node(self) -> Node | None:
        current_node = self.head
        middle = (self.num_of_nodes // 2) 
        
        if self.num_of_nodes % 2 == 0:
            middle -= 1
        
        if self.head is None:
            return None
        
        while middle != 0 and current_node is not None:
            middle -= 1
            current_node = current_node.next
        
        return current_node
    
    def reverse(self) -> None:
        current_node = self.head
        previous_node = None
        next_node = None
        
        if self.head is None:
            return None
        
        while current_node != None:
            next_node = current_node.next
            current_node.next = previous_node
            previous_node = current_node
            current_node = next_node
        
        self.head = previous_node
        
        return None    
