class HashTable:

    def __init__(self) -> None:
        self.capacity = 10
        self.keys = [None] * self.capacity
        self.values = [None] * self.capacity

    def insert(self, key, data):

        index = self.hash_function(key)

        # Ther may be collision
        while self.keys[index] is not None:

            if self.keys[index] == key:
                self.values[index] = data
                return

            index = (index + 1) % self.capacity

        self.keys[index] = key
        self.values[index] = data

    def hash_function(self, key):

        hash_sum = 0

        for letter in key:
            hash_sum += ord(letter)

        return hash_sum % self.capacity

    def get(self, key):

        index = self.hash_function(key)

        while self.keys[index] is not None:
            if self.keys[index] == key:
                return self.values[index]

            index = (index + 1) % self.capacity

        return None


if __name__ == "__main__":

    table = HashTable()
    table.insert("Hello", 15)
    table.insert("Bit", 22)
    print(table.get("Hello"))
