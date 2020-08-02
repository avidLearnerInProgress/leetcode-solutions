class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        #self.max_num = 10000
        #self.buckets = [[] for i in range(self.max_num)]
        self.size = 1000000
        self.buckets = [False for i in range(self.size)]
        
    def add(self, key: int) -> None:
        # hashed_key = hash(key)
        # if not key in self.buckets[hashed_key]:
            # self.buckets[hashed_key].append(key)
        self.buckets[key] = True

    def remove(self, key: int) -> None:
        # hashed_key = hash(key)
        # if key in self.buckets[hashed_key]:
        #     self.buckets[hashed_key].remove(key)
        self.buckets[key] = False
            
    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        # hashed_key = hash(key)
        # if key in self.buckets[hashed_key]:
        #     return True
        # return False
        return self.buckets[key]

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
