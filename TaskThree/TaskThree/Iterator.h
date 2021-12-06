#pragma once

#include "stdafx.h"
#include "iostream"


struct EndOfIterator {};
typedef int elem_t;
struct Node
{
	elem_t data;
	Node *next;
	Node *prev;
	
	Node(elem_t data, Node* next = nullptr, Node* prev = nullptr) {
		this->data = data;
		this->next = next;
		this->prev = prev;
	}
};

class Iterator {
public:
	virtual void start() = 0;
	virtual elem_t getElement() const = 0;
	virtual void next() = 0;
	virtual void prev() = 0;
	virtual bool finish() const = 0;
	virtual Node* getNow() const = 0;
};