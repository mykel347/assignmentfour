#pragma once

const int TABLE_SIZE = 100;
template <typename K, typename V>
class HashNode {
public:
	HashNode(const K &key, const V &value) : 
	key(key), value(value), next(NULL) {}
	
	K getKey() const { return key; }
	V getValue() const { return value; }
	void setValue(V value) { HashNode::value = value; }
	HashNode* getNext() const { return next; }
	void setNext(HashNode* next) { HashNode::next = next; }

private:
	K key;
	V value;
	HashNode* next;
};

template <typename K>
struct KeyHash {
	unsigned long operator()(const K& key) const
	{
		return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
	}
};

template <typename K, typename V, typename F = KeyHash<K>>
class HashTable
{
public:
	HashTable();
	~HashTable();

	bool get(const K& key, V& value);        
	void put(const K& key, const V& value);
	void remove(const K& key);

private:
	HashNode<K, V>** table;
	F hashFunc;
};


