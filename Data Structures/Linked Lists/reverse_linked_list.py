from LinkedList import LinkedList


if __name__ == "__main__":
    
    new_list = LinkedList()
   
    for i in range(10):
       new_list.insert_end(i)
    
    new_list.traverse_list()
    new_list.reverse()
    new_list.traverse_list()