def is_min_heap(heap):

    # your implementation here
    heap_size = len(heap)
    for i in range(heap_size):
        
        left_child = 2 * i + 1 if 2 * i + 1 < heap_size else None
        right_child = 2 * i + 2 if 2 * i + 2 < heap_size else None
        
        if left_child is not None and heap[i] > heap[left_child]:
            return False
            
        if right_child is not None and heap[i] > heap[right_child]:
            return False
        
    return True


if __name__ == "__main__":
    heap: list = [1, 2, 3, 5, -4]
    print(is_min_heap(heap=heap))