class TimSort:
 
    def __init__(self, nums):
        self.nums = nums    
 
    def sort(self):
        self.merge_sort(self.nums)
 
    def insertion_sort(self, nums):
        for i in range(len(nums)):
            j = i
            # we have to check all the previous items (not always all of them)
            # so in worst case we consider all the previous items (until j=0)
            while j > 0 and nums[j - 1] > nums[j]:
                # swap the items - shift operations
                # this is the main disadvantage of insertion sort O(NxN)
                nums[j - 1], nums[j] = nums[j], nums[j - 1]
                j = j - 1
 
    def merge_sort(self, nums):
        if len(nums) <= 32:
            self.insertion_sort(nums)
            return
 
        middle_index = len(nums) // 2
        left_half = nums[:middle_index]
        right_half = nums[middle_index:]
 
        self.merge_sort(left_half)
        self.merge_sort(right_half)
        self.merge(left_half, right_half, nums)
 
    def merge(self, left, right, nums):
        i = 0
        j = 0
        k = 0
 
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                nums[k] = left[i]
                i = i + 1
            else:
                nums[k] = right[j]
                j = j + 1
 
            k = k + 1
 
        # after that there may be additional items in the left (right) sub-array
        while i < len(left):
            nums[k] = left[i]
            i = i + 1
            k = k + 1
 
        while j < len(right):
            nums[k] = right[j]
            j = j + 1
            k = k + 1
 
 
if __name__ == '__main__':
    x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10,1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    sort = TimSort(x)
    sort.sort()
    print(x)