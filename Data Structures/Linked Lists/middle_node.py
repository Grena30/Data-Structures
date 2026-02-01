from LinkedList import LinkedList


if __name__ == "__main__":
    
    new_list = LinkedList()
   
    for i in range(4):
       new_list.insert_end(i)
    
    new_list.traverse_list()
    print()
    middle_node = new_list.get_middle_node()
    print(middle_node)