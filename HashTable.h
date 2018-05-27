#pragma once
//#include <cstddef>
#include <string>

// typename V = objectPtr address searching/storing on the hashtable
// typename K = This is the string we're sending to become hashed
template <typename K, typename V>
class HashNode
{
public:
	HashNode(const K &key, const V &value) :
		key(key), value(value), next(NULL) {}

	K getKey() const { return key; }
	V getValue() const { return value; }
	void setValue(V value) { HashNode::value = value; }
	HashNode* getNext() const { return next; }
	void setNext(HashNode* next) { HashNode::next = next; }

private:
	K key = NULL;
	V value = NULL;
	HashNode* next = NULL;
};

template <typename K, typename V>
class HashTable
{
public:
	HashTable(int size);
	~HashTable();

	bool get(const K& stringKey, V& objectPtr);        
	void put(const K& stringKey, const V& objectPtr);
	void remove(const K& stringKey);
	unsigned long hash(const K& stringkey);

private:
	//Hashtable
	
	int tableSize;
	HashNode<K, V>** table;
};


#include "HashTable.cpp"

