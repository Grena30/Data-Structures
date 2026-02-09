

class Stack:
    
    def __init__(self):
        self.stack = []
        
    def push(self, data) -> None:
        self.stack.append(data)
        
        return None
    
    # O(1) 
    def pop(self) -> int:
        
        if self.stack_size() < 1:
            return -1
        
        data = self.stack[-1]
        
        del self.stack[-1]
        
        return data
    
    def peek(self) -> int:
        data = self.stack[-1]
        
        return data
    
    def is_empty(self) -> bool:
        return self.stack == []
    
    def stack_size(self) -> int:
        return len(self.stack)