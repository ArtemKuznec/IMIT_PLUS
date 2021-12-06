#pragma once

struct NoElemException{};
struct WrongSizeException{};
struct CopyOfElementException{};
struct IteratorWrongCountException{};

struct Element
{
	int data;
	int key;
	Element(int data, int key);
};


class HashTable {
private:
	Element** table;
	int size;
	int count;
public:
	friend class Iterator;
	HashTable();
	HashTable(int n);
	bool checkElem(int key);
	int findElem(int key);
	void addElem(int elem, int key);
	void removeElem(int key);
	void doEmpty();
	void printElem();
	bool isEmpty();
	~HashTable();
};

class Iterator {
private:
	Element* now;
	HashTable* hashList;
	int counter;
public:
	Iterator(HashTable* &hashTable);
	~Iterator();
	bool hasNext();
	void start();
	void next();
	int seeElem();
};