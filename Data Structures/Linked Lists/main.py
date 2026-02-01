from LinkedList import LinkedList
from DoublyLinkedLists import DoublyLinkedList


if __name__ == "__main__":

    new_linked_list = LinkedList()

    new_linked_list.insert_start(5)
    new_linked_list.insert_end("Hello butuk")
    new_linked_list.insert_start("Butuk")
    new_linked_list.remove("Butuk")
    new_linked_list.traverse_list()
    
    new_doubly_linked_list = DoublyLinkedList()
    new_doubly_linked_list.insert(5)
    new_doubly_linked_list.insert("Hello butuk")
    new_doubly_linked_list.insert("Butuk")
    new_doubly_linked_list.remove("Butuk")
    new_doubly_linked_list.traverse_forward()
    new_doubly_linked_list.traverse_backward()
