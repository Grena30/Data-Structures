from linked_list import LinkedList, DoublyLinkedList
from stack import Stack
from tree import BinarySearchTree, TreeComparator, AVLTree, RedBlackTree


def tree_creation() -> None:

    new_bst = BinarySearchTree()
    # new_bst.insert(5)
    new_bst.insert(5)
    new_bst.insert(2)
    new_bst.insert(25)
    new_bst.traverse()

    second_bst = BinarySearchTree()
    second_bst.insert(5)
    second_bst.insert(3)
    second_bst.insert(25)
    second_bst.traverse()

    comparator = TreeComparator()
    print(comparator.compare(new_bst.root, second_bst.root))

    return None


def avl_tree_creation() -> None:

    avl = AVLTree()
    avl.insert(5)
    avl.insert(8)
    avl.insert(6)

    # avl.remove(5)

    avl.traverse()

    return None

def red_black_tree_creation() -> None:
    
    rbt = RedBlackTree()
    
    

def main() -> None:
    # tree_creation()
    avl_tree_creation()

    return None


if __name__ == "__main__":

    main()

    # new_linked_list = LinkedList()

    # new_linked_list.insert_start(5)
    # new_linked_list.insert_end("Hello butuk")
    # new_linked_list.insert_start("Butuk")
    # new_linked_list.remove("Butuk")
    # new_linked_list.traverse_list()

    # new_doubly_linked_list = DoublyLinkedList()
    # new_doubly_linked_list.insert(5)
    # new_doubly_linked_list.insert("Hello butuk")
    # new_doubly_linked_list.insert("Butuk")
    # new_doubly_linked_list.remove("Butuk")
    # new_doubly_linked_list.traverse_forward()
    # new_doubly_linked_list.traverse_backward()

    # new_stack = Stack()

    # new_stack.push(5)
    # new_stack.push("hello")
    # print(new_stack.peek())
