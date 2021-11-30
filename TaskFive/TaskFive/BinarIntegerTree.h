#pragma once
#include "iostream"
#include "vector"
#include "climits"

struct Node {
	int info;
	Node *left, *right;
	Node(int info, Node *left = nullptr, Node *right = nullptr);
};

struct BadPathException {};
struct NoElemException {};

class BinarIntegerTree
{
private:
	Node *root;
	int size;
	void copyTree(Node* root, Node* copy);
	void deleteTree(Node* root);
	void printTree(std::ostream& os, Node* root, int counter);
	int getEvenCount(Node* root);
	bool checkPositive(Node* root);
	bool deleteAllLeafs(Node* root);
	double getSum(Node* root);
	bool findElem(Node* root, int x, std::vector<int> &patn);
	bool checkBinaryFindTree(Node* root, int min, int max);
	void findMin(Node *root, int &min);
	void findMax(Node *root, int &max);
public:
	BinarIntegerTree();
	BinarIntegerTree(int x);
	BinarIntegerTree(const BinarIntegerTree& copy);
	BinarIntegerTree(BinarIntegerTree && move);
	~BinarIntegerTree();
	BinarIntegerTree& operator=(const BinarIntegerTree& copy);
	BinarIntegerTree& operator=(BinarIntegerTree&& copy);
	void addElem(int x, std::vector<int> path);
	friend std::ostream& operator<<(std::ostream& os, BinarIntegerTree& obj);
	int getEvenCount();
	bool checkPositive();
	void deleteAllLeafs();
	double getMiddle();
	bool checkBinaryFindTree();
	std::vector<int> findElem(int x);
};

