#include "stdafx.h"
#include "Iterator.h"


Iterator::Iterator(Queue queue)
{
	this->queue = new Queue(queue);
	this->index = queue.head;
}

Iterator::~Iterator() {
}

void Iterator::start() {
	index = queue->head;
}

void Iterator::next() {
	if (this->finish()) {
		throw EndOfIteratorException();
	}
	index = (index + 1) % queue->size;
}

bool Iterator::finish() {
	return (index == (queue->tail%queue->size));
}

int Iterator::getValue() {
	return queue->queue[index];
}