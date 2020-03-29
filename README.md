## SimpleHashTable

- Resolve collison using separate chaining.
- If we can ensure that the load factor α never exceeds some fixed value α_max, then all operations will be O(1 + α_max) = O(1).


## Improvement (later)

- If α (current number of table entries / table size) is greater than 1, I'll resize the table size and rehash all the elements in the original bucket array into a new one. Since increasing the size of a hash table requires considerably more work than increasing the size of an ordinary array. Rehashing should be avoided as much as possible.
