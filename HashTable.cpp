#include "HashTable.h"


template <typename K, typename V, typename F = KeyHash<K>>
HashTable<K, V, F>::HashTable()
{
	table = new HashNode<K, V> *[TABLE_SIZE]()
}

template <typename K, typename V, typename F = KeyHash<K>>
HashTable<K, V, F>::~HashTable()
{
	//cycles through each hash "bucket" deleting each Node
	for (int i = 0; i < TABLE_SIZE; ++i) {
		HashNode<K, V>* entry = table[i];
		while (entry != NULL) {
			HashNode<K, V>* prev = entry;
			entry = entry->getNext();
			delete prev;
		}
		table[i] = NULL;
	}
	//Delets the table
	delete[table];
}

template<typename K, typename V, typename F>
bool HashTable<K, V, F>::get(const K & key, V & value)
{
	//retrieves the hashValue
	unsigned long hashValue = hashFunc(key);
	HashNode<K, V>* entry = table[hashValue];

	//Cycles through all nodes with same hashkey
	while (entry != NULL) {
		if (entry->getKey() == key) {
			value = entry->getValue();
			return true;
		}
		entry = entry->getNext();
	}
	return false;
}

template<typename K, typename V, typename F>
void HashTable<K, V, F>::put(const K & key, const V & value)
{
	//retrives the hashValue(slot in the matrix)
	unsigned long hashValue = hashFunc(key);
	HashNode<K, V>* prev = NULL;
	HashNode<K, V>* entry = table[hashValue];

	//cycles through other nodes with same hashValue (if needed)
	while (entry != NULL && entry->getKey() != key) {
		prev = entry;
		entry = entry->getNext();
	}

	if (entry == NULL) {
		entry = new HashNode<K, V>(key, value);
		//if no other hashValues were found
		if (prev == NULL) {
			//insert into first slot
			table[hashValue] = entry; 
		}
		else {
			//insert at end of list
			prev->setNext(entry);
		}
	}
	else {
		//found the existing node, updating value
		entry->setValue(value);
	}
}

template<typename K, typename V, typename F>
void HashTable<K, V, F>::remove(const K & key)
{
	//retrieve the hash value(slot in the matrix)
	unsigned long hashValue = hashFunc(key);
	HashNode<K, V>* prev = NULL;
	HashNode<K, V>* entry = table[hashValue];

	//cycles through matched values to get correct key
	while (entry != NULL && entry->getKey() != key)
	{
		prev = entry;
		entry = entry->getNext();
	}

	//No such key found
	if (entry == NULL) {
		//key not found
		return;
	}
	//Two possible cases, 1st slot, and remaining slots.
	else {
		//Prev never cycled, found key on entry slot		
		if (prev == NULL) {
			//This will set the "next" value to either  void or the any chained object
			table[hashValue] = entry->getNext();
		}
		else {
			//Located the key mid-chain
			//Sets the "next" of prev to the following chained object (or NULL if end of list)
			prev->setNext(entry->getNext();)
		}
		//deletes the HashNode object
		delete entry;
	}
}
