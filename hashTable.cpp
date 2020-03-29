// Implement a simple hash table.
// Handle collison using separate chaining.
#include <iostream>
#include <string>
#include <list>
#include <bitset>
using namespace std;

// table is an array of pointers, each pointer points to a list of V type
template <class K, class V>
class HashTable {
  private:
    list<V>* table; 
    int bucketSize;
    int tableSize;
    int addrCal(int key);
    int addrCal(string key);
    int addrCal(char key);
  public:
    HashTable(int tSize = 101);
    ~HashTable();
    bool put(K key, V val);
    list<V> get(K key);
    bool remove(K key);
    bool remove(K key, V val);
    void clear();
    bool empty();
    list<V> operator[](K key);
    int count(K key);
    int getBucketSize() { return bucketSize; }
};

template <class K, class V>
HashTable<K,V>::HashTable(int tSize) {
  tableSize = tSize;
  table = new list<V>[tableSize];
  bucketSize = 0;
}

template <class K, class V>
HashTable<K,V>::~HashTable() {
  delete [] table;
  table = nullptr;
  bucketSize = 0;
}

//key type should support int, char, and string.
template <class K, class V>
int HashTable<K,V>::addrCal(int key) {
    return key % tableSize;
}

template <class K, class V>
int HashTable<K,V>::addrCal(char key) {
    return int(key) % tableSize;
}

template <class K, class V>
int HashTable<K,V>::addrCal(string key) {
    string binary = "";
    for(int i = 0; i<key.length();i++) {
      int charNum = key[i] - '0';
      binary += bitset<32>(charNum).to_string(); //to binary
    }

    unsigned long hashCode = bitset<32>(binary).to_ulong();
    return hashCode % tableSize;
}

// When I define the map type (i.e map<string, string>),
// this function only accepts <string, string> type,
// any other types would be rejected, and thus only call
// addrCal(string key).
template <class K, class V>
bool HashTable<K,V>::put(K key, V val) {
  int pos = addrCal(key);

  //new bucket used.
  if(table[pos].empty())
    bucketSize++;

  table[pos].push_back(val);
  return true;
}

template <class K, class V>
bool HashTable<K,V>::remove(K key){
  int pos = addrCal(key);
  if(table[pos].empty())
    return false;

  table[pos].clear();
  bucketSize--;
  return true;
}

template <class K, class V>
bool HashTable<K,V>::remove(K key, V val){
  int pos = addrCal(key);

  if(table[pos].empty())
    return false;

  table[pos].remove(val);
  if(table[pos].empty())
    bucketSize--;

  return true;
}

template <class K, class V>
list<V> HashTable<K,V>::get(K key) {
  int pos = addrCal(key);
  return table[pos];
}

template <class K, class V>
void HashTable<K,V>::clear() {
  ~HashTable();
}

template <class K, class V>
bool HashTable<K,V>::empty() {
  if(bucketSize == 0)
    return true;

  return false;
}

template <class K, class V>
int HashTable<K,V>::count(K key) {
  int pos = addrCal(key);
  return table[pos].size();
}

template <class K, class V>
list<V> HashTable<K,V>::operator[](K key) {
  return get(key);
}
