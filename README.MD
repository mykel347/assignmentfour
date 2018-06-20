Assignment 4- Inventory Tracking System

Program Overview
Our inventory tracking system for a local movie rental store utilizes various data structures to facilitate transactions. First data files are read into the program for processing. It is assumed this data is previously acquired and provided to the program. The program then uses string concatenation and string manipulations to determine the right commands to process. These commands are then stored in linked lists to be processed and each transaction is processed onto a hash table. At the end of the program, each transaction in the linked list processed is displayed. 

Class Descriptions
Movie Class
The Movie Class is a parent class that contains the bare minimum that is required to process a movie information. 
bool setStock(int s); ||This function adds a movie to the movie stock

int getStock() const; ||This function returns the int stock private attribute 

void setDirector(std::string dir); || Takes a director parameter and sets a director 

std::string getDirector() const; || Returns private director attribute

void setTitle(std::string t); || Sets the title attribute

std::string getTitle() const; || Returns the title attribute

void setYearReleased(int year); || Sets the year release attribute with the parameter

int getYearReleased() const; || Returns the year released

virtual bool lessThan(Movie* Rhs) const; || Comparison function to sort movie

virtual void print(); || Prints the transactions that takes place in the class
Private Members 
int stock; || Private attribute to store a movie transaction
std::string director; || Director attribute
std::string title; || Movie title attribute
int yearReleased; || Movie release year attribute




Child Classes 
The movie class has three child classes. The Drama Class, Classic Class and Comedy Class.
The Drama and Comedy class do not utilize a method peculiar to them respectively. However, the classic movie has 
std::string majorActorFirst;
std::string majorActorLast;
std::string movieType = "Classic";
std::string key;
int monthReleased = 0;
private methods that allows it to process correctly the difference input it gets for the classic movie type.
These attributes also have setters and getters to appropriately place information into the class.

The customer class
The customer class contains attributes for a customer such as customer first and last name and also a key or ID that distinguishes customers. For example, customer John Doe and customer John Doe may have equal names but different keys. Finally it also has a linked list of a transaction history class to keep track of customer activities. Here is a the basic over view of the class 
class Customer
{
public:

	//Constructors
	Customer();
	Customer(int newID, std::string first, std::string last);

	//Destructors
	~Customer();

	//Setters for the customer class
	void setFirstName(std::string first);
	void setKey(std::string k) { key = k; }
	void setLastName(std::string last);
	void setID(int newID);

	//Getters for the customer class
	std::string getLastName() const;
	std::string getFirstName() const;
	int getID() const;
	std::string getKey() { return key; }





	//Helper methods for the customer class
	void print();
	bool addToHistory(std::string type, std::string);
	void printHistory();
	bool lessThan(Customer* c);

private:
	//Private viarables for the customer class
	int ID;
	std::string firstName;
	std::string lastName;
	std::string key;
	LinkedList<TransactionHistory> historyLinkedList;
};


Transaction History Class
For us to distinguish command inputs by customer, a transaction history class is utilized. The transaction is a very brief class that only serves the purpose of tracking customer histories
//This class is to be used within each customer object to maintain
//their individual transation histories.
class TransactionHistory
{
public:
	TransactionHistory(std::string type, std::string key);
	~TransactionHistory();

	//This list will not sort itself. The list generates linearly
	bool lessThan(TransactionHistory* z) { return false; }
	void print();

	//Possible reasons for a get/set is for user to edit history
	//No need to this function within the scope of the assignement

private:
	std::string date;   // timestamp
	std::string transType;
	std::string movieKey; //May change the way to keep movie data, using the ptr to call the print method within movie
};






Linked List Class
The basic of all data structures linked list is used to store and process commands. When the command file is loaded, it is put in a linked list and each node is processed. The class utilizes a Node structure. The class is templated to process commands of all types even though the assignment limits us to processing strings
template <typename T>
class LinkedList
{
private:
	struct Node {
		T* data;
		Node* next = nullptr;
	};
	Node* root = nullptr;

public:
	LinkedList();
	~LinkedList();

	//Add is dependant on the objects having a lessThan method for sorting
	bool add(T* objectSent);
	void printFromNode() const;
	bool isEmpty() const;
	void clear();

	//Defined the function here since the Node struct is unknown to the CPP file until compile
	Node* clearHelper(Node* r){
		if (r == nullptr)
			return nullptr;

		if (r->next != nullptr)
			clearHelper(r->next);
		delete r;
		return nullptr;
	}

	//No remove implemented. 
};







Hash Table
A hash table allows an O(1) retrieval of information and this advantage is used in storing customer and movie transactions. The Hash table utilizes the chaining method which chains values of equal keys rather than rejecting them. A hashNode is used for the chaining while a hash function is used to create the hashes.
The class looks like this 
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
	bool put(const K& stringKey, const V& objectPtr);
	void remove(const K& stringKey);
	int hash(const K& key);

private:
	//Hashtable
	
	int tableSize;
	HashNode<K, V>** table;
};




The hash funciton used is 
template<typename K, typename V>
int HashTable<K, V>::hash(const K& key)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++) {
		hash = hash + (int)key[i];
	}
	hash = hash % tableSize;
	return hash;
}

The hash table uses a template for multi data type processing.

