#include "stdafx.h"
#include "Queue.h"


Queue::Queue() {
	this->queue = new int[10];
	this->head = 0;
	this->tail = 0;
	this->size = 10;
	empty = true;
}

Queue::Queue(int size) {
	this->queue = new int[size];
	this->head = 0;
	this->tail = 0;
	this->size = size;
	empty = true;
}

Queue::Queue(const Queue& copy) {
	this->head = copy.head;
	this->tail = copy.tail;
	this->size = copy.size;
	this->queue = new int[copy.size];
	for (int i = 0; i < copy.size; i++) {
		this->queue[i] = copy.queue[i];
	}
	this->empty = copy.empty;
}

Queue::~Queue() {
	delete[] queue;
}

void Queue::pushElem(int elem) {
	if (((tail + 1) % size) == head) {
		throw EndOfQueueException();
	}
	if (this->empty) {
		empty = false;
		this->queue[tail] = elem;
	}
	else {
		tail = (tail + 1) % size;
		this->queue[tail] = elem;
	}
}

int Queue::popElem() {
	int x;
	if (this->empty) {
		throw QueueIsEmptyException();
	}
	if (this->tail == this->head) {
		this->empty = true;
		x = this->queue[head];
	}
	else {
		x = this->queue[head];
		this->head = (this->head + 1) % this->size;
	}
	return x;
}

int Queue::seeHead() {
	if (this->empty) {
		throw QueueIsEmptyException();
	}
	return this->queue[head];
}

bool Queue::isEmpty() {
	return empty;
}

void Queue::makeEmpty() {
	this->empty = true;
	this->head = 0;
	this->tail = 0;
}

int Queue::getSize() {
	return this->size;
}
