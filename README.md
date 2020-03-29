## SimpleHashTable

- Resolve collison using separate chaining.
- If we can ensure that the load factor α never exceeds some fixed value αmax, then all operations will be O(1 + αmax) = O(1).


## Improvement (later)

- If α (current number of table entries / table size) is greater than 1, I'll resize the table size and rehash all the elements in the original bucket array into a new one.
