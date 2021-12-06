#include "stdafx.h"
#include "HashTable.h"
#include "iostream"


Element::Element(int data, int key)
{
	this->data = data;
	this->key = key;
}

HashTable::HashTable()
{
	count = 0;
	size = 5;
	table = new Element*[5];
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}

HashTable::HashTable(int x)
{
	if (x <= 0) {
		throw WrongSizeException();
	}
	count = 0;
	size = x;
	table = new Element*[x];
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}

void HashTable::addElem(int elem, int key)
{
	if (count == 0) {
		table[0]= new Element(elem, key);
		count++;
	}
	else if ((size % count) == size) {
		return;
	}else {
		checkElem(key);
		table[count%size] = new Element(elem, key);
		count++;
	}
}

bool HashTable::checkElem(int key) {
	Element* temp = table[0];
	for (int i = 0; i < count; i++) {
		temp = table[i];
		if (key == temp->key) {
			throw CopyOfElementException();
		}
	}
}

void HashTable::removeElem(int key) {
	Element* temp = table[0];
	for (int i = 0; i < count; i++) {
		temp = table[i];
		if (key == temp->key) {
			for (int j = i; j < count; j++) {
				
				table[j] = table[j + 1];				
			}
			break;
		}
	}
	delete temp;
	table[count-1] = nullptr;
	count--;
}

int HashTable::findElem(int key){
	Element* temp;
	for (int i = 0; i < count; i++) {
		temp = table[i];
		if (key == temp->key) {
			return temp->data;
		}
	}
	throw NoElemException();
}


void HashTable::doEmpty()
{
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
	count = 0;
}

bool HashTable::isEmpty()
{
	if (count > 0) { return false; }
	return true;
}

void HashTable::printElem()
{	
	if (count == 0) {
		throw NoElemException();
	}

	Element* temp;
	for (int i = 0; i < count ; i++) {
		temp = table[i];
		std::cout <<"key: "<< temp->key << "   number: " << temp->data <<  std::endl;
	}
}


HashTable::~HashTable()
{
	doEmpty();
	count = 0;
	delete[] table;
}

Iterator::Iterator(HashTable* & hashTable)
{
	counter = 0;
	hashList = hashTable;
	now = hashList->table[0];
}

Iterator::~Iterator()
{
}

bool Iterator::hasNext()
{
	if (counter <= hashList->count) { return true; }
	return false;
}

void Iterator::start()
{
	if (hashList->count == 0) {
		throw IteratorWrongCountException();
	}
	now = hashList->table[0];
	counter++;
}

void Iterator::next()
{
	now = hashList->table[counter];
	counter++;
}

int Iterator::seeElem()
{
	return now->data;
}
