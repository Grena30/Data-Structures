CAPACITY: int = 10


class Heap:

    def __init__(self) -> None:
        self.heap_size = 0
        self.heap = [0] * CAPACITY

    def insert(self, item):

        if self.heap_size == CAPACITY:
            return

        self.heap[self.heap_size] = item
        self.heap_size = self.heap_size + 1

        # Check the heap properties
        self.fix_up(self.heap_size - 1)

    # Whether to make swap operations or not
    def fix_up(self, index):

        parent_index = (index - 1) // 2

        if index > 0 and self.heap[index] > self.heap[parent_index]:
            self.heap[index], self.heap[parent_index] = (
                self.heap[parent_index],
                self.heap[index],
            )
            self.fix_up(parent_index)
            
    
    def get_max(self):
        return self.heap[0]

    # Return max and remove it as well
    def poll(self):
        
        max_item = self.get_max()
        
        # Swap root node with the last item and heapify
        self.heap[0], self.heap[self.heap_size - 1] = self.heap[self.heap_size - 1], self.heap[0]
        self.heap_size = self.heap_size - 1
        
        self.fix_down(0)
        
        return max_item
    
    def fix_down(self, index):
        
        index_left = 2 * index + 1
        index_right = 2 * index + 2
        
        largest_index = index
        
        if index_left < self.heap_size and self.heap[index_left] > self.heap[index]:
            largest_index = index_left
        
        if index_right < self.heap_size and self.heap[index_right] > self.heap[index]:
            largest_index = index_right
            
        if index != largest_index:
            self.heap[index], self.heap[largest_index] = self.heap[largest_index], self.heap[index]
            self.fix_down(largest_index)
            
    
    def heap_sort(self):
        
        for _ in range(self.heap_size):
            max_item = self.poll()
            print(max_item)