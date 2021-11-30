#pragma once

struct EndOfQueueException {};
struct QueueIsEmptyException {};

class Queue
{
private:
	int size;
	int *queue;
	int head, tail;
	bool empty;
public:
	Queue();
	Queue(int size);
	Queue(const Queue &copy);
	~Queue();
	void pushElem(int elem);
	int popElem();
	int seeHead();
	bool isEmpty();
	void makeEmpty();
	int getSize();
	friend class Iterator;
};

