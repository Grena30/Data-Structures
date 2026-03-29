def naive_search(pattern, text):

    # length of the pattern
    m = len(pattern)
    # length of the text
    n = len(text)
    
    
    for i in range(n):
        check = 0
        
        for j in range(m):
            if i + j > n - 1:
                return 0
            
            if pattern[j] != text[i + j]:
                break
            
            check += 1
        
        if check == m:
            return i
    
    return 0


if __name__ == "__main__":
    pattern = "abc"
    text = "aaabcqr"
    
    print(naive_search(pattern, text))